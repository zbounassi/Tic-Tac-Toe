#include <iostream>
#include<array>
#include<iomanip>
using namespace std;

// Used to ensure the board is consisted of 3 rows and 3 columns
constexpr int ROWS = 3;
constexpr int COLS = 3;

// Used to hold information of winnings across successive playthroughs of the modes
static int playerWins = 0;
static int cpuWins = 0;
static int mpP1Wins = 0;
static int mpP2Wins = 0;
static int draws = 0;
static int gamesPlayed = 0;


// Used to calculate the next move taken by the CPU on Hard difficulty
static int cpuLastPos;

// Used to reset all win counters to 0
void resetCounters() {
    playerWins = 0;
    cpuWins = 0;
    mpP1Wins = 0;
    mpP2Wins = 0;
    draws = 0;
    gamesPlayed = 0;
};

// Determining if its the player's or the CPU's turn
bool isPlayerTurn(int turn, char player) {
    if((player == 'X' && turn % 2 != 0) || (player == 'O' && turn % 2 == 0))
        return true;
    else
        return false;
};

// Used to inform players of the spaces in a simplified manner
void printNumberedBoard() {
    cout << "These are corresponding numbers to the corresponding spaces. Have fun!\n\n";
    cout << setw(18) << "   1\t|   2\t|   3" << endl;
    cout << setw(24) << " ----------------------" << endl;
    cout << setw(18) << "   4\t|   5\t|   6" << endl;
    cout << setw(24) << " ----------------------" << endl;
    cout << setw(18) << "   7\t|   8\t|   9";
};

// Prints the board while players are in the game
void printPlayingBoard(array<array<char,ROWS>,COLS>&board){
    cout << endl << endl;
    printf("     %c\t|   %c\t|   %c\n", board[0][0], board[0][1], board[0][2]);
    cout << setw(24) << " ----------------------" << endl;
    printf("     %c\t|   %c\t|   %c\n", board[1][0], board[1][1], board[1][2]);
    cout << setw(24) << " ----------------------" << endl;
    printf("     %c\t|   %c\t|   %c\n", board[2][0], board[2][1], board[2][2]);
};

// Used to reset the board, so that each game starts off with a blank playable board
void clearBoard(array<array<char, ROWS>, COLS>&board){
    board = { {} };
};

// Checks to see the player has gotten Tic-Tac-Toe against the CPU
bool checkPlayerWinSolo(array<array<char,ROWS>,COLS>&board, char player) {

    //check rows and cols
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            cout << "\nPlayer " << ((player == 'X') ? 1 : 2) << " has won the game!";
            playerWins++;
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            cout << "\nPlayer " << ((player == 'X') ? 1 : 2) << " has won the game!";
            playerWins++;
            return true;
        }
    }

    //check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        cout << "\nPlayer " << ((player == 'X') ? 1 : 2) << " has won the game!";
        playerWins++;
        return true;
    }
    if (board[2][0] == player && board[1][1] == player && board[0][2] == player) {
        cout << "\nPlayer " << ((player == 'X') ? 1 : 2) << " has won the game!";
        playerWins++;
        return true;
    }

    //false if none are true
    return false;
};


// Checks to see if any player has gotten Tic-Tac-Toe and will announce the winner, if there is one
bool checkPlayerWinMP(array<array<char, ROWS>, COLS>& board, char player) {

    //check rows and cols
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            cout << "\nPlayer " << ((player == 'X') ? 1 : 2) << " has won the game!";
            if (player == 'X')
                mpP1Wins++;
            else
                mpP2Wins++;
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            cout << "\nPlayer " << ((player == 'X') ? 1 : 2) << " has won the game!";
            if (player == 'X')
                mpP1Wins++;
            else
                mpP2Wins++;
            return true;
        }
    }

    //check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        cout << "\nPlayer " << ((player == 'X') ? 1 : 2) << " has won the game!";
        if (player == 'X')
            mpP1Wins++;
        else
            mpP2Wins++;
        return true;
    }
    if (board[2][0] == player && board[1][1] == player && board[0][2] == player) {
        cout << "\nPlayer " << ((player == 'X') ? 1 : 2) << " has won the game!";
        if (player == 'X')
            mpP1Wins++;
        else
            mpP2Wins++;
        return true;
    }

    //false if none are true
    return false;
};


