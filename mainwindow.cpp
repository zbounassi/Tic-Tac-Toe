#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tictactoeFuncs.cpp"
#include <array>

std::string gameMode;
std::string difficulty;
bool settingsClicked = false, playClicked = false;
array<array<char, 3>,3> board = {{}};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->twoPlayerButton->setHidden(true);
    ui->vsCPUButton->setHidden(true);
    ui->playEasyCPUButton->setHidden(true);
    ui->playMediumCPUButton->setHidden(true);
    ui->playHardCPUButton->setHidden(true);
    ui->backButtonMenu->setHidden(true);
    ui->backButtonCPUselect->setHidden(true);    
}

MainWindow::~MainWindow()
{
    delete ui;
    if(boardWindow) delete boardWindow;
}

// Function that when called will hide the main menu and display the playing board
void MainWindow::showBoard(){

    if(!boardWindow){
        boardWindow = new boardwindow();

        connect(boardWindow, &boardwindow::backToMenu, this, &MainWindow::show);
    }

    boardWindow->show();
    this->hide();
}

/*
    Main Menu Buttons
*/

// Button that when pressed will display 2 player or vsCPU options
void MainWindow::on_playButton_clicked()
{
    ui->twoPlayerButton->setHidden(false);
    ui->vsCPUButton->setHidden(false);
    ui->backButtonMenu->setHidden(false);

    ui->playButton->setHidden(true);
    ui->settingsButton->setHidden(true);
    ui->exitButton->setHidden(true);

    playClicked = true;
}

// Button that when pressed will display settings available to the user
void MainWindow::on_settingsButton_clicked()
{
    ui->playButton->setHidden(true);
    ui->settingsButton->setHidden(true);
    ui->exitButton->setHidden(true);

    ui->backButtonMenu->setHidden(false);

    settingsClicked = true;
}

// Button that when pressed will close the program
void MainWindow::on_exitButton_clicked()
{
    close();
}

/*
    Play and Settings back button
*/
// Button that when pressed will leave the game select screen and show the main menu
void MainWindow::on_backButtonMenu_clicked()
{
    ui->playButton->setHidden(false);
    ui->settingsButton->setHidden(false);
    ui->exitButton->setHidden(false);

    if(playClicked == true)
    {
        ui->twoPlayerButton->setHidden(true);
        ui->vsCPUButton->setHidden(true);
        ui->backButtonMenu->setHidden(true);
        playClicked = false;
    }
    if(settingsClicked == true)
    {
        ui->backButtonMenu->setHidden(true);
        settingsClicked = false;
    }
}


/*
    vsCPU button choices and back display
*/

// Button that when pressed will display the three available options of vsCPU games
void MainWindow::on_vsCPUButton_clicked()
{
    ui->playEasyCPUButton->setHidden(false);
    ui->playMediumCPUButton->setHidden(false);
    ui->playHardCPUButton->setHidden(false);
    ui->backButtonCPUselect->setHidden(false);

    ui->twoPlayerButton->setHidden(true);
    ui->backButtonMenu->setHidden(true);
}

// Button that will back out from having chosen to play vsCPU games
void MainWindow::on_backButtonCPUselect_clicked()
{
    ui->playEasyCPUButton->setHidden(true);
    ui->playMediumCPUButton->setHidden(true);
    ui->playHardCPUButton->setHidden(true);
    ui->backButtonCPUselect->setHidden(true);

    ui->twoPlayerButton->setHidden(false);
    ui->backButtonMenu->setHidden(false);
}


/*
    Buttons that will start one of the four game types of tic-tac-toe
*/

// Button definition that will start a two player game
void MainWindow::on_twoPlayerButton_clicked()
{
    gameMode = "MULTIPLAYER";
    showBoard();
    boardWindow->clearBoardUI();
    boardWindow->setGameMode();
}

// Button definition that will start a vsCPU game on easy difficulty
void MainWindow::on_playEasyCPUButton_clicked()
{
    gameMode = "CPU";
    difficulty = "Easy";
    showBoard();
    boardWindow->clearBoardUI();
    boardWindow->setGameMode();
}

// Button definition that will start a vsCPU game on medium difficulty
void MainWindow::on_playMediumCPUButton_clicked()
{
    gameMode = "CPU";
    difficulty = "Medium";
    showBoard();
    boardWindow->clearBoardUI();
    boardWindow->setGameMode();
}

// Button definition that will start a vsCPU game on hard difficulty
void MainWindow::on_playHardCPUButton_clicked()
{
    gameMode = "CPU";
    difficulty = "Hard";
    showBoard();
    boardWindow->clearBoardUI();
    boardWindow->setGameMode();
}
