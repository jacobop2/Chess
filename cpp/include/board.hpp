#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>

const int NUM_ROWS = 8;
const int NUM_COLS = 8;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;
const int SQUARE_SIZE = SCREEN_WIDTH / NUM_COLS;

struct Square {
    int row;
    int col;

    Square(int r, int c) 
        : row(r), col(c) {}
    
    bool operator==(const Square& other) const {
        return row == other.row && col == other.col;
    }
};

enum class PieceColor {
    WHITE, BLACK, NONE
};

enum class PieceType {
    PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING, NONE
};

struct Piece {
    PieceType type = PieceType::NONE;
    PieceColor color = PieceColor::NONE;
    bool hasMoved = false;

    Piece() = default;
    Piece(PieceType t, PieceColor c, bool moved = false)
        : type(t), color(c), hasMoved(moved) {}
};

class Board {
public:
    Board();
    Piece at(int row, int col) const {
        return m_board[row][col];
    }
    std::vector<Square> getValidMoves(const Piece& piece, int row, int col) const;

private:
    Piece m_board[NUM_COLS][NUM_ROWS];
};

#endif // BOARD_HPP