#ifndef BOARDWINDOW_H
#define BOARDWINDOW_H

#include <QWidget>
#include <array>

/*
    All functions are in the same order that they appear in
    boardwindow.cpp. The functions in the public area are split from
    the rest. Those in the private area have line breaks to show where
    the functions are separted into blocks in the .cpp file.
*/
struct gameState {
    char player;
    char cpu;
    char currentPlayer;
    int turn = 1;
    bool playerTurn = false;
    bool cpuTurn = false;
    bool won = false;
    std::string mode = " ";
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
    void setGameMode();
    void showChoices();
    void clearBoardUI();
    void hidePlayArea();
    void mpTurn();

protected:
    // void resizeEvent(QResizeEvent *event) override;

private slots:

    void hideChoices();
    void showPlayArea();
    void resetBoxes();
    void setArea(int);

    void playerTurn();
    int getDifficulty();
    void cpuTurn();
    void on_area1_clicked();
    void on_area2_clicked();
    void on_area3_clicked();
    void on_area4_clicked();
    void on_area5_clicked();
    void on_area6_clicked();
    void on_area7_clicked();
    void on_area8_clicked();
    void on_area9_clicked();
    bool legalMoveCheck(int pos);

    void endGame();
    std::string getPlayer();
    bool checkWinner();
    bool boardFull();

    void on_goFirst_clicked();
    void on_goSecond_clicked();

    void on_replayConfirm_clicked();
    void on_replayDeny_clicked();

    void on_gameExitButton_clicked();
    void on_gameExitConfirm_clicked();
    void on_gameExitDeny_clicked();
    void on_closeProgram_clicked();
    void on_menuExit_clicked();

    // void centerBoard();
    void showWinTracker();
    void clearTrackers();

    void getPlayerNames();
    void on_nameConfirm_clicked();

    void on_performChange_clicked();
    void on_doNotChange_clicked();
    void changeSidesOffer();

signals:
    void backToMenu();

private:
    Ui::boardwindow *ui;
    std::array<std::array<char, 3>, 3> board = {{}};
    gameState game;
};

#endif // BOARDWINDOW_H
