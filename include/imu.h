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
        float* parseAcc(QByteArray data);
        float* parseAngVel(QByteArray data);
        float* parseAngle(QByteArray data);
        float* parseMag(QByteArray data);

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
        float* m_acc;
        float* m_vel;
        float* m_angle;
        float* m_mag;
};

#endif