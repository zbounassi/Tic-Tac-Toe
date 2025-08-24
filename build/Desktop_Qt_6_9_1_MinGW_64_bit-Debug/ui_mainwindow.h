/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *vsCPUButton;
    QPushButton *playEasyCPUButton;
    QPushButton *twoPlayerButton;
    QPushButton *backButtonMenu;
    QPushButton *playMediumCPUButton;
    QLabel *titleText;
    QPushButton *playButton;
    QPushButton *backButtonCPUselect;
    QPushButton *settingsButton;
    QPushButton *exitButton;
    QPushButton *playHardCPUButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1920, 1080);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        vsCPUButton = new QPushButton(centralwidget);
        vsCPUButton->setObjectName("vsCPUButton");
        vsCPUButton->setGeometry(QRect(830, 540, 91, 31));
        playEasyCPUButton = new QPushButton(centralwidget);
        playEasyCPUButton->setObjectName("playEasyCPUButton");
        playEasyCPUButton->setGeometry(QRect(940, 470, 91, 31));
        twoPlayerButton = new QPushButton(centralwidget);
        twoPlayerButton->setObjectName("twoPlayerButton");
        twoPlayerButton->setGeometry(QRect(830, 470, 91, 31));
        backButtonMenu = new QPushButton(centralwidget);
        backButtonMenu->setObjectName("backButtonMenu");
        backButtonMenu->setGeometry(QRect(830, 610, 91, 31));
        playMediumCPUButton = new QPushButton(centralwidget);
        playMediumCPUButton->setObjectName("playMediumCPUButton");
        playMediumCPUButton->setGeometry(QRect(940, 540, 91, 31));
        titleText = new QLabel(centralwidget);
        titleText->setObjectName("titleText");
        titleText->setGeometry(QRect(740, 250, 361, 201));
        QFont font;
        font.setPointSize(54);
        titleText->setFont(font);
        playButton = new QPushButton(centralwidget);
        playButton->setObjectName("playButton");
        playButton->setGeometry(QRect(830, 470, 91, 31));
        backButtonCPUselect = new QPushButton(centralwidget);
        backButtonCPUselect->setObjectName("backButtonCPUselect");
        backButtonCPUselect->setGeometry(QRect(830, 610, 91, 31));
        settingsButton = new QPushButton(centralwidget);
        settingsButton->setObjectName("settingsButton");
        settingsButton->setGeometry(QRect(830, 540, 91, 31));
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(830, 610, 91, 31));
        playHardCPUButton = new QPushButton(centralwidget);
        playHardCPUButton->setObjectName("playHardCPUButton");
        playHardCPUButton->setGeometry(QRect(940, 610, 91, 31));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        vsCPUButton->setText(QCoreApplication::translate("MainWindow", "vs CPU", nullptr));
        playEasyCPUButton->setText(QCoreApplication::translate("MainWindow", "Easy", nullptr));
        twoPlayerButton->setText(QCoreApplication::translate("MainWindow", "2 Player", nullptr));
        backButtonMenu->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        playMediumCPUButton->setText(QCoreApplication::translate("MainWindow", "Medium", nullptr));
        titleText->setText(QCoreApplication::translate("MainWindow", "Tic-Tac-Toe", nullptr));
        playButton->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        backButtonCPUselect->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        settingsButton->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        exitButton->setText(QCoreApplication::translate("MainWindow", "Close Program", nullptr));
        playHardCPUButton->setText(QCoreApplication::translate("MainWindow", "Hard", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
