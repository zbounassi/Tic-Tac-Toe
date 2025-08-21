#ifndef BOARDWINDOW_H
#define BOARDWINDOW_H

#include <QWidget>

namespace Ui {
class boardwindow;
}

class boardwindow : public QWidget
{
    Q_OBJECT

public:
    explicit boardwindow(QWidget *parent = nullptr);
    ~boardwindow();

private slots:

    void hideChoices();

    void showPlayArea();

    void playCPUEasy(std::string order);

    void on_area1_clicked();
    void on_area2_clicked();
    void on_area3_clicked();
    void on_area4_clicked();
    void on_area5_clicked();
    void on_area6_clicked();
    void on_area7_clicked();
    void on_area8_clicked();
    void on_area9_clicked();

    void on_gameExitConfirm_clicked();

    void on_gameExitDeny_clicked();

    void on_gameExitButton_clicked();

    void on_closeProgram_clicked();

    void on_menuExit_clicked();

    void on_goFirst_clicked();

    void on_goSecond_clicked();


    void on_replayConfirm_clicked();

signals:
    void backToMenu();

private:
    Ui::boardwindow *ui;
};

#endif // BOARDWINDOW_H
