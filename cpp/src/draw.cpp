#include "draw.hpp"

void drawBoard(sf::RenderWindow& window) 
{
    for (int row = 0; row < NUM_ROWS; ++row) {
        for (int col = 0; col < NUM_COLS; ++col) {
            sf::RectangleShape square(sf::Vector2f(SQUARE_SIZE, SQUARE_SIZE));
            square.setPosition(col * SQUARE_SIZE, row * SQUARE_SIZE);
            square.setFillColor((row + col) % 2 == 0 ? sf::Color::White : sf::Color(0,50,0));
            window.draw(square);
        }
    }
}

void drawPieces(sf::RenderWindow& window, Board& board, sf::Sprite pieceSprites[]) 
{
    for (int row = 0; row < NUM_ROWS; ++row) {
        for (int col = 0; col < NUM_COLS; ++col) {
            Piece piece = board.at(row, col);
            if (piece.type == PieceType::NONE)
                continue;

            int spriteIndex = -1;
            if (piece.color == PieceColor::WHITE) {
                switch (piece.type) {
                    case PieceType::PAWN:   spriteIndex = 0; break;
                    case PieceType::KNIGHT: spriteIndex = 1; break;
                    case PieceType::BISHOP: spriteIndex = 2; break;
                    case PieceType::ROOK:   spriteIndex = 3; break;
                    case PieceType::QUEEN:  spriteIndex = 4; break;
                    case PieceType::KING:   spriteIndex = 5; break;
                    default: break;
                }
            } else if (piece.color == PieceColor::BLACK) {
                switch (piece.type) {
                    case PieceType::PAWN:   spriteIndex = 6; break;
                    case PieceType::KNIGHT: spriteIndex = 7; break;
                    case PieceType::BISHOP: spriteIndex = 8; break;
                    case PieceType::ROOK:   spriteIndex = 9; break;
                    case PieceType::QUEEN:  spriteIndex = 10; break;
                    case PieceType::KING:   spriteIndex = 11; break;
                    default: break;
                }
            }

            if (spriteIndex != -1) {
                pieceSprites[spriteIndex].setPosition(col * SQUARE_SIZE, row * SQUARE_SIZE);
                window.draw(pieceSprites[spriteIndex]);
            }
        }
    }
}