#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "boardwindow.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showBoard();

    void on_twoPlayerButton_clicked();

    void on_playEasyCPUButton_clicked();

    void on_playMediumCPUButton_clicked();

    void on_playHardCPUButton_clicked();

    void on_playButton_clicked();

    void on_settingsButton_clicked();

    void on_exitButton_clicked();

    void on_backButtonMenu_clicked();

    void on_vsCPUButton_clicked();

    void on_backButtonCPUselect_clicked();


private:
    Ui::MainWindow *ui;
    boardwindow *boardWindow = nullptr;
};


#endif // MAINWINDOW_H
