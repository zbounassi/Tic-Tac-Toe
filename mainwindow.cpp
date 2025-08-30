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
bool settingsClicked = false, playClicked = false, displayTracker = false;
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

    ui->fullscreenBox->setHidden(true);
    ui->fullscreenText->setHidden(true);
    ui->resolutionSettings->setHidden(true);
    ui->res800->setHidden(true);
    ui->res1280->setHidden(true);
    ui->res1920->setHidden(true);
    ui->themeSelect->setHidden(true);
    ui->darkMode->setHidden(true);
    ui->lightMode->setHidden(true);
    ui->trackerBox->setHidden(true);
    ui->trackerText->setHidden(true);

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
    ui->titleText->setHidden(true);

    ui->backButtonMenu->setHidden(false);

    settingsClicked = true;

    ui->fullscreenBox->setHidden(false);
    ui->fullscreenText->setHidden(false);
    ui->resolutionSettings->setHidden(false);
    ui->themeSelect->setHidden(false);
    ui->trackerBox->setHidden(false);
    ui->trackerText->setHidden(false);

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
        ui->titleText->setHidden(false);

        ui->fullscreenBox->setHidden(true);
        ui->fullscreenText->setHidden(true);
        ui->resolutionSettings->setHidden(true);
        ui->res800->setHidden(true);
        ui->res1280->setHidden(true);
        ui->res1920->setHidden(true);
        ui->themeSelect->setHidden(true);
        ui->darkMode->setHidden(true);
        ui->lightMode->setHidden(true);
        ui->trackerBox->setHidden(true);
        ui->trackerText->setHidden(true);

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


/*
    Functions that are connected to buttons and calls that are
    used in the repositioning and recentering of objects when
    the resolution of the screen is being adjusted
*/

/*
    Recieves input from the selected resolution option to resize the screen
    The largest resolution will move the window to the corner so that no
    portion of the screen is cutoff in the resize
*/
void MainWindow::resizeSelected()
{
    if(res == 800)
        this->resize(800, 600);
    else if(res == 1280)
        this->resize(1280, 720);
    else{
        this->resize(1920, 1000);
        this->move(0,0);
    }
}

/*
    If the boolean returns true, it should be fullscreen
    If the boolean is false it should be the chosen window size

    In order to implement this I need to find the command to set the
    window to a chosen size, starting with the command to go/remove fullscreen
*/
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

// Button to change to a darkMode theme
void MainWindow::on_darkMode_clicked()
{

}

// Button to change to a lightMode theme
void MainWindow::on_lightMode_clicked()
{

}

// Button that will change the resolution to 800x600 (if not already done)
void MainWindow::on_res800_clicked()
{
    if(res != 800)
        res = 800;
    if(!(ui->fullscreenBox->isChecked()))
        this->resizeSelected();
}

// Button that will change the resolution to 1280*720 (if not already done)
void MainWindow::on_res1280_clicked()
{
    if(res != 1280)
        res = 1280;
    if(!(ui->fullscreenBox->isChecked()))
        this->resizeSelected();
}

// Button that will change the resolution to 1920*1000 (if not already done)
// 1000 is done in place of 1080 to account for the taskbar cutting off part of the window
void MainWindow::on_res1920_clicked()
{
    if(res != 1920)
        res = 1920;

    if(!(ui->fullscreenBox->isChecked()))
        this->resizeSelected();
}

// Overriden definition of resizeEvent to allow for the movement of buttons when the window resizes
void MainWindow::resizeEvent(QResizeEvent *event){
    QMainWindow::resizeEvent(event);

    repositionButtons();
}

// Function definition that will ensure all buttons are in their intended location regardless of the resolution choice
void MainWindow::repositionButtons()
{
    repositionMenuButtons();
    repositionPlayButtons();
    repositionSettingsButtons();
}

void MainWindow::repositionMenuButtons()
{
    int x = (this->width() - ui->titleText->width()) / 2;
    int y = (this->height() - ui->titleText->height()) / 2;

    int centering = ui->titleText->width() / 3 + 15;
    int heightDrop = ui->titleText->height();

    ui->titleText->move(x, y - (heightDrop/2));

    if(y <= 800){
        ui->playButton->move(x+centering, y + (heightDrop/2));
        ui->settingsButton->move(x+ centering, y + heightDrop);
        ui->exitButton->move(x+centering, y + (3 * heightDrop / 2));
    }
    else {
        ui->playButton->move(x + centering, y + heightDrop);
        ui->settingsButton->move(x + centering, y + (3*heightDrop/2));
        ui->exitButton->move(x + centering, y + (2*heightDrop));
    }
}

void MainWindow::repositionPlayButtons()
{
    ui->backButtonCPUselect->move(ui->exitButton->pos());
    ui->backButtonMenu->move(ui->exitButton->pos());
    ui->twoPlayerButton->move(ui->playButton->pos());
    ui->vsCPUButton->move(ui->settingsButton->pos());

    QPoint pos = ui->twoPlayerButton->pos();
    int spacing = (ui->vsCPUButton->width()) * 2;

    ui->playEasyCPUButton->move(pos.x() + spacing, pos.y());

    pos = ui->vsCPUButton->pos();

    ui->playMediumCPUButton->move(pos.x() + spacing, pos.y());

    pos = ui->backButtonCPUselect->pos();

    ui->playHardCPUButton->move(pos.x() + spacing, pos.y());
}

void MainWindow::repositionSettingsButtons()
{
    int x = (this->width() / 12);
    int y = (this->height() / 8);

    int spacing = ui->fullscreenText->width();
    int boxHt = (ui->fullscreenBox->height()/2);

    ui->fullscreenText->move(x, y - boxHt);
    ui->fullscreenBox->move(x + spacing + 10, y);

    ui->resolutionSettings->move(x, y * 2);
    ui->themeSelect->move(x, y * 3);

    spacing = ui->fullscreenText->width();
    boxHt = (ui->fullscreenBox->height() / 2);

    ui->trackerText->move(x, y * 4 - boxHt);
    ui->trackerBox->move(x + spacing + 75, y*4);

    spacing = ui->resolutionSettings->width() + 20;

    ui->res800->move(2 * x + spacing, y * 2);
    ui->res1280->move(3 * x + spacing, y * 2);
    ui->res1920->move(4 * x + spacing, y * 2);

    ui->darkMode->move(2 * x + spacing, y * 3);
    ui->lightMode->move(3 * x + spacing, y * 3);

}

void MainWindow::on_resolutionSettings_clicked()
{
    if(ui->res800->isHidden()){
        ui->res800->setHidden(false);
        ui->res1280->setHidden(false);
        ui->res1920->setHidden(false);
    }
    else{
        ui->res800->setHidden(true);
        ui->res1280->setHidden(true);
        ui->res1920->setHidden(true);
    }
    ui->darkMode->setHidden(true);
    ui->lightMode->setHidden(true);
}




void MainWindow::on_themeSelect_clicked()
{
    if(ui->darkMode->isHidden()){
        ui->darkMode->setHidden(false);
        ui->lightMode->setHidden(false);
    }
    else{
        ui->darkMode->setHidden(true);
        ui->lightMode->setHidden(true);
    }

    ui->res800->setHidden(true);
    ui->res1280->setHidden(true);
    ui->res1920->setHidden(true);
}


void MainWindow::on_trackerBox_clicked()
{
    if(ui->trackerBox->isChecked() == true)
        displayTracker = true;
    else
        displayTracker = false;
}

