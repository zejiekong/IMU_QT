#include <imu.h>
#include <QSerialPortInfo>
#include <QDebug>
#include <QThread>

Imu::Imu(QObject* parent):QSerialPort(parent)
{
    //connect readyRead to decode slot
    connect(this,&QIODevice::readyRead,this,&Imu::parseData);
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
        while(Imu::waitForReadyRead(2000)){}
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
                m_acc = parseAcc(data);
                if(m_acc) emit dataParsed(WITMOTION::ACC,m_acc);
                break;

            case '\x52':
                data.append(this->read(9));
                m_vel = parseAngVel(data);
                if(m_vel) emit dataParsed(WITMOTION::ANG_VEL,m_vel);
                break;

            case '\x53':
                data.append(this->read(9));
                m_angle = parseAngle(data);
                if(m_angle) emit dataParsed(WITMOTION::ANGLE,m_angle);
                break;

            case '\x54':
                data.append(this->read(9));
                m_mag = parseMag(data);
                if(m_mag) emit dataParsed(WITMOTION::MAG,m_mag);
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
    return (sum==byte[10])?true:false;
}

float* Imu::parseAcc(QByteArray data)
{
    if(this->checkSum(data))
    {
        float* acc = new float[3];
        acc[0] = (((uint16_t)data[3] << 8)|(uint16_t)data[2])/32768.0f*16.0f*G;
        acc[1] = (((uint16_t)data[5] << 8)|(uint16_t)data[4])/32768.0f*16.0f*G;
        acc[2] = (((uint16_t)data[7] << 8)|(uint16_t)data[6])/32768.0f*16.0f*G;
        return acc;
    }
    return nullptr;
}

float* Imu::parseAngVel(QByteArray data)
{
    if(this->checkSum(data))
    {
        float* ang_vel = new float[3];
        ang_vel[0] = (((uint16_t)data[3] << 8)|(uint16_t)data[2])/32768.0f*2000.0f;
        ang_vel[1] = (((uint16_t)data[5] << 8)|(uint16_t)data[4])/32768.0f*2000.0f;
        ang_vel[2] = (((uint16_t)data[7] << 8)|(uint16_t)data[6])/32768.0f*2000.0f;
        return ang_vel;
    }
    return nullptr; 
}

float* Imu::parseAngle(QByteArray data)
{
    if(this->checkSum(data))
    {
        float* angle = new float[3];
        angle[0] = (((uint16_t)data[3] << 8 )|(uint16_t)data[2])/32768.0f*180.0f;
        angle[1] = (((uint16_t)data[5] << 8 )|(uint16_t)data[4])/32768.0f*180.0f;
        angle[2] = (((uint16_t)data[7] << 8 )|(uint16_t)data[6])/32768.0f*180.0f;
        return angle;
    }
    return nullptr; 
}

float* Imu::parseMag(QByteArray data)
{
    if(this->checkSum(data))
    {
        float* mag = new float[3];
        mag[0] = (((uint16_t)data[3] << 8) |(uint16_t) data[2]);
        mag[1] = (((uint16_t)data[5] << 8) |(uint16_t) data[4]);
        mag[2] = (((uint16_t)data[7] << 8) |(uint16_t) data[6]);
        return mag;
    }
    return nullptr; 
}