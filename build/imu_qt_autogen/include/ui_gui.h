/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSearch_Port;
    QAction *actionStart;
    QAction *actionQuit;
    QWidget *centralwidget;
    QOpenGLWidget *openGLWidget;
    QPlainTextEdit *Acc_X;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPlainTextEdit *Acc_Z;
    QPlainTextEdit *Acc_Y;
    QPlainTextEdit *Omega_Z;
    QPlainTextEdit *Omega_X;
    QPlainTextEdit *Omega_Y;
    QPlainTextEdit *Angle_Z;
    QPlainTextEdit *Angle_X;
    QPlainTextEdit *Angle_Y;
    QPlainTextEdit *Mag_Z;
    QPlainTextEdit *Mag_X;
    QPlainTextEdit *Mag_Y;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPlainTextEdit *statusText;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *SearchPortButton;
    QPushButton *StartButton;
    QPushButton *QuitButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionSearch_Port = new QAction(MainWindow);
        actionSearch_Port->setObjectName(QString::fromUtf8("actionSearch_Port"));
        actionStart = new QAction(MainWindow);
        actionStart->setObjectName(QString::fromUtf8("actionStart"));
        actionStart->setEnabled(false);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        openGLWidget = new QOpenGLWidget(centralwidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setGeometry(QRect(20, 60, 461, 231));
        Acc_X = new QPlainTextEdit(centralwidget);
        Acc_X->setObjectName(QString::fromUtf8("Acc_X"));
        Acc_X->setGeometry(QRect(180, 330, 71, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 340, 111, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 390, 101, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 440, 81, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 485, 101, 21));
        Acc_Z = new QPlainTextEdit(centralwidget);
        Acc_Z->setObjectName(QString::fromUtf8("Acc_Z"));
        Acc_Z->setGeometry(QRect(400, 330, 71, 31));
        Acc_Y = new QPlainTextEdit(centralwidget);
        Acc_Y->setObjectName(QString::fromUtf8("Acc_Y"));
        Acc_Y->setGeometry(QRect(290, 330, 71, 31));
        Omega_Z = new QPlainTextEdit(centralwidget);
        Omega_Z->setObjectName(QString::fromUtf8("Omega_Z"));
        Omega_Z->setGeometry(QRect(400, 380, 71, 31));
        Omega_X = new QPlainTextEdit(centralwidget);
        Omega_X->setObjectName(QString::fromUtf8("Omega_X"));
        Omega_X->setGeometry(QRect(180, 380, 71, 31));
        Omega_Y = new QPlainTextEdit(centralwidget);
        Omega_Y->setObjectName(QString::fromUtf8("Omega_Y"));
        Omega_Y->setGeometry(QRect(290, 380, 71, 31));
        Angle_Z = new QPlainTextEdit(centralwidget);
        Angle_Z->setObjectName(QString::fromUtf8("Angle_Z"));
        Angle_Z->setGeometry(QRect(400, 430, 71, 31));
        Angle_X = new QPlainTextEdit(centralwidget);
        Angle_X->setObjectName(QString::fromUtf8("Angle_X"));
        Angle_X->setGeometry(QRect(180, 430, 71, 31));
        Angle_Y = new QPlainTextEdit(centralwidget);
        Angle_Y->setObjectName(QString::fromUtf8("Angle_Y"));
        Angle_Y->setGeometry(QRect(290, 430, 71, 31));
        Mag_Z = new QPlainTextEdit(centralwidget);
        Mag_Z->setObjectName(QString::fromUtf8("Mag_Z"));
        Mag_Z->setGeometry(QRect(400, 480, 71, 31));
        Mag_X = new QPlainTextEdit(centralwidget);
        Mag_X->setObjectName(QString::fromUtf8("Mag_X"));
        Mag_X->setGeometry(QRect(180, 480, 71, 31));
        Mag_Y = new QPlainTextEdit(centralwidget);
        Mag_Y->setObjectName(QString::fromUtf8("Mag_Y"));
        Mag_Y->setGeometry(QRect(290, 480, 71, 31));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(210, 300, 49, 16));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(320, 300, 49, 16));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(430, 300, 49, 16));
        statusText = new QPlainTextEdit(centralwidget);
        statusText->setObjectName(QString::fromUtf8("statusText"));
        statusText->setGeometry(QRect(520, 330, 241, 171));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(620, 300, 61, 21));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(230, 30, 49, 16));
        SearchPortButton = new QPushButton(centralwidget);
        SearchPortButton->setObjectName(QString::fromUtf8("SearchPortButton"));
        SearchPortButton->setGeometry(QRect(590, 60, 121, 51));
        SearchPortButton->setAutoDefault(false);
        StartButton = new QPushButton(centralwidget);
        StartButton->setObjectName(QString::fromUtf8("StartButton"));
        StartButton->setGeometry(QRect(590, 140, 121, 51));
        QuitButton = new QPushButton(centralwidget);
        QuitButton->setObjectName(QString::fromUtf8("QuitButton"));
        QuitButton->setGeometry(QRect(590, 220, 121, 51));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "IMU QT", nullptr));
        actionSearch_Port->setText(QApplication::translate("MainWindow", "Search Port", nullptr));
        actionStart->setText(QApplication::translate("MainWindow", "Start", nullptr));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", nullptr));
        label->setText(QApplication::translate("MainWindow", "Acceleration", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Angular Velocity", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Angle", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Magnetic FIeld", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "X", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Y", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Z", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Status", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "IMU", nullptr));
        SearchPortButton->setText(QApplication::translate("MainWindow", "Search Port", nullptr));
        StartButton->setText(QApplication::translate("MainWindow", "Start", nullptr));
        QuitButton->setText(QApplication::translate("MainWindow", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