// CPU checks to see any spaces where the opponent can fulfill Tic-Tac-Toe
bool cpuCheckWin(array<array<char, ROWS>, COLS>&board, char player) {

    //check rows and cols
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }

    //check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[2][0] == player && board[1][1] == player && board[0][2] == player) return true;

    //false if none are true
    return false;
};

// Checking to see if the CPU has won the game
bool cpuWinCheck (array<array<char, ROWS>, COLS>& board, char player) {

    //check rows and cols
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            cpuWins++;
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            cpuWins++;
            return true;
        }
    }

    //check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        cpuWins++;
        return true;
    }
    if (board[2][0] == player && board[1][1] == player && board[0][2] == player) {
        cpuWins++;
        return true;
    }

    //false if none are true
    return false;
};

// CPU checks if the corners are open to be played in
int cornerOpen(array<array<char, ROWS>, COLS>&board) {
    int val = -1;
    if (board[0][0] != 'X' && board[0][0] != 'O')
        val = 1;
    else if (board[0][2] != 'X' && board[0][2] != 'O')
        val = 3;
    else if (board[2][0] != 'X' && board[2][0] != 'O')
        val = 7;
    else if (board[2][2] != 'X' && board[2][2] != 'O')
        val = 9;
    return(val);
};

// CPU checks if there is a space available next to its prior move to be made
bool spaceOverOpen(array<array<char, ROWS>, COLS>&board) {
    int playedRow, playedCol, row, col;
    bool found = false;

    playedRow = (cpuLastPos - 1) / 3;
    playedCol = (cpuLastPos - 1) % 3;

    int rowChange[] = { -1,-1, -1, 0, 0, 1, 1 ,1 };
    int colChange[] = { -1, 0,  1,-1, 1,-1, 0 ,1 };

    for (int i = 0; i < 8 && !found; i++) {
        row = playedRow + rowChange[i];
        col = playedCol + colChange[i];

        if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
            if (board[row][col] != 'X' && board[row][col] != 'O') {
                cpuLastPos = (row * 3) + col + 1;
                cout << "\nThis may be an issue: " << cpuLastPos << endl;
                found = true;
            }
        }
    }
    return(found);
};

// CPU checks if there is a move that wins the game
int findWinningMove(array<array<char, ROWS>, COLS>&board, char cpu) {
    int position = -1, row, col;
    bool moveFound = false;
    array < array<char, ROWS>, COLS> testBoard = board;
    for (int i = 1; i <= 9 && !moveFound; i++) {
        testBoard = board;
        row = (i - 1) / 3;
        col = (i - 1) % 3;
        if (testBoard[row][col] != 'X' && testBoard[row][col] != 'O') {
            testBoard[row][col] = cpu;
            if (cpuCheckWin(testBoard, cpu) == true) {
                position = i;
                moveFound = true;
            }
        }
    }
    return(position);
};

// CPU checks if the opponent has a move that wins the game
int findBlockingMove(array<array<char, ROWS>, COLS>&board, char player){
    int position = -1, row, col;
    bool moveFound = false;
    array < array<char, ROWS>, COLS> testBoard = board;
    for (int i = 1; i <= 9 && !moveFound; i++) {
        testBoard = board;
        row = (i - 1) / 3;
        col = (i - 1) % 3;
        if (testBoard[row][col] != 'X' && testBoard[row][col] != 'O') {
            testBoard[row][col] = player;
            if (cpuCheckWin(testBoard, player) == true) {
                position = i;
                moveFound = true;
            }
        }
    }
    return(position);
};

// CPU takes the center if it sees no better move
int takeCenter(array<array<char, ROWS>, COLS>&board) {
    if (board[1][1] != 'X' && board[1][1] != 'O')
        return 5;
    return -1;
};

// Randomly generated move, the easiest difficulty level
int cpuMoveEasy() {
    return(rand() % 9 + 1);
};

