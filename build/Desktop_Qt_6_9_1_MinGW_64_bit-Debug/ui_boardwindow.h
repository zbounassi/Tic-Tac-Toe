/********************************************************************************
** Form generated from reading UI file 'boardwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOARDWINDOW_H
#define UI_BOARDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_boardwindow
{
public:
    QPushButton *area1;
    QPushButton *area2;
    QPushButton *area3;
    QPushButton *area4;
    QPushButton *area5;
    QPushButton *area6;
    QPushButton *area7;
    QPushButton *area8;
    QPushButton *area9;
    QFrame *line1;
    QFrame *line2;
    QFrame *line3;
    QFrame *line4;
    QTextBrowser *playerPrompt;
    QPushButton *gameExitButton;
    QPushButton *gameExitConfirm;
    QPushButton *gameExitDeny;
    QTextBrowser *exitPrompt;
    QTextBrowser *exitPromptMenu;
    QPushButton *menuExit;
    QPushButton *closeProgram;
    QPushButton *goFirst;
    QPushButton *goSecond;

    void setupUi(QWidget *boardwindow)
    {
        if (boardwindow->objectName().isEmpty())
            boardwindow->setObjectName("boardwindow");
        boardwindow->resize(1099, 654);
        area1 = new QPushButton(boardwindow);
        area1->setObjectName("area1");
        area1->setGeometry(QRect(370, 210, 61, 41));
        area2 = new QPushButton(boardwindow);
        area2->setObjectName("area2");
        area2->setGeometry(QRect(490, 210, 61, 41));
        area3 = new QPushButton(boardwindow);
        area3->setObjectName("area3");
        area3->setGeometry(QRect(600, 210, 61, 41));
        area4 = new QPushButton(boardwindow);
        area4->setObjectName("area4");
        area4->setGeometry(QRect(370, 300, 61, 41));
        area5 = new QPushButton(boardwindow);
        area5->setObjectName("area5");
        area5->setGeometry(QRect(490, 300, 61, 41));
        area6 = new QPushButton(boardwindow);
        area6->setObjectName("area6");
        area6->setGeometry(QRect(600, 300, 61, 41));
        area7 = new QPushButton(boardwindow);
        area7->setObjectName("area7");
        area7->setGeometry(QRect(370, 390, 61, 41));
        area8 = new QPushButton(boardwindow);
        area8->setObjectName("area8");
        area8->setGeometry(QRect(490, 390, 61, 41));
        area9 = new QPushButton(boardwindow);
        area9->setObjectName("area9");
        area9->setGeometry(QRect(600, 390, 61, 41));
        line1 = new QFrame(boardwindow);
        line1->setObjectName("line1");
        line1->setGeometry(QRect(450, 170, 20, 301));
        line1->setFrameShape(QFrame::Shape::VLine);
        line1->setFrameShadow(QFrame::Shadow::Sunken);
        line2 = new QFrame(boardwindow);
        line2->setObjectName("line2");
        line2->setGeometry(QRect(570, 170, 20, 301));
        line2->setFrameShape(QFrame::Shape::VLine);
        line2->setFrameShadow(QFrame::Shadow::Sunken);
        line3 = new QFrame(boardwindow);
        line3->setObjectName("line3");
        line3->setGeometry(QRect(347, 270, 351, 20));
        line3->setFrameShape(QFrame::Shape::HLine);
        line3->setFrameShadow(QFrame::Shadow::Sunken);
        line4 = new QFrame(boardwindow);
        line4->setObjectName("line4");
        line4->setGeometry(QRect(350, 370, 341, 16));
        line4->setFrameShape(QFrame::Shape::HLine);
        line4->setFrameShadow(QFrame::Shadow::Sunken);
        playerPrompt = new QTextBrowser(boardwindow);
        playerPrompt->setObjectName("playerPrompt");
        playerPrompt->setGeometry(QRect(370, 40, 301, 61));
        gameExitButton = new QPushButton(boardwindow);
        gameExitButton->setObjectName("gameExitButton");
        gameExitButton->setGeometry(QRect(930, 50, 80, 24));
        gameExitConfirm = new QPushButton(boardwindow);
        gameExitConfirm->setObjectName("gameExitConfirm");
        gameExitConfirm->setGeometry(QRect(840, 180, 80, 24));
        gameExitDeny = new QPushButton(boardwindow);
        gameExitDeny->setObjectName("gameExitDeny");
        gameExitDeny->setGeometry(QRect(990, 180, 80, 24));
        exitPrompt = new QTextBrowser(boardwindow);
        exitPrompt->setObjectName("exitPrompt");
        exitPrompt->setGeometry(QRect(750, 80, 341, 61));
        exitPromptMenu = new QTextBrowser(boardwindow);
        exitPromptMenu->setObjectName("exitPromptMenu");
        exitPromptMenu->setGeometry(QRect(750, 80, 341, 61));
        menuExit = new QPushButton(boardwindow);
        menuExit->setObjectName("menuExit");
        menuExit->setGeometry(QRect(840, 180, 80, 24));
        closeProgram = new QPushButton(boardwindow);
        closeProgram->setObjectName("closeProgram");
        closeProgram->setGeometry(QRect(990, 180, 80, 24));
        goFirst = new QPushButton(boardwindow);
        goFirst->setObjectName("goFirst");
        goFirst->setGeometry(QRect(380, 120, 80, 24));
        goSecond = new QPushButton(boardwindow);
        goSecond->setObjectName("goSecond");
        goSecond->setGeometry(QRect(560, 120, 80, 24));

        retranslateUi(boardwindow);

        QMetaObject::connectSlotsByName(boardwindow);
    } // setupUi

    void retranslateUi(QWidget *boardwindow)
    {
        boardwindow->setWindowTitle(QCoreApplication::translate("boardwindow", "Form", nullptr));
        area1->setText(QString());
        area2->setText(QString());
        area3->setText(QString());
        area4->setText(QString());
        area5->setText(QString());
        area6->setText(QString());
        area7->setText(QString());
        area8->setText(QString());
        area9->setText(QString());
        playerPrompt->setHtml(QCoreApplication::translate("boardwindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Would you like to go first or second?</p></body></html>", nullptr));
        gameExitButton->setText(QCoreApplication::translate("boardwindow", "Exit to Menu", nullptr));
        gameExitConfirm->setText(QCoreApplication::translate("boardwindow", "Yes", nullptr));
        gameExitDeny->setText(QCoreApplication::translate("boardwindow", "No", nullptr));
        exitPrompt->setHtml(QCoreApplication::translate("boardwindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">Are you sure that you want to leave the game?</span></p></body></html>", nullptr));
        exitPromptMenu->setHtml(QCoreApplication::translate("boardwindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">Would you like to exit to the menu or close the program?</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt;\"><br /></p></body></html>", nullptr));
        menuExit->setText(QCoreApplication::translate("boardwindow", "Exit to Menu", nullptr));
        closeProgram->setText(QCoreApplication::translate("boardwindow", "Close Program", nullptr));
        goFirst->setText(QCoreApplication::translate("boardwindow", "First", nullptr));
        goSecond->setText(QCoreApplication::translate("boardwindow", "Second", nullptr));
    } // retranslateUi

};

namespace Ui {
    class boardwindow: public Ui_boardwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOARDWINDOW_H
