/**
 * @file imu.h
 * @author ze-jie-kong-@hotmail.com
 * @brief 
 * @version 0.1
 * @date 2024-04-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef IMU_H
#define IMU_H
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QString>

#define G 9.8

enum WITMOTION{ACC,ANG_VEL,ANGLE,MAG};

class Imu : public QSerialPort
{
    Q_OBJECT
    public:
        explicit Imu(QObject *parent=nullptr);
        bool checkSum(QByteArray data);
        void parseByte(float* imu_data, QByteArray data);
        bool parseAcc(float* imu_data,QByteArray data);
        bool parseAngVel(float* imu_data,QByteArray data);
        bool parseAngle(float* imu_data,QByteArray data);
        bool parseMag(float* imu_data,QByteArray data);

    public slots:
        void autoPortScanner(bool checked=false); //signal to window
        void start();
        void parseData();
    signals:
        void portDetected(bool enable);
        void dataReceived();
        void dataParsed(int type, float* data);
        void statusUpdate(QString status);
    private:
        float m_acc[3],m_angle[3],m_vel[3],m_mag[3];
};

#endif