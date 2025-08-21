#include "boardwindow.h"
#include "ui_boardwindow.h"

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
}

boardwindow::~boardwindow()
{
    delete ui;
}


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

