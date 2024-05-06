//test imu class data received 

#include <QObject>
#include <imu.h>
#include <QtTest/QtTest>
#include <QByteArray>
#include <QList>

QByteArray acc_data = "\x55\x51\x1F\x20\xEC\x20\x0B\x08\x27\x0C\xF7";
QByteArray ang_vel_data = "\x55\x52\x20\x20\x20\x20\x20\x20\x27\x0C\xDA";

class TestImu : public QObject
{
    Q_OBJECT
    public:
        TestImu();
    private slots:
        void dataReceived();
    private:
        QScopedPointer<Imu> m_imu;
};

TestImu::TestImu()
{
    m_imu.reset(new Imu);
}

void TestImu::dataReceived()
{
    float acc_result[3] = {0.01,0.116,1.01};
    float ang_vel_result[3] = {0,0,0};
    //QVERIFY(m_imu->checkSum(ang_vel_data));
    
}

QTEST_MAIN(TestImu);
#include "imu_test.moc"

/*
55 53 A9 04 20 1E FF 41 69 4E 38 08
55 54 32 01 40 FE 5B 01 27 0C A9 
0.01	0.116	1.01	0	0	0	6.553	-0.681	148.013	29.988	-43.904	34.006	31.08

*/