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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_boardwindow
{
public:
    QLabel *nameAskLabel;
    QPushButton *nameConfirm;
    QTextEdit *p2Entry;
    QWidget *exitWidget;
    QPushButton *gameExitButton;
    QPushButton *gameExitDeny;
    QPushButton *gameExitConfirm;
    QPushButton *closeProgram;
    QPushButton *exitToMenu;
    QLabel *exitMenuOrClose;
    QTextEdit *p1Entry;
    QWidget *boardLocation;
    QFrame *line4;
    QPushButton *area4;
    QPushButton *area8;
    QFrame *line2;
    QPushButton *area6;
    QPushButton *area2;
    QFrame *line1;
    QPushButton *area5;
    QPushButton *area7;
    QPushButton *area1;
    QPushButton *area3;
    QPushButton *area9;
    QFrame *line3;
    QLabel *playerPrompt;
    QPushButton *goSecond;
    QPushButton *goFirst;
    QPushButton *replayDeny;
    QLabel *changeSides;
    QLabel *playAgainPrompt;
    QPushButton *doNotChange;
    QPushButton *performChange;
    QPushButton *replayConfirm;
    QLabel *winTracker;
    QLabel *p2Prompt;
    QLabel *p1Prompt;

    void setupUi(QWidget *boardwindow)
    {
        if (boardwindow->objectName().isEmpty())
            boardwindow->setObjectName("boardwindow");
        boardwindow->resize(1920, 1080);
        boardwindow->setMinimumSize(QSize(800, 600));
        nameAskLabel = new QLabel(boardwindow);
        nameAskLabel->setObjectName("nameAskLabel");
        nameAskLabel->setGeometry(QRect(750, 220, 291, 51));
        nameConfirm = new QPushButton(boardwindow);
        nameConfirm->setObjectName("nameConfirm");
        nameConfirm->setGeometry(QRect(860, 430, 141, 31));
        p2Entry = new QTextEdit(boardwindow);
        p2Entry->setObjectName("p2Entry");
        p2Entry->setGeometry(QRect(840, 350, 181, 61));
        exitWidget = new QWidget(boardwindow);
        exitWidget->setObjectName("exitWidget");
        exitWidget->setGeometry(QRect(950, 0, 351, 151));
        gameExitButton = new QPushButton(exitWidget);
        gameExitButton->setObjectName("gameExitButton");
        gameExitButton->setGeometry(QRect(260, 10, 80, 24));
        gameExitDeny = new QPushButton(exitWidget);
        gameExitDeny->setObjectName("gameExitDeny");
        gameExitDeny->setGeometry(QRect(260, 120, 80, 24));
        gameExitConfirm = new QPushButton(exitWidget);
        gameExitConfirm->setObjectName("gameExitConfirm");
        gameExitConfirm->setGeometry(QRect(110, 120, 80, 24));
        closeProgram = new QPushButton(exitWidget);
        closeProgram->setObjectName("closeProgram");
        closeProgram->setGeometry(QRect(260, 120, 80, 24));
        exitToMenu = new QPushButton(exitWidget);
        exitToMenu->setObjectName("exitToMenu");
        exitToMenu->setGeometry(QRect(110, 120, 80, 24));
        exitMenuOrClose = new QLabel(exitWidget);
        exitMenuOrClose->setObjectName("exitMenuOrClose");
        exitMenuOrClose->setGeometry(QRect(0, 40, 341, 61));
        p1Entry = new QTextEdit(boardwindow);
        p1Entry->setObjectName("p1Entry");
        p1Entry->setGeometry(QRect(840, 270, 181, 61));
        boardLocation = new QWidget(boardwindow);
        boardLocation->setObjectName("boardLocation");
        boardLocation->setGeometry(QRect(320, 100, 401, 551));
        boardLocation->setMinimumSize(QSize(0, 0));
        line4 = new QFrame(boardLocation);
        line4->setObjectName("line4");
        line4->setGeometry(QRect(20, 300, 341, 16));
        line4->setFrameShape(QFrame::Shape::HLine);
        line4->setFrameShadow(QFrame::Shadow::Sunken);
        area4 = new QPushButton(boardLocation);
        area4->setObjectName("area4");
        area4->setGeometry(QRect(40, 230, 61, 51));
        area8 = new QPushButton(boardLocation);
        area8->setObjectName("area8");
        area8->setGeometry(QRect(160, 320, 61, 51));
        line2 = new QFrame(boardLocation);
        line2->setObjectName("line2");
        line2->setGeometry(QRect(240, 100, 20, 301));
        line2->setFrameShape(QFrame::Shape::VLine);
        line2->setFrameShadow(QFrame::Shadow::Sunken);
        area6 = new QPushButton(boardLocation);
        area6->setObjectName("area6");
        area6->setGeometry(QRect(270, 230, 61, 51));
        area2 = new QPushButton(boardLocation);
        area2->setObjectName("area2");
        area2->setGeometry(QRect(160, 130, 61, 51));
        line1 = new QFrame(boardLocation);
        line1->setObjectName("line1");
        line1->setGeometry(QRect(120, 100, 20, 301));
        line1->setFrameShape(QFrame::Shape::VLine);
        line1->setFrameShadow(QFrame::Shadow::Sunken);
        area5 = new QPushButton(boardLocation);
        area5->setObjectName("area5");
        area5->setGeometry(QRect(160, 230, 61, 51));
        area7 = new QPushButton(boardLocation);
        area7->setObjectName("area7");
        area7->setGeometry(QRect(40, 320, 61, 51));
        area1 = new QPushButton(boardLocation);
        area1->setObjectName("area1");
        area1->setGeometry(QRect(40, 130, 61, 51));
        area3 = new QPushButton(boardLocation);
        area3->setObjectName("area3");
        area3->setGeometry(QRect(270, 130, 61, 51));
        area9 = new QPushButton(boardLocation);
        area9->setObjectName("area9");
        area9->setGeometry(QRect(270, 320, 61, 51));
        line3 = new QFrame(boardLocation);
        line3->setObjectName("line3");
        line3->setGeometry(QRect(17, 200, 351, 20));
        line3->setFrameShape(QFrame::Shape::HLine);
        line3->setFrameShadow(QFrame::Shadow::Sunken);
        playerPrompt = new QLabel(boardLocation);
        playerPrompt->setObjectName("playerPrompt");
        playerPrompt->setGeometry(QRect(10, 30, 381, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Verdana")});
        font.setPointSize(15);
        playerPrompt->setFont(font);
        goSecond = new QPushButton(boardLocation);
        goSecond->setObjectName("goSecond");
        goSecond->setGeometry(QRect(240, 100, 80, 24));
        goFirst = new QPushButton(boardLocation);
        goFirst->setObjectName("goFirst");
        goFirst->setGeometry(QRect(60, 103, 80, 21));
        replayDeny = new QPushButton(boardLocation);
        replayDeny->setObjectName("replayDeny");
        replayDeny->setGeometry(QRect(230, 490, 80, 24));
        changeSides = new QLabel(boardLocation);
        changeSides->setObjectName("changeSides");
        changeSides->setGeometry(QRect(30, 410, 231, 61));
        QFont font1;
        font1.setPointSize(12);
        changeSides->setFont(font1);
        playAgainPrompt = new QLabel(boardLocation);
        playAgainPrompt->setObjectName("playAgainPrompt");
        playAgainPrompt->setGeometry(QRect(30, 410, 351, 61));
        playAgainPrompt->setFont(font1);
        doNotChange = new QPushButton(boardLocation);
        doNotChange->setObjectName("doNotChange");
        doNotChange->setGeometry(QRect(230, 490, 80, 24));
        performChange = new QPushButton(boardLocation);
        performChange->setObjectName("performChange");
        performChange->setGeometry(QRect(80, 490, 80, 24));
        replayConfirm = new QPushButton(boardLocation);
        replayConfirm->setObjectName("replayConfirm");
        replayConfirm->setGeometry(QRect(80, 490, 80, 24));
        winTracker = new QLabel(boardwindow);
        winTracker->setObjectName("winTracker");
        winTracker->setGeometry(QRect(60, 90, 171, 231));
        p2Prompt = new QLabel(boardwindow);
        p2Prompt->setObjectName("p2Prompt");
        p2Prompt->setGeometry(QRect(760, 370, 49, 16));
        p1Prompt = new QLabel(boardwindow);
        p1Prompt->setObjectName("p1Prompt");
        p1Prompt->setGeometry(QRect(760, 290, 49, 16));

        retranslateUi(boardwindow);

        QMetaObject::connectSlotsByName(boardwindow);
    } // setupUi

    void retranslateUi(QWidget *boardwindow)
    {
        boardwindow->setWindowTitle(QCoreApplication::translate("boardwindow", "Form", nullptr));
        nameAskLabel->setText(QCoreApplication::translate("boardwindow", "Please enter the names of the two players: ", nullptr));
        nameConfirm->setText(QCoreApplication::translate("boardwindow", "Submit Names", nullptr));
        gameExitButton->setText(QCoreApplication::translate("boardwindow", "Exit to Menu", nullptr));
        gameExitDeny->setText(QCoreApplication::translate("boardwindow", "No", nullptr));
        gameExitConfirm->setText(QCoreApplication::translate("boardwindow", "Yes", nullptr));
        closeProgram->setText(QCoreApplication::translate("boardwindow", "Close Program", nullptr));
        exitToMenu->setText(QCoreApplication::translate("boardwindow", "Exit to Menu", nullptr));
        exitMenuOrClose->setText(QCoreApplication::translate("boardwindow", "Would you like to exit to the menu or close the program?", nullptr));
        area4->setText(QString());
        area8->setText(QString());
        area6->setText(QString());
        area2->setText(QString());
        area5->setText(QString());
        area7->setText(QString());
        area1->setText(QString());
        area3->setText(QString());
        area9->setText(QString());
        playerPrompt->setText(QCoreApplication::translate("boardwindow", "TextLabel", nullptr));
        goSecond->setText(QCoreApplication::translate("boardwindow", "Second", nullptr));
        goFirst->setText(QCoreApplication::translate("boardwindow", "First", nullptr));
        replayDeny->setText(QCoreApplication::translate("boardwindow", "No", nullptr));
        changeSides->setText(QCoreApplication::translate("boardwindow", "Would you like to change sides?", nullptr));
        playAgainPrompt->setText(QCoreApplication::translate("boardwindow", "Would you like to play again in the same mode?", nullptr));
        doNotChange->setText(QCoreApplication::translate("boardwindow", "No", nullptr));
        performChange->setText(QCoreApplication::translate("boardwindow", "Yes", nullptr));
        replayConfirm->setText(QCoreApplication::translate("boardwindow", "Yes", nullptr));
        winTracker->setText(QCoreApplication::translate("boardwindow", "TextLabel", nullptr));
        p2Prompt->setText(QCoreApplication::translate("boardwindow", "Player 2:", nullptr));
        p1Prompt->setText(QCoreApplication::translate("boardwindow", "Player 1:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class boardwindow: public Ui_boardwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOARDWINDOW_H