// Move may be randomly generated or worked to win/block a win, the medium level of difficulty
int cpuMoveMedium(array<array<char, ROWS>, COLS>&board, char cpu, char player) {
    int scale, position = -1, row, col;
    bool moveFound = false;
    array < array<char, ROWS>, COLS> testBoard = board;
    scale = rand() % 5;
    if(scale <= 2) {
        for (int i = 1; i <= 9 && !moveFound; i++) {
            testBoard = board;
            row = (i - 1) / 3;
            col = (i - 1) % 3;
            if (testBoard[row][col] != 'X' && testBoard[row][col] != 'O'){
                testBoard[row][col] = cpu;
                if (cpuCheckWin(testBoard, cpu) == true) {
                    position = i;
                    moveFound = true;
                }
            }
            else if (testBoard[row][col] != 'X' && testBoard[row][col] != 'O') {
                testBoard[row][col] = player;
                if (cpuCheckWin(testBoard, player) == true) {
                    position = i;
                    moveFound = true;
                }
            }
        }
    }
    else
        position = cpuMoveEasy();

    return(position);
};

// Move is given a list to "think" through, the hardest level of difficulty
int cpuMoveHard(array<array<char, ROWS>, COLS>&board, char cpu, char player, int turn) {

    int centerMov, cornerMov;

    int winMov = findWinningMove(board, cpu);
    if (winMov != -1)
        return winMov;

    int blockMov = findBlockingMove(board, player);
    if (blockMov != -1)
        return blockMov;

    if (turn % 2 == 0) {
        centerMov = takeCenter(board);
        if (centerMov != -1)
            return centerMov;

        cornerMov = cornerOpen(board);
        if (cornerMov != -1)
            return cornerMov;
    }
    else {
        if (turn > 3) {
            centerMov = takeCenter(board);
            if (centerMov != -1)
                return centerMov;
        }
        else {
            cornerMov = cornerOpen(board);
            if (cornerMov != -1)
                return cornerMov;

            centerMov = takeCenter(board);
            if (centerMov != -1)
                return centerMov;
        }
    }

    cornerMov = cornerOpen(board);
    if (cornerMov != -1)
        return cornerMov;

    centerMov = takeCenter(board);
    if (centerMov != -1)
        return centerMov;


    int position = cpuMoveEasy();

    return(position);
};

// Calls all functions to be capable of playing Tic-Tac-Toe with someone else
void playTicTacToe(array<array<char, ROWS>, COLS>&board) {

    printNumberedBoard();

    bool won = false;
    char player1 = 'X', player2 = 'O', crtPlayer;
    int turn = 1, position = -1, row, col;
    string playAgain;

    while (!won && turn <= 9) {

        while (true) {

            if (turn % 2 != 0)
                crtPlayer = player1;
            else
                crtPlayer = player2;

            cout << "\n\nPlayer " << ((crtPlayer == 'X') ? 1 : 2)
                 << " select a square to play in (1 - 9): ";
            cin >> position;

            row = (position - 1) / 3;
            col = (position - 1) % 3;

            if (position >= 1 && position <= 9 &&
                board[row][col] != 'X' && board[row][col] != 'O') {
                board[row][col] = crtPlayer;
                turn++;

                printPlayingBoard(board);

                if (turn >= 5)
                    won = checkPlayerWinMP(board, crtPlayer);

                break;
            }
            else
                cout << "The selected square is invalid. Please try again.";
        }
    }
    if (gamesPlayed >= 1)
        cout << "\nCurrent Scores:\nPlayer 1: " << mpP1Wins << "\tPlayer 2: " << mpP2Wins << "\t\tDraws: " << draws;

    cout << "\nWould you like to play this mode again? ";
    cin >> playAgain;

    while (playAgain != "Yes" && playAgain != "yes" && playAgain != "No" && playAgain != "no") {
        cout << "\nInvalid response entered, please try again: ";
        cin >> playAgain;
    }
    if (playAgain == "Yes" || playAgain == "yes") {
        gamesPlayed++;
        clearBoard(board);
        playTicTacToe(board);
    }
    else
        resetCounters();
}

