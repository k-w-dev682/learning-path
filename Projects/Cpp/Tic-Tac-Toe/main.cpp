#include <iostream>
#include <ctime>

void displayBoard(char board[3][3]);
void playerMove(char board[3][3]);
void computerMove(char board[3][3]);
bool checkWin(char board[3][3], char player);
bool checkDraw(char board[3][3]);

int main() {
    srand(time(0)); 

    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    displayBoard(board);

    while (true) {
        // 1. RUCH GRACZA
        playerMove(board);
        displayBoard(board);
        
        if (checkWin(board, 'X')) {
            std::cout << "You win!\n";
            break;
        }
        if (checkDraw(board)) {
            std::cout << "It's a draw!\n";
            break;
        }

        // 2. RUCH KOMPUTERA
        computerMove(board);
        displayBoard(board);

        if (checkWin(board, 'O')) {
            std::cout << "Computer wins!\n";
            break;
        }
        if (checkDraw(board)) {
            std::cout << "It's a draw!\n";
            break;
        }
    }

    std::cout << "Thank you for playing!\n";
    return 0;
}

void displayBoard(char board[3][3]) {
    std::cout << '\n';
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            std::cout << " " << board[i][j] << " ";
            if(j < 2) {
                std::cout << "|";
            }
        }
        std::cout << '\n';
        if(i < 2) {
            std::cout << "---|---|---\n";
        }
    }
}

void playerMove(char board[3][3]) {
    int slot;

    do {
        std::cout << "Make your move (1-9): ";
        std::cin >> slot;

        if(slot < 1 || slot > 9) {
            std::cout << "Wrong! Choose number (1-9) \n";
            continue;
        }
        int row = (slot - 1) / 3;
        int collumn = (slot - 1) % 3;

        if(board[row][collumn] != ' ') {
            std::cout << "This slot is taken! Choose another";
        } else {
            board[row][collumn] = 'X';
            break;
        }
    }
    while(true);
}

void computerMove(char board[3][3]) {
    int slot;
    int row;
    int collumn;

    std::cout << "Computer is making a move...\n";

    do {
        slot = (rand() % 9) + 1; 

        row = (slot - 1) / 3;
        collumn = (slot - 1) % 3;

        if (board[row][collumn] == ' ') {
            board[row][collumn] = 'O';
            break;
        }
    } while (true);
}

bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; 
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; 
        }
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; 
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false; 
            }
        }
    }
    return true; 
}