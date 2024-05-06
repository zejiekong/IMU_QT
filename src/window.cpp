#include <window.h>
#include <QMenuBar>
#include <QMenu>
#include <QApplication>
#include <QDebug>

Window::Window(QWidget *parent): QMainWindow(parent)
{
    setupUi(this);
    StartButton->setDisabled(true);
    connect(QuitButton,&QPushButton::clicked,QApplication::instance(),&QApplication::quit);

    //instantiate imu
    m_imu.reset(new Imu());
    m_imu.data()->moveToThread(&workerThread);
    connect(SearchPortButton,&QPushButton::clicked,m_imu.data(),&Imu::autoPortScanner);
    connect(m_imu.data(),&Imu::portDetected,StartButton,&QPushButton::setEnabled);
    connect(m_imu.data(),&Imu::dataParsed,this,&Window::updateData);
    connect(StartButton,&QPushButton::clicked,m_imu.data(),&Imu::start);
    connect(m_imu.data(),&Imu::statusUpdate,statusText,&QPlainTextEdit::insertPlainText);

    workerThread.start();
}

//update Imu data in GUI
void Window::updateData(int type, float* data)
{
    switch(type)
    {
        case WITMOTION::ACC:
            Acc_X->setPlainText(QString::number(data[0]));
            Acc_Y->setPlainText(QString::number(data[1]));
            Acc_Z->setPlainText(QString::number(data[2]));
            break;

        case WITMOTION::ANG_VEL:
            Omega_X->setPlainText(QString::number(data[0]));
            Omega_Y->setPlainText(QString::number(data[1]));
            Omega_Z->setPlainText(QString::number(data[2]));
            break;

        case WITMOTION::ANGLE:
            Angle_X->setPlainText(QString::number(data[0]));
            Angle_Y->setPlainText(QString::number(data[1]));
            Angle_Z->setPlainText(QString::number(data[2]));
            break;

        case WITMOTION::MAG:
            Mag_X->setPlainText(QString::number(data[0]));
            Mag_Y->setPlainText(QString::number(data[1]));
            Mag_Z->setPlainText(QString::number(data[2]));
            break;
    }
}

