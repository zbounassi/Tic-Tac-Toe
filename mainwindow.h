#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "boardwindow.h"
#include <QMainWindow>

/*
    All functions are in the same order that they appear in
    mainwindow.cpp. There are line breaks to show where
    the functions are separted into blocks in the .cpp file.
*/

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
    void resetMenu();

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void showBoard();

    void on_playButton_clicked();
    void on_settingsButton_clicked();
    void on_exitButton_clicked();

    void on_backButtonMenu_clicked();

    void on_vsCPUButton_clicked();
    void on_backButtonCPUselect_clicked();

    void on_twoPlayerButton_clicked();
    void on_playEasyCPUButton_clicked();
    void on_playMediumCPUButton_clicked();
    void on_playHardCPUButton_clicked();

    void resizeSelected();
    void on_fullscreenBox_clicked();

    void on_darkMode_clicked();
    void on_lightMode_clicked();

    void on_res800_clicked();
    void on_res1280_clicked();
    void on_res1920_clicked();

    void repositionButtons();
    void repositionMenuButtons();
    void repositionPlayButtons();
    void repositionSettingsButtons();

    void on_resolutionSettings_clicked();

    void on_themeSelect_clicked();

    void on_trackerBox_clicked();

private:
    Ui::MainWindow *ui;
    boardwindow *boardWindow = nullptr;
};


#endif // MAINWINDOW_H
