#include "boardwindow.h"
#include "ui_boardwindow.h"
#include "mainwindow.h"
#include "tictactoeFuncs.h"
using namespace std;

extern string difficulty;
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

// Function used to hide extraneous buttons once the player determines the playing order
void boardwindow::hideChoices()
{
    ui->goFirst->setHidden(true);
    ui->goSecond->setHidden(true);
}

// Function used to prompt the player if they would like to go first or second
void boardwindow::showChoices()
{
    ui->playerPrompt->setText("Would you like to go first or second?");
    ui->goFirst->setHidden(false);
    ui->goSecond->setHidden(false);
}

// Function call to clear the playing UI and reset related game rules
void boardwindow::clearBoardUI()
{
    ui->playAgainPrompt->setHidden(true);
    ui->replayConfirm->setHidden(true);
    ui->replayDeny->setHidden(true);

    hidePlayArea();

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            board[i][j] = ' ';

    game.turn = 1;
    game.won = false;
    game.playerTurn = true;
    game.cpuTurn = false;
    game.currentPlayer = 'X';
    game.player = 'X';
    game.cpu = 'O';

    resetBoxes();
}

// Function used to hide the playing board
void boardwindow::hidePlayArea()
{
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
}

// Function used to show the board
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

// Function used to reset all of the play areas to the empty string
// Also resets the areaPlayed booleans so that the CPU will recognize open spaces across multiple games
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

    area1Played = false;
    area2Played = false;
    area3Played = false;
    area4Played = false;
    area5Played = false;
    area6Played = false;
    area7Played = false;
    area8Played = false;
    area9Played = false;
}

// Function call to announce that the game is over
// Message will change based on the outcome being a draw or win
// Will be adjusted to prompt the user if they would like to play again
void boardwindow::endGame(){
    ui->playAgainPrompt->setHidden(false);
    ui->replayConfirm->setHidden(false);
    ui->replayDeny->setHidden(false);

    if(game.won == false)
        ui->playerPrompt->setText("It's a draw!");
    QString currentText = ui->playerPrompt->text();
    ui->playerPrompt->setText(currentText + "\nThe game is now over!");
}

// Function call to receive the current player and return that string so it can be displayed
std::string boardwindow::getPlayer(){
    if(game.playerTurn)
        return "Player";
    else
        return "CPU";
}

// Function that will check if the move made wins the game
// If the game is won, a message will display showing the winner
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

// Function used to perform multiplayer turns
void boardwindow::mpTurn(){
    checkWinner();
    if(game.won || boardFull()){
        endGame();
        return;
    }

    if(game.turn % 2 != 0)
        game.player = 'X';
    else
        game.player = 'O';

    ui->playerPrompt->setText(QString("Player %1 make your move:").arg(game.player == 'X' ? 1 : 2));
}

