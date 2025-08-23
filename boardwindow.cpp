#include "boardwindow.h"
#include "ui_boardwindow.h"
#include "mainwindow.h"
#include "tictactoeFuncs.h"
using namespace std;

string order;

bool area1Played = false;
bool area2Played = false;
bool area3Played = false;
bool area4Played = false;
bool area5Played = false;
bool area6Played = false;
bool area7Played = false;
bool area8Played = false;
bool area9Played = false;
bool cpuMoveMade = false;

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

void boardwindow::showChoices()
{
    ui->playerPrompt->setText("Would you like to go first or second?");
    ui->goFirst->setHidden(false);
    ui->goSecond->setHidden(false);
}

void boardwindow::clearBoardUI()
{
    showPlayArea();

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            board[i][j] = ' ';

    resetBoxes();
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

void boardwindow::resetBoxes()
{
    ui->area1->setText("");
    ui->area2->setText("");
    ui->area3->setText("");
    ui->area4->setText("");
    ui->area5->setText("");
    ui->area6->setText("");
    ui->area7->setText("");
    ui->area8->setText("");
    ui->area9->setText("");
}

void boardwindow::endGame(){
    ui->playAgainPrompt->setHidden(false);
    ui->replayConfirm->setHidden(false);
    ui->replayDeny->setHidden(false);

    if(game.won == false)
        ui->playerPrompt->setText("It's a draw!");
    QString currentText = ui->playerPrompt->text();
    ui->playerPrompt->setText(currentText + "\nThe game is now over!");
}

std::string boardwindow::getPlayer(){
    if(game.playerTurn)
        return "Player";
    else
        return "CPU";
}

bool boardwindow::checkWinner(){

    char player = game.currentPlayer;
    bool won = false;

    //check rows and cols
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) won = true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) won = true;
    }

    //check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) won = true;
    if (board[2][0] == player && board[1][1] == player && board[0][2] == player) won = true;

    if(won){
        game.won = true;
        string winner = getPlayer();
        ui->playerPrompt->setText(QString("The %1 has won the game!").arg(winner));
    }
    //false if none are true
    return false;
}

void boardwindow::playerTurn(){
    if(game.won || game.turn > 9){
        endGame();
        return;
    }

    game.playerTurn = true;
    game.cpuTurn = false;
    cpuMoveMade = false;

    game.currentPlayer = game.player;

    QApplication::processEvents();
    ui->playerPrompt->setText("Player please make your move:");
}

void boardwindow::cpuTurn(){

    if(game.won || game.turn > 9){
        endGame();
        return;
    }

    game.playerTurn = false;
    game.cpuTurn = true;

    game.currentPlayer = game.cpu;
    ui->playerPrompt->setText("CPU is calculating its move");
    QApplication::processEvents();

    int position;

    do{
        position = cpuMoveEasy();
    } while (!legalMoveCheck(position));

    game.turn++;
    setArea(position);

    checkWinner();
}

void boardwindow::on_area1_clicked()
{
    if(game.player == 'X')
        ui->area1->setText("X");
    else
        ui->area1->setText("O");

    board[0][0] = game.player;
    area1Played = true;

    if(game.turn > 4){
        if(!checkWinner()){
            game.turn++;
            cpuTurn();
        }
        else
            endGame();
    }
    else{
        game.turn++;
        cpuTurn();
    }
}

void boardwindow::on_area2_clicked()
{
    if(game.player == 'X')
        ui->area2->setText("X");
    else
        ui->area2->setText("O");

    board[0][1] = game.player;
    area2Played = true;

    if(game.turn > 4){
        if(!checkWinner()){
            game.turn++;
            cpuTurn();
        }
        else
            endGame();
    }
    else{
        game.turn++;
        cpuTurn();
    }
}

void boardwindow::on_area3_clicked()
{
    if(game.player == 'X')
        ui->area3->setText("X");
    else
        ui->area3->setText("O");

    board[0][2] = game.player;
    area3Played = true;

    if(game.turn > 4){
        if(!checkWinner()){
            game.turn++;
            cpuTurn();
        }
        else
            endGame();
    }
    else{
        game.turn++;
        cpuTurn();
    }
}

void boardwindow::on_area4_clicked()
{
    if(game.player == 'X')
        ui->area4->setText("X");
    else
        ui->area4->setText("O");

    board[1][0] = game.player;
    area4Played = true;

    if(game.turn > 4){
        if(!checkWinner()){
            game.turn++;
            cpuTurn();
        }
        else
            endGame();
    }
    else{
        game.turn++;
        cpuTurn();
    }
}

void boardwindow::on_area5_clicked()
{
    if(game.player == 'X')
        ui->area5->setText("X");
    else
        ui->area5->setText("O");

    board[1][1] = game.player;
    area5Played = true;

    if(game.turn > 4){
        if(!checkWinner()){
            game.turn++;
            cpuTurn();
        }
        else
            endGame();
    }
    else{
        game.turn++;
        cpuTurn();
    }
}

