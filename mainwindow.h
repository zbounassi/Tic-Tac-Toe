#ifndef MAINWINDOW_H
#define MAINWINDOW_H

<<<<<<< HEAD
#include "boardwindow.h"
=======
>>>>>>> 838665d9016d793fa8e5a8c919e1e5de8db431cf
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
    void on_playButton_clicked();

    void on_settingsButton_clicked();

    void on_exitButton_clicked();

    void on_twoPlayerButton_clicked();

    void on_backButtonMenu_clicked();

    void on_vsCPUButton_clicked();

    void on_backButtonCPUselect_clicked();

    void on_playEasyCPUButton_clicked();

    void on_playMediumCPUButton_clicked();

    void on_playHardCPUButton_clicked();

private:
    Ui::MainWindow *ui;
<<<<<<< HEAD
    boardwindow *boardWindow = nullptr;
=======
>>>>>>> 838665d9016d793fa8e5a8c919e1e5de8db431cf
};


#endif // MAINWINDOW_H
