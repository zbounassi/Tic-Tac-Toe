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
#include <QtWidgets/QLabel>
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
    QPushButton *gameExitButton;
    QPushButton *gameExitConfirm;
    QPushButton *gameExitDeny;
    QTextBrowser *exitPrompt;
    QTextBrowser *exitPromptMenu;
    QPushButton *menuExit;
    QPushButton *closeProgram;
    QPushButton *goFirst;
    QPushButton *goSecond;
    QTextBrowser *playAgainPrompt;
    QPushButton *replayConfirm;
    QPushButton *replayDeny;
    QLabel *playerPrompt;

    void setupUi(QWidget *boardwindow)
    {
        if (boardwindow->objectName().isEmpty())
            boardwindow->setObjectName("boardwindow");
        boardwindow->resize(1920, 1080);
        area1 = new QPushButton(boardwindow);
        area1->setObjectName("area1");
        area1->setGeometry(QRect(610, 360, 61, 51));
        area2 = new QPushButton(boardwindow);
        area2->setObjectName("area2");
        area2->setGeometry(QRect(730, 360, 61, 51));
        area3 = new QPushButton(boardwindow);
        area3->setObjectName("area3");
        area3->setGeometry(QRect(840, 360, 61, 51));
        area4 = new QPushButton(boardwindow);
        area4->setObjectName("area4");
        area4->setGeometry(QRect(610, 460, 61, 51));
        area5 = new QPushButton(boardwindow);
        area5->setObjectName("area5");
        area5->setGeometry(QRect(730, 460, 61, 51));
        area6 = new QPushButton(boardwindow);
        area6->setObjectName("area6");
        area6->setGeometry(QRect(840, 460, 61, 51));
        area7 = new QPushButton(boardwindow);
        area7->setObjectName("area7");
        area7->setGeometry(QRect(610, 550, 61, 51));
        area8 = new QPushButton(boardwindow);
        area8->setObjectName("area8");
        area8->setGeometry(QRect(730, 550, 61, 51));
        area9 = new QPushButton(boardwindow);
        area9->setObjectName("area9");
        area9->setGeometry(QRect(840, 550, 61, 51));
        line1 = new QFrame(boardwindow);
        line1->setObjectName("line1");
        line1->setGeometry(QRect(690, 330, 20, 301));
        line1->setFrameShape(QFrame::Shape::VLine);
        line1->setFrameShadow(QFrame::Shadow::Sunken);
        line2 = new QFrame(boardwindow);
        line2->setObjectName("line2");
        line2->setGeometry(QRect(810, 330, 20, 301));
        line2->setFrameShape(QFrame::Shape::VLine);
        line2->setFrameShadow(QFrame::Shadow::Sunken);
        line3 = new QFrame(boardwindow);
        line3->setObjectName("line3");
        line3->setGeometry(QRect(587, 430, 351, 20));
        line3->setFrameShape(QFrame::Shape::HLine);
        line3->setFrameShadow(QFrame::Shadow::Sunken);
        line4 = new QFrame(boardwindow);
        line4->setObjectName("line4");
        line4->setGeometry(QRect(590, 530, 341, 16));
        line4->setFrameShape(QFrame::Shape::HLine);
        line4->setFrameShadow(QFrame::Shadow::Sunken);
        gameExitButton = new QPushButton(boardwindow);
        gameExitButton->setObjectName("gameExitButton");
        gameExitButton->setGeometry(QRect(1240, 0, 80, 24));
        gameExitConfirm = new QPushButton(boardwindow);
        gameExitConfirm->setObjectName("gameExitConfirm");
        gameExitConfirm->setGeometry(QRect(1150, 130, 80, 24));
        gameExitDeny = new QPushButton(boardwindow);
        gameExitDeny->setObjectName("gameExitDeny");
        gameExitDeny->setGeometry(QRect(1300, 130, 80, 24));
        exitPrompt = new QTextBrowser(boardwindow);
        exitPrompt->setObjectName("exitPrompt");
        exitPrompt->setGeometry(QRect(1060, 30, 341, 61));
        exitPromptMenu = new QTextBrowser(boardwindow);
        exitPromptMenu->setObjectName("exitPromptMenu");
        exitPromptMenu->setGeometry(QRect(1060, 30, 341, 61));
        menuExit = new QPushButton(boardwindow);
        menuExit->setObjectName("menuExit");
        menuExit->setGeometry(QRect(1150, 130, 80, 24));
        closeProgram = new QPushButton(boardwindow);
        closeProgram->setObjectName("closeProgram");
        closeProgram->setGeometry(QRect(1300, 130, 80, 24));
        goFirst = new QPushButton(boardwindow);
        goFirst->setObjectName("goFirst");
        goFirst->setGeometry(QRect(620, 280, 80, 24));
        goSecond = new QPushButton(boardwindow);
        goSecond->setObjectName("goSecond");
        goSecond->setGeometry(QRect(800, 280, 80, 24));
        playAgainPrompt = new QTextBrowser(boardwindow);
        playAgainPrompt->setObjectName("playAgainPrompt");
        playAgainPrompt->setGeometry(QRect(580, 650, 341, 61));
        replayConfirm = new QPushButton(boardwindow);
        replayConfirm->setObjectName("replayConfirm");
        replayConfirm->setGeometry(QRect(670, 730, 80, 24));
        replayDeny = new QPushButton(boardwindow);
        replayDeny->setObjectName("replayDeny");
        replayDeny->setGeometry(QRect(820, 730, 80, 24));
        playerPrompt = new QLabel(boardwindow);
        playerPrompt->setObjectName("playerPrompt");
        playerPrompt->setGeometry(QRect(580, 190, 381, 81));
        QFont font;
        font.setFamilies({QString::fromUtf8("Verdana")});
        font.setPointSize(15);
        playerPrompt->setFont(font);

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
        playAgainPrompt->setHtml(QCoreApplication::translate("boardwindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">Would you like to play again in the same mode?</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt;\"><br /></p></body></html>", nullptr));
        replayConfirm->setText(QCoreApplication::translate("boardwindow", "Yes", nullptr));
        replayDeny->setText(QCoreApplication::translate("boardwindow", "No", nullptr));
        playerPrompt->setText(QCoreApplication::translate("boardwindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class boardwindow: public Ui_boardwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOARDWINDOW_H
