#include <iostream>
#include <vector>

void initializeBoard(std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' '; 
        }
    }
}

void displayBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j];
            if (j < 2) std::cout << " | ";
        }
        std::cout << "\n";
        if (i < 2) std::cout << "---------\n";
    }
    std::cout << "\n";
}

bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || // Check rows
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) { // Check columns
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

bool checkDraw(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false; 
            }
        }
    }
    return true; 
}

void makeMove(std::vector<std::vector<char>>& board, char player) {
    int row, col;
    while (true) {
        std::cout << "Player " << player << ", enter your move (row and column: 0-2): ";
        std::cin >> row >> col;
        
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = player;
            break;
        } else {
            std::cout << "Invalid move. Please try again.\n";
        }
    }
}

int main() {
    char playAgain;
    do {
        std::vector<std::vector<char>> board(3, std::vector<char>(3));
        initializeBoard(board);
        char currentPlayer = 'X';
        bool gameOver = false;
        while (!gameOver) {
            displayBoard(board);
            makeMove(board, currentPlayer);
        
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                std::cout << "Player " << currentPlayer << " wins!\n";
                gameOver = true;
            }
        
            else if (checkDraw(board)) {
                displayBoard(board);
                std::cout << "It's a draw!\n";
                gameOver = true;
            }
            else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

    
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;
        
    } while (playAgain == 'y' || playAgain == 'Y');
    
    std::cout << "Thanks for playing!\n";
    return 0;
}
