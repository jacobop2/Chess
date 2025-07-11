#include "board.hpp"

Board::Board() {
    m_board[0][0] = Piece(PieceType::ROOK, PieceColor::BLACK);
    m_board[0][1] = Piece(PieceType::KNIGHT, PieceColor::BLACK);
    m_board[0][2] = Piece(PieceType::BISHOP, PieceColor::BLACK);
    m_board[0][3] = Piece(PieceType::QUEEN, PieceColor::BLACK);
    m_board[0][4] = Piece(PieceType::KING, PieceColor::BLACK);
    m_board[0][5] = Piece(PieceType::BISHOP, PieceColor::BLACK);
    m_board[0][6] = Piece(PieceType::KNIGHT, PieceColor::BLACK);
    m_board[0][7] = Piece(PieceType::ROOK, PieceColor::BLACK);
    for (int col = 0; col < NUM_COLS; ++col) {
        m_board[1][col] = Piece(PieceType::PAWN, PieceColor::BLACK);
    }

    m_board[7][0] = Piece(PieceType::ROOK, PieceColor::WHITE);
    m_board[7][1] = Piece(PieceType::KNIGHT, PieceColor::WHITE);
    m_board[7][2] = Piece(PieceType::BISHOP, PieceColor::WHITE);
    m_board[7][3] = Piece(PieceType::QUEEN, PieceColor::WHITE);
    m_board[7][4] = Piece(PieceType::KING, PieceColor::WHITE);
    m_board[7][5] = Piece(PieceType::BISHOP, PieceColor::WHITE);
    m_board[7][6] = Piece(PieceType::KNIGHT, PieceColor::WHITE);
    m_board[7][7] = Piece(PieceType::ROOK, PieceColor::WHITE);
    for (int col = 0; col < NUM_COLS; ++col) {
        m_board[6][col] = Piece(PieceType::PAWN, PieceColor::WHITE);
    }
}

std::vector<Square> Board::getValidMoves(const Piece& piece, int row, int col) const {
    std::vector<Square> validMoves;

    if (piece.type == PieceType::PAWN) {
        int direction = (piece.color == PieceColor::WHITE) ? -1 : 1;
        if (row + direction >= 0 && row + direction < NUM_ROWS) {
            if (m_board[row + direction][col].type == PieceType::NONE) {
                validMoves.push_back(Square(row + direction, col));
            }
            if (piece.hasMoved == false && row + 2 * direction >= 0 && row + 2 * direction < NUM_ROWS &&
                m_board[row + 2 * direction][col].type == PieceType::NONE && 
                m_board[row + direction][col].type == PieceType::NONE) {
                    validMoves.push_back(Square(row + 2 * direction, col));
            }
            if (col > 0 && m_board[row + direction][col - 1].color != piece.color) {
                validMoves.push_back(Square(row + direction, col - 1));
            }
            if (col < NUM_COLS - 1 && m_board[row + direction][col + 1].color != piece.color) {
                validMoves.push_back(Square(row + direction, col + 1));
            }
            // En passant logic can be added here
        }
    } else if (piece.type == PieceType::ROOK) {
        // Rook logic here
    } else if (piece.type == PieceType::BISHOP) {
        // Bishop logic here
    } else if (piece.type == PieceType::KNIGHT) {
        // Knight logic here
    } else if (piece.type == PieceType::QUEEN) {
        // Queen logic here
    } else if (piece.type == PieceType::KING) {
        // King logic here
    }

    return validMoves;
}