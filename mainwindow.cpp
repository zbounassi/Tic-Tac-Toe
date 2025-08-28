#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tictactoeFuncs.cpp"
#include <array>

#include <QStyle>
#include <QScreen>
#include <QGuiApplication>
#include <QResizeEvent>
#include <QApplication>
#include <QPalette>

int res;
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

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();

    this->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            screenGeometry
        )
    );
}


MainWindow::~MainWindow()
{
    delete ui;
    if(boardWindow) delete boardWindow;
}

// Function that when called will hide the main menu and display the playing board
// Will also reset the main menu for once the game(s) are complete
void MainWindow::showBoard(){

    if(!boardWindow){
        boardWindow = new boardwindow();

        connect(boardWindow, &boardwindow::backToMenu, this, &MainWindow::show);
    }

    boardWindow->show();
    this->resetMenu();
    this->hide();
}

// Used once a game is done to reset the main menu back to its original state
void MainWindow::resetMenu(){

    ui->playButton->setHidden(false);
    ui->settingsButton->setHidden(false);
    ui->exitButton->setHidden(false);

    ui->twoPlayerButton->setHidden(true);
    ui->vsCPUButton->setHidden(true);
    ui->playEasyCPUButton->setHidden(true);
    ui->playMediumCPUButton->setHidden(true);
    ui->playHardCPUButton->setHidden(true);
    ui->backButtonMenu->setHidden(true);
    ui->backButtonCPUselect->setHidden(true);
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
    QPoint pos = ui->playButton->pos();

    int x = pos.x();
    int y = pos.y();

    ui->playEasyCPUButton->move(x + 60, y - 40);
    ui->playMediumCPUButton->move(x + 60, y);
    ui->playHardCPUButton->move(x + 60, y + 80);

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


/*
    Functions that are connected to buttons and calls that are
    used in the repositioning and recentering of objects when
    the resolution of the screen is being adjusted
*/

void MainWindow::resizeSelected()
{
    if(res == 800)
        this->resize(800, 600);
    else if(res == 1280)
        this->resize(1280, 720);
    else
        this->resize(1920, 1080);
}

// If the boolean returns true, it should be fullscreen
// If the boolean is false it should be the chosen window size

// In order to implement this I need to find the command to set the
// window to a chosen size, starting with the command to go/remove fullscreen
void MainWindow::on_fullscreenBox_clicked()
{
    if(ui->fullscreenBox->isChecked() == true)
        this->setWindowState(Qt::WindowFullScreen);
    else{
        this->setWindowState(Qt::WindowNoState);
        resizeSelected(); // need to define this
    }
    this->show();
}


void MainWindow::on_darkMode_clicked()
{

}


void MainWindow::on_lightMode_clicked()
{

}


void MainWindow::on_res800_clicked()
{
    if(res != 800)
        res = 800;
    if(!(ui->fullscreenBox->isChecked()))
        this->resizeSelected();
}


void MainWindow::on_res1280_clicked()
{
    if(res != 1280)
        res = 1280;
    if(!(ui->fullscreenBox->isChecked()))
        this->resizeSelected();
}


void MainWindow::on_res1920_clicked()
{
    if(res != 1920)
        res = 1920;

    if(!(ui->fullscreenBox->isChecked()))
        this->resizeSelected();
}

void MainWindow::resizeEvent(QResizeEvent *event){
    QMainWindow::resizeEvent(event);

    recenterButtons();
}

void MainWindow::recenterButtons()
{

    int x = (this->width() - ui->titleText->width()) / 2;
    int y = (this->height() - ui->titleText->height()) / 2;

    int centering = ui->titleText->width() / 3 + 15;
    int heightDrop = ui->titleText->height();

    ui->titleText->move(x, y);
    ui->playButton->move(x + centering, y + heightDrop + 20);
    ui->settingsButton->move(x + centering, y + (heightDrop * 2 - 10));
    ui->exitButton->move(x + centering, y + (heightDrop * 5 / 2));

    ui->backButtonCPUselect->move(ui->exitButton->pos());
    ui->backButtonMenu->move(ui->exitButton->pos());
    ui->twoPlayerButton->move(ui->playButton->pos());
    ui->vsCPUButton->move(ui->settingsButton->pos());
}
