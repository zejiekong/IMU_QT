//test imu class data received 

#include <QObject>
#include <imu.h>
#include <QtTest/QtTest>
#include <QByteArray>
#include <QList>

QByteArray acc_data = "\x55\x51\x27\x00\x8b\x00\x13\x08\xEE\x0C\x6D";
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
        float acc[3] = {0,0,0};
};

TestImu::TestImu()
{
    m_imu.reset(new Imu);
}

void TestImu::dataReceived()
{
    float acc_result[3] = {0.0861328,313.313,9.88613};
    float ang_vel_result[3] = {0,0,0};
    m_imu->parseAcc(acc,acc_data);
    qDebug() << acc[0] << acc[1] << acc[2];
    //for(int i=0;i<3;i++)QCOMPARE(acc[i],acc_result[i]);
    //QVERIFY(m_imu->checkSum(ang_vel_data));
    
}

QTEST_MAIN(TestImu);
#include "imu_test.moc"

