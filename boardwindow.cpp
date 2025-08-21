#include "boardwindow.h"
#include "ui_boardwindow.h"
#include "mainwindow.cpp"
using namespace std;

boardwindow::boardwindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::boardwindow)
{
    ui->setupUi(this);

    ui->gameExitConfirm->setHidden(true);
    ui->gameExitDeny->setHidden(true);
    ui->exitPrompt->setHidden(true);
    ui->exitPromptMenu->setHidden(true);
    ui->menuExit->setHidden(true);
    ui->closeProgram->setHidden(true);

    ui->area1->setHidden(true);
    ui->area2->setHidden(true);
    ui->area3->setHidden(true);
    ui->area4->setHidden(true);
    ui->area5->setHidden(true);
    ui->area6->setHidden(true);
    ui->area7->setHidden(true);
    ui->area8->setHidden(true);
    ui->area9->setHidden(true);

    ui->line1->setHidden(true);
    ui->line2->setHidden(true);
    ui->line3->setHidden(true);
    ui->line4->setHidden(true);

    ui->playAgainPrompt->setHidden(true);
    ui->replayConfirm->setHidden(true);
    ui->replayDeny->setHidden(true);
}

boardwindow::~boardwindow()
{
    delete ui;
}

void boardwindow::hideChoices()
{
    ui->goFirst->setHidden(true);
    ui->goSecond->setHidden(true);
}

void boardwindow::showPlayArea()
{
    ui->area1->setHidden(false);
    ui->area2->setHidden(false);
    ui->area3->setHidden(false);
    ui->area4->setHidden(false);
    ui->area5->setHidden(false);
    ui->area6->setHidden(false);
    ui->area7->setHidden(false);
    ui->area8->setHidden(false);
    ui->area9->setHidden(false);

    ui->line1->setHidden(false);
    ui->line2->setHidden(false);
    ui->line3->setHidden(false);
    ui->line4->setHidden(false);
}

int turn = 1;
char player, cpu;
string order;

void boardwindow::playCPUEasy(string order){

    bool won = false, playerTurn = false;
    string playAgain;

    if(order == "first"){
        player = 'X';
        cpu = 'O';
    }
    else{
        cpu = 'X';
        player = 'O';
    }

    while(!won && turn <= 9){
        if((player == 'X' && turn % 2 != 0) || (player == 'O' && turn % 2 == 0))
            playerTurn = true;

        if(playerTurn){
            ui->playerPrompt->setText("Player please make your move");

            // Wait for an area to be clicked
            // once area is clicked it should increment the turn and move onto the cpu's turn


        }
        else{
            ui->playerPrompt->setText("CPU is calculating its move");

            // CPU selects the square to be played in and needs to act as though it clicked the space

        }


        turn++;

    }

    if(won == false)
        ui->playerPrompt->setText("The game has ended in a draw!");


    ui->playAgainPrompt->setHidden(false);
    ui->replayConfirm->setHidden(false);
    ui->replayDeny->setHidden(false);


};


void boardwindow::on_area1_clicked()
{

}
void boardwindow::on_area2_clicked()
{

}

void boardwindow::on_area3_clicked()
{

}
void boardwindow::on_area4_clicked()
{

}

void boardwindow::on_area5_clicked()
{

}
void boardwindow::on_area6_clicked()
{

}
void boardwindow::on_area7_clicked()
{

}
void boardwindow::on_area8_clicked()
{

}
void boardwindow::on_area9_clicked()
{

}


void boardwindow::on_gameExitButton_clicked()
{
    ui->gameExitConfirm->setHidden(false);
    ui->gameExitDeny->setHidden(false);
    ui->exitPrompt->setHidden(false);
}


void boardwindow::on_gameExitConfirm_clicked()
{
    ui->exitPromptMenu->setHidden(false);
    ui->menuExit->setHidden(false);
    ui->closeProgram->setHidden(false);
}


void boardwindow::on_gameExitDeny_clicked()
{
    ui->gameExitConfirm->setHidden(true);
    ui->gameExitDeny->setHidden(true);
    ui->exitPrompt->setHidden(true);
}

void boardwindow::on_closeProgram_clicked()
{
    close();
}


void boardwindow::on_menuExit_clicked()
{
    this->hide();
    emit backToMenu();
}


void boardwindow::on_goFirst_clicked()
{
    hideChoices();
    showPlayArea();
    order = "first";
    playCPUEasy(order);
}


void boardwindow::on_goSecond_clicked()
{
    hideChoices();
    showPlayArea();
    order = "second";
    playCPUEasy(order);
}



void boardwindow::on_replayConfirm_clicked()
{

}