void boardwindow::on_area6_clicked()
{
    if(game.player == 'X')
        ui->area6->setText("X");
    else
        ui->area6->setText("O");

    board[1][2] = game.player;
    area6Played = true;

    if(game.turn > 4){
        if(!checkWinner()){
            game.turn++;
            cpuTurn();
        }
        else
            endGame();
    }
    else{
        game.turn++;
        cpuTurn();
    }
}

void boardwindow::on_area7_clicked()
{
    if(game.player == 'X')
        ui->area7->setText("X");
    else
        ui->area7->setText("O");

    board[2][0] = game.player;
    area7Played = true;

    if(game.turn > 4){
        if(!checkWinner()){
            game.turn++;
            cpuTurn();
        }
        else
            endGame();
    }
    else{
        game.turn++;
        cpuTurn();
    }
}

void boardwindow::on_area8_clicked()
{
    if(game.player == 'X')
        ui->area8->setText("X");
    else
        ui->area8->setText("O");

    board[2][1] = game.player;
    area8Played = true;

    if(game.turn > 4){
        if(!checkWinner()){
            game.turn++;
            cpuTurn();
        }
        else
            endGame();
    }
    else{
        game.turn++;
        cpuTurn();
    }
}

void boardwindow::on_area9_clicked()
{
    if(game.player == 'X')
        ui->area9->setText("X");
    else
        ui->area9->setText("O");

    board[2][2] = game.player;
    area9Played = true;

    if(game.turn > 4){
        if(!checkWinner()){
            game.turn++;
            cpuTurn();
        }
        else
            endGame();
    }
    else{
        game.turn++;
        cpuTurn();
    }
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

    game.player = 'X';
    game.cpu = 'O';

    playerTurn();
}

void boardwindow::on_goSecond_clicked()
{
    hideChoices();
    showPlayArea();

    game.player = 'O';
    game.cpu = 'X';

    cpuTurn();
}

void boardwindow::on_replayConfirm_clicked()
{

}

void boardwindow::setArea(int pos){
    switch(pos){
    case 1:
        if(!area1Played){
            if(game.cpu == 'X')
                ui->area1->setText("X");
            else
                ui->area1->setText("O");


            board[0][0] = game.cpu;
            area1Played = true;

            cpuMoveMade = true;

            playerTurn();
        }
        break;
    case 2:
        if(!area2Played){
            if(game.cpu== 'X')
                ui->area2->setText("X");
            else
                ui->area2->setText("O");

            board[0][1] = game.cpu;
            area2Played = true;

            cpuMoveMade = true;

            playerTurn();
        }
        break;
    case 3:
        if(!area3Played){
            if(game.cpu == 'X')
                ui->area3->setText("X");
            else
                ui->area3->setText("O");

            board[0][2] = game.cpu;
            area3Played = true;

            cpuMoveMade = true;

            playerTurn();
        }
        break;
    case 4:
        if(!area4Played){
            if(game.cpu == 'X')
                ui->area4->setText("X");
            else
                ui->area4->setText("O");

            board[1][0] = game.cpu;
            area4Played = true;

            cpuMoveMade = true;

            playerTurn();
        }
        break;
    case 5:
        if(!area5Played){
            if(game.cpu == 'X')
                ui->area5->setText("X");
            else
                ui->area5->setText("O");

            board[1][1] = game.cpu;
            area5Played = true;

            cpuMoveMade = true;

            playerTurn();
        }
        break;
    case 6:
        if(!area6Played){
            if(game.cpu == 'X')
                ui->area6->setText("X");
            else
                ui->area6->setText("O");

            board[1][2] = game.cpu;
            area6Played = true;

            cpuMoveMade = true;

            playerTurn();
        }
        break;
    case 7:
        if(!area7Played){
            if(game.cpu == 'X')
                ui->area7->setText("X");
            else
                ui->area7->setText("O");

            board[2][0] = game.cpu;
            area7Played = true;

            cpuMoveMade = true;

            playerTurn();
        }
        break;
    case 8:
        if(!area8Played){
            if(game.cpu == 'X')
                ui->area8->setText("X");
            else
                ui->area8->setText("O");

            board[2][1] = game.cpu;
            area8Played = true;

            cpuMoveMade = true;

            playerTurn();
        }
        break;
    case 9:
        if(!area9Played){
            if(game.cpu == 'X')
                ui->area9->setText("X");
            else
                ui->area9->setText("O");

            board[2][2] = game.cpu;
            area9Played = true;

            cpuMoveMade = true;

            playerTurn();
        }
        break;
    }
}

bool boardwindow::legalMoveCheck(int pos){
    switch(pos){
    case 1: return (board[0][0] == ' ');
    case 2: return (board[0][1] == ' ');
    case 3: return (board[0][2] == ' ');
    case 4: return (board[1][0] == ' ');
    case 5: return (board[1][1] == ' ');
    case 6: return (board[1][2] == ' ');
    case 7: return (board[2][0] == ' ');
    case 8: return (board[2][1] == ' ');
    case 9: return (board[2][2] == ' ');
    default: return false;
    }
}
