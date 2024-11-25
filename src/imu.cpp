#include <imu.h>
#include <QSerialPortInfo>
#include <QDebug>
#include <QThread>

Imu::Imu(QObject* parent):QSerialPort(parent),m_acc{},m_angle{},m_vel{},m_mag{}
{
    //connect readyRead to decode slot
    connect(this,&QSerialPort::readyRead,this,&Imu::parseData);
}

void Imu::autoPortScanner(bool checked)
{
    const auto serialPortInfos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &portInfo : serialPortInfos) {
        qDebug() << "\n"
                 << "Port:" << portInfo.portName() << "\n"
                 << "Location:" << portInfo.systemLocation() << "\n"
                 << "Description:" << portInfo.description() << "\n"
                 << "Manufacturer:" << portInfo.manufacturer() << "\n"
                 << "Serial number:" << portInfo.serialNumber() << "\n"
                 << "Vendor Identifier:"
                 << (portInfo.hasVendorIdentifier()
                     ? QByteArray::number(portInfo.vendorIdentifier(), 16)
                     : QByteArray()) << "\n"
                 << "Product Identifier:"
                 << (portInfo.hasProductIdentifier()
                     ? QByteArray::number(portInfo.productIdentifier(), 16)
                     : QByteArray());
        if (portInfo.manufacturer() == "Silicon Labs")
        {
            this->setPort(portInfo);
            emit portDetected(true);
            emit statusUpdate("Sensor Detected: " + portInfo.portName() + "\n");
            return ;
        }
    }
    emit statusUpdate("No Port Available\n");
}

void Imu::start()
{
    this->setBaudRate(115200);
    if(this->open(QIODevice::ReadWrite))
    {
        emit statusUpdate("Sensor Connected\n");
        while(Imu::waitForReadyRead()){}
        this->parseData();
        emit statusUpdate("No Sensor Detected\n");
        this->close();
    }

}

void Imu::parseData()
{

    QByteArray data{this->read(1)};
    if(data[0] == '\x55')
    {
        data.append(this->read(1));
        switch(data[1])
        {
            case '\x51':
                data.append(this->read(9));
                if(parseAcc(m_acc,data)) emit dataParsed(WITMOTION::ACC,m_acc);
                break;

            case '\x52':
                data.append(this->read(9));
                if(parseAngVel(m_vel,data)) emit dataParsed(WITMOTION::ANG_VEL,m_vel);
                break;

            case '\x53':
                data.append(this->read(9));
                if(parseAngle(m_angle,data)) emit dataParsed(WITMOTION::ANGLE,m_angle);
                break;

            case '\x54':
                data.append(this->read(9));
                if(parseMag(m_mag,data)) emit dataParsed(WITMOTION::MAG,m_mag);
                break;

            default:
                return;
        }
    }
}

bool Imu::checkSum(QByteArray byte)
{
    uint8_t sum{0};
    for(int i=0;i<10;i++)
    {
        sum += byte[i];
    
    }
    qDebug() << byte.size();
    return sum==byte[10];
}

void Imu::parseByte(float* imu_data, QByteArray data)
{
    imu_data[0] = (uint16_t)data[3] << 8|(uint16_t)data[2];
    imu_data[1] = (uint16_t)data[5] << 8|(uint16_t)data[4];
    imu_data[2] = (uint16_t)data[7] << 8|(uint16_t)data[6];
}

bool Imu::parseAcc(float* imu_data,QByteArray data)
{
    if(this->checkSum(data))
    {
        this->parseByte(imu_data,data);
        for(int i=0;i<3;i++) imu_data[i] = imu_data[i]/32768.0f * 16.0f * G;
        return true;
    }
    return false;
}

bool Imu::parseAngVel(float* imu_data,QByteArray data)
{
    if(this->checkSum(data))
    {
        this->parseByte(imu_data,data);
        for(int i =0;i<3;i++) imu_data[i] = imu_data[i]/32768.0f * 2000.0f;
        return true;
    }
    return false;
}

bool Imu::parseAngle(float* imu_data, QByteArray data)
{
    if(this->checkSum(data))
    {
        this->parseByte(imu_data,data);
        for(int i=0;i<3;i++) imu_data[i] = imu_data[i]/32768.0f*180.0f;
        return true;
    }
    return false;
}

bool Imu::parseMag(float* imu_data, QByteArray data)
{
    if(this->checkSum(data))
    {
        this->parseByte(imu_data,data);
        return true;
    }
    return false;
}