// Play vs CPU on the Easy difficulty
void playTicTacToeCPUEasy(array<array<char, ROWS>, COLS>&board) {

    bool won = false, playerTurn, cpuShow = false;
    char player, cpu;
    string playAgain;
    int turn = 1, position = -1, row, col, playOrder;

    printNumberedBoard();

    cout << "\n\nWould you like to go first or second (enter a 1 or 2): ";
    cin >> playOrder;

    while (playOrder != 1 && playOrder != 2) {
        cout << "\nInvalid turn choice. Please try again: ";
        cin >> playOrder;
    }

    if (playOrder == 1) {
        player = 'X';
        cpu = 'O';
    }
    else {
        player = 'O';
        cpu = 'X';
    }

    while (!won && turn <= 9) {

        while (true) {

            playerTurn = isPlayerTurn(turn, player);

            if (playerTurn)
                cout << "\nPlayer please select a square to play in (1 - 9): ";
            else if (!cpuShow)
                cout << "\nThe CPU is calculating...";

            if (playerTurn)
                cin >> position;
            else {
                position = cpuMoveEasy();
                cpuShow = true;
            }

            row = (position - 1) / 3;
            col = (position - 1) % 3;

            if (position >= 1 && position <= 9 && board[row][col] != 'X' && board[row][col] != 'O') {
                if (playerTurn)
                    board[row][col] = player;
                else {
                    board[row][col] = cpu;
                    cpuShow = false;
                }
                turn++;

                printPlayingBoard(board);

                if (turn >= 5 && playerTurn)
                    won = checkPlayerWinSolo(board, player);
                else
                    won = cpuWinCheck(board, cpu);
                break;
            }
            else
                if (playerTurn)
                    cout << "The selected square is invalid. Please try again.";
        }
    }
    if (won == false) {
        cout << "\nThe game has ended in a draw!";
        draws++;
    }

    if (gamesPlayed >= 1)
        cout << "\nCurrent Scores:\nPlayer: " << playerWins << "\tCPU: " << cpuWins << "\t\tDraws: " << draws;

    cout << "\nWould you like to play this mode again? ";
    cin >> playAgain;

    while (playAgain != "Yes" && playAgain != "yes" && playAgain != "No" && playAgain != "no") {
        cout << "\nInvalid response entered, please try again: ";
        cin >> playAgain;
    }
    if (playAgain == "Yes" || playAgain == "yes") {
        gamesPlayed++;
        clearBoard(board);
        playTicTacToeCPUEasy(board);
    }
    else
        resetCounters();
};

// Play vs CPU on the Medium difficulty
void playTicTacToeCPUMedium(array<array<char, ROWS>, COLS>&board) {

    bool won = false, playerTurn, cpuShow = false;
    char player, cpu;
    string playAgain;
    int turn = 1, position = -1, row, col, playOrder;

    printNumberedBoard();

    cout << "\n\nWould you like to go first or second (enter a 1 or 2): ";
    cin >> playOrder;

    while (playOrder != 1 && playOrder != 2) {
        cout << "\nInvalid turn choice. Please try again: ";
        cin >> playOrder;
    }

    if (playOrder == 1) {
        player = 'X';
        cpu = 'O';
    }
    else{
        player = 'O';
        cpu = 'X';
    }

    while (!won && turn <= 9) {

        while (true) {

            playerTurn = isPlayerTurn(turn, player);

            if (playerTurn)
                cout << "\nPlayer please select a square to play in (1 - 9): ";
            else if (!cpuShow)
                cout << "\nThe CPU is calculating...";

            if (playerTurn)
                cin >> position;
            else {
                position = cpuMoveMedium(board, cpu, player);
                cpuShow = true;
            }

            row = (position - 1) / 3;
            col = (position - 1) % 3;

            if (position >= 1 && position <= 9 && board[row][col] != 'X' && board[row][col] != 'O') {
                if (playerTurn)
                    board[row][col] = player;
                else {
                    board[row][col] = cpu;
                    cpuShow = false;
                }

                turn++;
                printPlayingBoard(board);

                if (turn >= 5 && playerTurn)
                    won = checkPlayerWinSolo(board, player);
                else
                    won = cpuWinCheck(board, cpu);
                break;
            }
            else
                if (playerTurn)
                    cout << "The selected square is invalid. Please try again.";
        }
    }
    if (won == false) {
        cout << "\nThe game has ended in a draw!";
        draws++;
    }

    if (gamesPlayed >= 1)
        cout << "\nCurrent Scores:\nPlayer: " << playerWins << "\tCPU: " << cpuWins << "\t\tDraws: " << draws;

    cout << "\nWould you like to play this mode again? ";
    cin >> playAgain;

    while (playAgain != "Yes" && playAgain != "yes" && playAgain != "No" && playAgain != "no") {
        cout << "\nInvalid response entered, please try again: ";
        cin >> playAgain;
    }
    if (playAgain == "Yes" || playAgain == "yes") {
        gamesPlayed++;
        clearBoard(board);
        playTicTacToeCPUMedium(board);
    }
    else
        resetCounters();
};

