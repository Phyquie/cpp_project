#include <iostream>
#include <vector>
#include <limits>

class ChessGame {
private:
    char board[8][8];

public:
    ChessGame() {
        initializeBoard();
    }

    void displayBoard() {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                std::cout << board[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    void initializeBoard() {
        // Initialize the chess board with pieces
        // For simplicity, using 'P' for pawns, 'R' for rooks, etc.
        // Lowercase for black pieces, uppercase for white pieces
        char pieces[] = {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'};
        for (int i = 0; i < 8; ++i) {
            board[0][i] = pieces[i];
            board[1][i] = 'P';
            board[6][i] = 'p';
            board[7][i] = pieces[i] + 32; // Uppercase to lowercase conversion
        }
    }

    bool isValidMove(int fromRow, int fromCol, int toRow, int toCol) {
        // Basic validation for demonstration purposes
        return fromRow >= 0 && fromRow < 8 && fromCol >= 0 && fromCol < 8 &&
               toRow >= 0 && toRow < 8 && toCol >= 0 && toCol < 8 &&
               board[fromRow][fromCol] != ' ' && board[fromRow][fromCol] != 'p' &&
               board[toRow][toCol] == ' ';
    }

    void makeMove(int fromRow, int fromCol, int toRow, int toCol) {
        if (isValidMove(fromRow, fromCol, toRow, toCol)) {
            // Make the move
            board[toRow][toCol] = board[fromRow][fromCol];
            board[fromRow][fromCol] = ' ';
        } else {
            std::cout << "Invalid move. Try again.\n";
        }
    }
};

int main() {
    ChessGame chessGame;
    int fromRow, fromCol, toRow, toCol;

    do {
        // Display the chess board
        chessGame.displayBoard();

        // Get player's move
        std::cout << "Enter the row and column of the piece to move (e.g., 2 3): ";
        std::cin >> fromRow >> fromCol;

        std::cout << "Enter the row and column to move the piece to (e.g., 4 3): ";
        std::cin >> toRow >> toCol;

        // Make the move
        chessGame.makeMove(fromRow, fromCol, toRow, toCol);

        // Clear input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (true);

    return 0;
}
