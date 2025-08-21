#ifndef TICTACTOEFUNCS_H
#define TICTACTOEFUNCS_H

#include<array>
using namespace std;

// Used to ensure the board is consisted of 3 rows and 3 columns
constexpr int ROWS = 3;
constexpr int COLS = 3;

void resetCounters();
bool isPlayerTurn(int turn, char player);
void printNumberedBoard();
void clearBoard(array<array<char, ROWS>, COLS>&board);
bool checkPlayerWinSolo(array<array<char,ROWS>,COLS>&board, char player);
bool checkPlayerWinMP(array<array<char, ROWS>, COLS>& board, char player) ;
bool cpuCheckWin(array<array<char, ROWS>, COLS>&board, char player);
bool cpuWinCheck (array<array<char, ROWS>, COLS>& board, char player);
int cornerOpen(array<array<char, ROWS>, COLS>&board);
bool spaceOverOpen(array<array<char, ROWS>, COLS>&board);
int findWinningMove(array<array<char, ROWS>, COLS>&board, char cpu);
int findBlockingMove(array<array<char, ROWS>, COLS>&board, char player);
int takeCenter(array<array<char, ROWS>, COLS>&board);
int cpuMoveEasy();
int cpuMoveMedium(array<array<char, ROWS>, COLS>&board, char cpu, char player);
int cpuMoveHard(array<array<char, ROWS>, COLS>&board, char cpu, char player, int turn);
void playTicTacToe(array<array<char, ROWS>, COLS>&board);
void playTicTacToeCPUEasy(array<array<char, ROWS>, COLS>&board);
void playTicTacToeCPUMedium(array<array<char, ROWS>, COLS>&board);
void playTicTacToeCPUHard(array<array<char, ROWS>, COLS>&board);

#endif // TICTACTOEFUNCS_H
