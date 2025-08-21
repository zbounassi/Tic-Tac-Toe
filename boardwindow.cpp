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

    ui->area1Text->setHidden(true);
    ui->area2Text->setHidden(true);
    ui->area3Text->setHidden(true);
    ui->area4Text->setHidden(true);
    ui->area5Text->setHidden(true);
    ui->area6Text->setHidden(true);
    ui->area7Text->setHidden(true);
    ui->area8Text->setHidden(true);
    ui->area9Text->setHidden(true);

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

string order;

void boardwindow::changeTurns(){
    if(game.currentPlayer == game.player){
        game.currentPlayer = game.cpu;
        game.playerTurn = false;
        game.cpuTurn = true;
    }
    else{
        game.currentPlayer = game.player;
        game.playerTurn = true;
        game.cpuTurn = false;
    }
    game.turn++;
};

void boardwindow::playCPUEasy(string order){

    int position;
    bool cpuMoveMade = false;
    string playAgain;

    if(order == "first"){
        game.player = 'X';
        game.cpu = 'O';
    }
    else{
        game.cpu = 'X';
        game.player = 'O';
    }

    if(!game.won && game.turn <= 9){

        if((game.player == 'X' && game.turn % 2 != 0) || (game.player == 'O' && game.turn % 2 == 0))
            game.playerTurn = true;
        else
            game.cpuTurn = true;

        if(game.playerTurn){
            ui->playerPrompt->setText("Player please make your move");
            game.currentPlayer = game.player;

            // Wait for an area to be clicked
            // once area is clicked it should increment the turn and move onto the cpu's turn


        }
        else{
            ui->playerPrompt->setText("CPU is calculating its move");
            game.currentPlayer = game.cpu;

            // CPU selects the square to be played in and needs to act as though it clicked the space
            position = cpuMoveEasy();
            if(!cpuMoveMade){
                switch(position){
                case 1:
                    on_area1_clicked();
                    cpuMoveMade = true;
                    break;
                case 2:
                    on_area2_clicked();
                    cpuMoveMade = true;
                    break;
                case 3:
                    on_area3_clicked();
                    cpuMoveMade = true;
                    break;
                case 4:
                    on_area4_clicked();
                    cpuMoveMade = true;
                    break;
                case 5:
                    on_area5_clicked();
                    cpuMoveMade = true;
                    break;
                case 6:
                    on_area6_clicked();
                    cpuMoveMade = true;
                    break;
                case 7:
                    on_area7_clicked();
                    cpuMoveMade = true;
                    break;
                case 8:
                    on_area8_clicked();
                    cpuMoveMade = true;
                    break;
                case 9:
                    on_area9_clicked();
                    cpuMoveMade = true;
                    break;
                default:
                    position = cpuMoveEasy();
                }
            }
        }

        if(game.won == false)
            ui->playerPrompt->setText("The game has ended in a draw!");

        ui->playAgainPrompt->setHidden(false);
        ui->replayConfirm->setHidden(false);
        ui->replayDeny->setHidden(false);
    }
};


void boardwindow::on_area1_clicked()
{
    if(game.currentPlayer == 'X')
        ui->area1Text->setText("X");
    else
        ui->area1Text->setText("O");

    ui->area1Text->setHidden(false);
    ui->area1->setHidden(true);
}

void boardwindow::on_area2_clicked()
{
    if(game.currentPlayer == 'X')
        ui->area2Text->setText("X");
    else
        ui->area2Text->setText("O");

    ui->area2Text->setHidden(false);
    ui->area2->setHidden(true);
}

void boardwindow::on_area3_clicked()
{
    if(game.currentPlayer == 'X')
        ui->area3Text->setText("X");
    else
        ui->area3Text->setText("O");

    ui->area3Text->setHidden(false);
    ui->area3->setHidden(true);
}
void boardwindow::on_area4_clicked()
{
    if(game.currentPlayer == 'X')
        ui->area4Text->setText("X");
    else
        ui->area4Text->setText("O");

    ui->area4Text->setHidden(false);
    ui->area4->setHidden(true);
}

void boardwindow::on_area5_clicked()
{
    if(game.currentPlayer == 'X')
        ui->area5Text->setText("X");
    else
        ui->area5Text->setText("O");

    ui->area5Text->setHidden(false);
    ui->area5->setHidden(true);
}
void boardwindow::on_area6_clicked()
{
    if(game.currentPlayer == 'X')
        ui->area6Text->setText("X");
    else
        ui->area6Text->setText("O");

    ui->area6Text->setHidden(false);
    ui->area6->setHidden(true);
}
void boardwindow::on_area7_clicked()
{
    if(game.currentPlayer == 'X')
        ui->area7Text->setText("X");
    else
        ui->area7Text->setText("O");

    ui->area7Text->setHidden(false);
    ui->area7->setHidden(true);
}
void boardwindow::on_area8_clicked()
{
    if(game.currentPlayer == 'X')
        ui->area8Text->setText("X");
    else
        ui->area8Text->setText("O");

    ui->area8Text->setHidden(false);
    ui->area8->setHidden(true);
}
void boardwindow::on_area9_clicked()
{
    if(game.currentPlayer == 'X')
        ui->area9Text->setText("X");
    else
        ui->area9Text->setText("O");

    ui->area9Text->setHidden(false);
    ui->area9->setHidden(true);
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

