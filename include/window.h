/**
 * @file window.h
 * @author ze-jie-kong-@hotmail.com
 * @brief 
 * @version 0.1
 * @date 2024-04-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef WINDOWS_H
#define WINODWS_H

#include <QMainWindow>
#include <imu.h>
#include <QScopedPointer>
#include "ui_gui.h"
#include <QThread>

class Window : public QMainWindow , private Ui_MainWindow
{
    Q_OBJECT
    public:
        explicit Window(QWidget *parent=0);
    signals:
    public slots:
        void updateData(int type, float* data);
    private:
        QScopedPointer<Imu> m_imu;
        QThread workerThread;

};

#endif