// Play vs CPU on the Hard difficulty
void playTicTacToeCPUHard(array<array<char, ROWS>, COLS>&board) {

    bool won = false, playerTurn = false, cpuShow = false;
    char player, cpu;
    string playAgain;
    int turn = 1, position = -1, row, col, playOrder;

    printNumberedBoard();

    cout << "\n\nWould you like to go first or second (enter a 1 or 2): ";
    cin >> playOrder;

    while (playOrder != 1 && playOrder != 2) {
        cout << "\nInvalid turn choice. Please try again: ";
        cin >> playOrder;
    }

    if (playOrder == 1) {
        player = 'X';
        cpu = 'O';
    }
    else {
        player = 'O';
        cpu = 'X';
    }

    while (!won && turn <= 9) {

        while (true) {

            playerTurn = isPlayerTurn(turn, player);

            if (playerTurn)
                cout << "\nPlayer please select a square to play in (1 - 9): ";
            else if (!cpuShow)
                cout << "\nThe CPU is calculating...";

            if (playerTurn)
                cin >> position;
            else
            {
                position = cpuMoveHard(board, cpu, player, turn);
                cpuLastPos = position;
                cpuShow = true;
            }

            row = (position - 1) / 3;
            col = (position - 1) % 3;

            if (position >= 1 && position <= 9 && board[row][col] != 'X' && board[row][col] != 'O') {
                if (playerTurn)
                    board[row][col] = player;
                else {
                    board[row][col] = cpu;
                    cpuShow = false;
                }
                turn++;
                printPlayingBoard(board);

                if (turn >= 5 && playerTurn)
                    won = checkPlayerWinSolo(board, player);
                else
                    won = cpuWinCheck(board, cpu);
                break;
            }
            else
                if (playerTurn)
                    cout << "The selected square is invalid. Please try again. ";
        }
    }
    if (won == false) {
        cout << "\nThe game has ended in a draw!";
        draws++;
    }

    if (gamesPlayed >= 1)
        cout << "\nCurrent Scores:\nPlayer: " << playerWins << "\tCPU: " << cpuWins << "\t\tDraws: " << draws;

    cout << "\nWould you like to play this mode again? ";
    cin >> playAgain;

    while (playAgain != "Yes" && playAgain != "yes" && playAgain != "No" && playAgain != "no") {
        cout << "\nInvalid response entered, please try again: ";
        cin >> playAgain;
    }
    if (playAgain == "Yes" || playAgain == "yes") {
        gamesPlayed++;
        clearBoard(board);
        playTicTacToeCPUHard(board);
    }
    else
        resetCounters();
};


int main()
{
    int gameSelect;
    array<array<char, ROWS>, COLS>board{ {} };
    string play;
    bool done = false;
    cout << "\nWelcome to Tic-Tac-Toe.";

    srand(time(0));

    while(!done){

        cout << "\nAre you looking to have 2 players or play against the CPU? \nEnter 0 to exit the program, 1 for CPU play, or 2 for 2 players: ";
        cin >> gameSelect;

        while (gameSelect != 0 && gameSelect != 1 && gameSelect != 2)
        {
            cout << "\nAn invalid choice has been made, please try again: ";
            cin >> gameSelect;
        }

        if (gameSelect == 1) {
            cout << "Would you like to play against the Easy, Medium, or Hard CPU? (1 for Easy, 2 for Medium, 3 for Hard) ";
            cin >> gameSelect;

            while (gameSelect != 1 && gameSelect != 2 && gameSelect != 3) {
                cout << "An invalid choice has been entered, please try again.\n";
                cin >> gameSelect;
            }

            if (gameSelect == 1)
                playTicTacToeCPUEasy(board);
            else if (gameSelect == 2)
                playTicTacToeCPUMedium(board);
            else
                playTicTacToeCPUHard(board);
        }
        else if (gameSelect == 2)
            playTicTacToe(board);
        else
            break;

        cout << "\nAny other modes that you would like to play? Please respond Yes or No: ";
        cin >> play;
        while (play != "Yes" && play != "yes" && play != "No" && play != "no") {
            cout << "Invalid response, please try again: ";
            cin >> play;
        }
        if (play == "Yes" || play == "yes")
            clearBoard(board);
        else
            done = true;
    }

    cout << "\n\nThank you for playing, have a good day!\n\n";
    cin.get();

    return(0);
};
