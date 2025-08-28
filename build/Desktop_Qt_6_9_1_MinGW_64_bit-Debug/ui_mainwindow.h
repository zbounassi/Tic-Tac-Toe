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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *mainMenu;
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
    QCheckBox *fullscreenBox;
    QTextBrowser *fullscreenText;
    QPushButton *resolutionSettings;
    QPushButton *res800;
    QPushButton *res1280;
    QPushButton *res1920;
    QPushButton *pushButton;
    QPushButton *darkMode;
    QPushButton *lightMode;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1920, 1080);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        MainWindow->setAutoFillBackground(false);
        mainMenu = new QWidget(MainWindow);
        mainMenu->setObjectName("mainMenu");
        vsCPUButton = new QPushButton(mainMenu);
        vsCPUButton->setObjectName("vsCPUButton");
        vsCPUButton->setGeometry(QRect(830, 540, 91, 31));
        playEasyCPUButton = new QPushButton(mainMenu);
        playEasyCPUButton->setObjectName("playEasyCPUButton");
        playEasyCPUButton->setGeometry(QRect(940, 470, 91, 31));
        twoPlayerButton = new QPushButton(mainMenu);
        twoPlayerButton->setObjectName("twoPlayerButton");
        twoPlayerButton->setGeometry(QRect(830, 470, 91, 31));
        backButtonMenu = new QPushButton(mainMenu);
        backButtonMenu->setObjectName("backButtonMenu");
        backButtonMenu->setGeometry(QRect(830, 610, 91, 31));
        playMediumCPUButton = new QPushButton(mainMenu);
        playMediumCPUButton->setObjectName("playMediumCPUButton");
        playMediumCPUButton->setGeometry(QRect(940, 540, 91, 31));
        titleText = new QLabel(mainMenu);
        titleText->setObjectName("titleText");
        titleText->setGeometry(QRect(700, 270, 361, 201));
        QFont font;
        font.setFamilies({QString::fromUtf8("Verdana")});
        font.setPointSize(50);
        titleText->setFont(font);
        titleText->setLineWidth(0);
        playButton = new QPushButton(mainMenu);
        playButton->setObjectName("playButton");
        playButton->setGeometry(QRect(830, 470, 91, 31));
        backButtonCPUselect = new QPushButton(mainMenu);
        backButtonCPUselect->setObjectName("backButtonCPUselect");
        backButtonCPUselect->setGeometry(QRect(830, 610, 91, 31));
        settingsButton = new QPushButton(mainMenu);
        settingsButton->setObjectName("settingsButton");
        settingsButton->setGeometry(QRect(830, 540, 91, 31));
        exitButton = new QPushButton(mainMenu);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(830, 610, 91, 31));
        playHardCPUButton = new QPushButton(mainMenu);
        playHardCPUButton->setObjectName("playHardCPUButton");
        playHardCPUButton->setGeometry(QRect(940, 610, 91, 31));
        fullscreenBox = new QCheckBox(mainMenu);
        fullscreenBox->setObjectName("fullscreenBox");
        fullscreenBox->setGeometry(QRect(250, 140, 76, 21));
        fullscreenText = new QTextBrowser(mainMenu);
        fullscreenText->setObjectName("fullscreenText");
        fullscreenText->setGeometry(QRect(290, 120, 301, 51));
        resolutionSettings = new QPushButton(mainMenu);
        resolutionSettings->setObjectName("resolutionSettings");
        resolutionSettings->setGeometry(QRect(209, 190, 121, 24));
        res800 = new QPushButton(mainMenu);
        res800->setObjectName("res800");
        res800->setGeometry(QRect(370, 190, 80, 24));
        res1280 = new QPushButton(mainMenu);
        res1280->setObjectName("res1280");
        res1280->setGeometry(QRect(370, 230, 80, 24));
        res1920 = new QPushButton(mainMenu);
        res1920->setObjectName("res1920");
        res1920->setGeometry(QRect(370, 270, 80, 24));
        pushButton = new QPushButton(mainMenu);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(210, 240, 121, 24));
        darkMode = new QPushButton(mainMenu);
        darkMode->setObjectName("darkMode");
        darkMode->setGeometry(QRect(370, 320, 101, 24));
        lightMode = new QPushButton(mainMenu);
        lightMode->setObjectName("lightMode");
        lightMode->setGeometry(QRect(370, 360, 101, 24));
        MainWindow->setCentralWidget(mainMenu);

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
        fullscreenBox->setText(QString());
        fullscreenText->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">Fullscreen</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Toggle the display being fullscreen or windowed here</span></p></body></html>", nullptr));
        resolutionSettings->setText(QCoreApplication::translate("MainWindow", "Change Resolution", nullptr));
        res800->setText(QCoreApplication::translate("MainWindow", "800x600", nullptr));
        res1280->setText(QCoreApplication::translate("MainWindow", "1280x720", nullptr));
        res1920->setText(QCoreApplication::translate("MainWindow", "1920x1080", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Change Theme", nullptr));
        darkMode->setText(QCoreApplication::translate("MainWindow", "Dark Mode", nullptr));
        lightMode->setText(QCoreApplication::translate("MainWindow", "Light Mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
