#ifndef BOARDWINDOW_H
#define BOARDWINDOW_H

#include <QWidget>
#include <array>

struct gameState {
    char board[9] = {};
    char player;
    char cpu;
    char currentPlayer;
    int turn = 1;
    bool playerTurn = false;
    bool cpuTurn = false;
    bool won = false;
};

namespace Ui {
class boardwindow;
}

class boardwindow : public QWidget
{
    Q_OBJECT

public:
    explicit boardwindow(QWidget *parent = nullptr);
    ~boardwindow();
    void clearBoardUI();
    void showChoices();

private slots:

    void hideChoices();
    void showPlayArea();

    bool legalMoveCheck(int pos);
    std::string getPlayer();

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

    void setArea(int);

    void endGame();
    void playerTurn();
    void cpuTurn();
    bool checkWinner();

    void resetBoxes();


signals:
    void backToMenu();

private:
    Ui::boardwindow *ui;
    std::array<std::array<char, 3>, 3> board = {{}};
    gameState game;
};

#endif // BOARDWINDOW_H
