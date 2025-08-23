#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tictactoeFuncs.cpp"
#include <array>

bool settingsClicked = false, playClicked = false;
array<array<char, ROWS>,COLS> board = {{}};

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

void MainWindow::showBoard(){

    if(!boardWindow){
        boardWindow = new boardwindow();

        connect(boardWindow, &boardwindow::backToMenu, this, &MainWindow::show);
    }

    boardWindow->show();
    this->hide();
}

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


void MainWindow::on_settingsButton_clicked()
{
    ui->playButton->setHidden(true);
    ui->settingsButton->setHidden(true);
    ui->exitButton->setHidden(true);

    ui->backButtonMenu->setHidden(false);

    settingsClicked = true;
}

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

void MainWindow::on_exitButton_clicked()
{
    close();
}

void MainWindow::on_vsCPUButton_clicked()
{
    ui->playEasyCPUButton->setHidden(false);
    ui->playMediumCPUButton->setHidden(false);
    ui->playHardCPUButton->setHidden(false);
    ui->backButtonCPUselect->setHidden(false);

    ui->twoPlayerButton->setHidden(true);
    ui->backButtonMenu->setHidden(true);
}

void MainWindow::on_backButtonCPUselect_clicked()
{
    ui->playEasyCPUButton->setHidden(true);
    ui->playMediumCPUButton->setHidden(true);
    ui->playHardCPUButton->setHidden(true);
    ui->backButtonCPUselect->setHidden(true);

    ui->twoPlayerButton->setHidden(false);
    ui->backButtonMenu->setHidden(false);
}

void MainWindow::on_twoPlayerButton_clicked()
{
    playTicTacToe(board);
}


void MainWindow::on_playEasyCPUButton_clicked()
{
    showBoard();
    boardWindow->clearBoardUI();
    boardWindow->showChoices();
}


void MainWindow::on_playMediumCPUButton_clicked()
{
    playTicTacToeCPUMedium(board);
}


void MainWindow::on_playHardCPUButton_clicked()
{
    playTicTacToeCPUHard(board);
}