// Function called to perform the player's turn
void boardwindow::playerTurn(){

    checkWinner();

    if(game.won || boardFull()){
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

// Function will return the move for the CPU based on the selected level of difficulty
int boardwindow::getDifficulty()
{
    int move;
    if(difficulty == "Easy")
        move = cpuMoveEasy();
    else if(difficulty == "Medium")
        move = cpuMoveMedium(board, game.cpu, game.player);
    else
        move = cpuMoveHard(board, game.cpu, game.player, game.turn);

    return(move);
}

// Function called to perform the CPU's turn
// Move difficulty will be decided by the player's chosen input
void boardwindow::cpuTurn(){

    if(game.won || boardFull()){
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
        position = getDifficulty();
    } while (!legalMoveCheck(position));

    setArea(position);

    game.turn++;

    if(game.turn >= 5)
        checkWinner();

}

// Area 1 (Top Left) of the board will be set to the player's character
void boardwindow::on_area1_clicked()
{
    if(area1Played == true){
        ui->playerPrompt->setText("Invalid selection: please try again");
        return;
    }
    else{
        if(game.player == 'X')
            ui->area1->setText("X");
        else
            ui->area1->setText("O");

        board[0][0] = game.player;
        area1Played = true;
    }

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

// Area 2 (Top Middle) of the board will be set to the player's character
void boardwindow::on_area2_clicked()
{
    if(area2Played == true){
        ui->playerPrompt->setText("Invalid selection: please try again");
        return;
    }
    else{
        if(game.player == 'X')
            ui->area2->setText("X");
        else
            ui->area2->setText("O");

        board[0][1] = game.player;
        area2Played = true;
    }

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

// Area 3 (Top Right) of the board will be set to the player's character
void boardwindow::on_area3_clicked()
{
    if(area3Played == true){
        ui->playerPrompt->setText("Invalid selection: please try again");
        return;
    }
    else{
        if(game.player == 'X')
            ui->area3->setText("X");
        else
            ui->area3->setText("O");

        board[0][2] = game.player;
        area3Played = true;
    }

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

// Area 4 (Middle Left) of the board will be set to the player's character
void boardwindow::on_area4_clicked()
{

    if(area4Played == true){
        ui->playerPrompt->setText("Invalid selection: please try again");
        return;
    }
    else{
        if(game.player == 'X')
            ui->area4->setText("X");
        else
            ui->area4->setText("O");

        board[1][0] = game.player;
        area4Played = true;
    }

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

// Area 5 (Middle Middle) of the board will be set to the player's character
void boardwindow::on_area5_clicked()
{
    if(area5Played == true){
        ui->playerPrompt->setText("Invalid selection: please try again");
        return;
    }
    else{
        if(game.player == 'X')
            ui->area5->setText("X");
        else
            ui->area5->setText("O");

        board[1][1] = game.player;
        area5Played = true;
    }

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

// Area 6 (Middle Right) of the board will be set to the player's character
void boardwindow::on_area6_clicked()
{
    if(area6Played == true){
        ui->playerPrompt->setText("Invalid selection: please try again");
        return;
    }
    else{
        if(game.player == 'X')
            ui->area6->setText("X");
        else
            ui->area6->setText("O");

        board[1][2] = game.player;
        area6Played = true;
    }

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

// Area 7 (Bottom Left) of the board will be set to the player's character
void boardwindow::on_area7_clicked()
{
    if(area7Played == true){
        ui->playerPrompt->setText("Invalid selection: please try again");
        return;
    }
    else{
        if(game.player == 'X')
            ui->area7->setText("X");
        else
            ui->area7->setText("O");

        board[2][0] = game.player;
        area7Played = true;
    }

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

// Area 8 (Bottom Middle) of the board will be set to the player's character
void boardwindow::on_area8_clicked()
{
    if(area8Played == true){
        ui->playerPrompt->setText("Invalid selection: please try again");
        return;
    }
    else{
        if(game.player == 'X')
            ui->area8->setText("X");
        else
            ui->area8->setText("O");

        board[2][1] = game.player;
        area8Played = true;
    }

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

// Area 9 (Bottom Right) of the board will be set to the player's character
void boardwindow::on_area9_clicked()
{
    if(area9Played == true){
        ui->playerPrompt->setText("Invalid selection: please try again");
        return;
    }
    else{
        if(game.player == 'X')
            ui->area9->setText("X");
        else
            ui->area9->setText("O");

        board[2][2] = game.player;
        area9Played = true;
    }

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


// Starting a game where the Player moves first
void boardwindow::on_goFirst_clicked()
{
    hideChoices();
    showPlayArea();

    game.player = 'X';
    game.cpu = 'O';

    playerTurn();
}

// Starting a game where the CPU moves first
void boardwindow::on_goSecond_clicked()
{
    hideChoices();
    showPlayArea();

    game.player = 'O';
    game.cpu = 'X';

    cpuTurn();
}

// Button definition to replay the same difficulty once the game is complete
void boardwindow::on_replayConfirm_clicked()
{
    clearBoardUI();

    showChoices();
}

// Button definition to exit to the main menu once the game is complete
void boardwindow::on_replayDeny_clicked()
{
    this->hide();
    emit backToMenu();
}


// Function used to enable the CPU to pick a square and move the turn to the player
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

// Boolean used for the CPU to check whether or not a move is legal
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

// Boolean function used to determine if the board is full, used to determine the case of a draw
bool boardwindow::boardFull()
{
    bool empty = false, full = false;

    for(int i = 0; i < 3 && !empty; i++)
        for(int j = 0; j < 3; j++)
            if(board[i][j] == ' ')
                empty = true;

    if(!empty)
        full = true;

    return(full);
}

// Button that will allow the user to proceed with or cancel exiting the game
void boardwindow::on_gameExitButton_clicked()
{
    if(ui->gameExitConfirm->isHidden() == true){
        if(ui->menuExit->isHidden() == false){
            ui->exitPromptMenu->setHidden(true);
            ui->menuExit->setHidden(true);
            ui->closeProgram->setHidden(true);
            ui->gameExitConfirm->setHidden(true);
            ui->gameExitDeny->setHidden(true);
            ui->exitPrompt->setHidden(true);
        }
        else{
            ui->exitPrompt->setHidden(false);
            ui->gameExitConfirm->setHidden(false);
            ui->gameExitDeny->setHidden(false);
        }
    }
    else if(ui->gameExitConfirm->isHidden() == false){
        ui->exitPrompt->setHidden(true);
        ui->gameExitConfirm->setHidden(true);
        ui->gameExitDeny->setHidden(true);
    }
}

// Button that confirms the user wants to exit the game
// They are then prompted if they want to close the program or enter the main menu
void boardwindow::on_gameExitConfirm_clicked()
{
    ui->exitPromptMenu->setHidden(false);
    ui->menuExit->setHidden(false);
    ui->closeProgram->setHidden(false);

    ui->gameExitConfirm->setHidden(true);
    ui->gameExitDeny->setHidden(true);
}

// Button that when clicked will deny the action of exiting the game
void boardwindow::on_gameExitDeny_clicked()
{
    ui->gameExitConfirm->setHidden(true);
    ui->gameExitDeny->setHidden(true);
    ui->exitPrompt->setHidden(true);
}

// Button that when pressed is used to close the program
void boardwindow::on_closeProgram_clicked()
{
    close();
}

// Button that when pressed is used to exit to the main menu
void boardwindow::on_menuExit_clicked()
{
    this->hide();
    emit backToMenu();
}
