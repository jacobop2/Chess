#include "draw.hpp"
#include <iostream>

const int DEBUG = 1;

int main() 
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Joe Chess");
    window.setVerticalSyncEnabled(false);

    Board board;

    sf::Texture textures[12];
    sf::Sprite pieceSprites[12];
    std::string pieceFiles[] = {
        "../assets/w_pawn.png", "../assets/w_knight.png", "../assets/w_bishop.png",
        "../assets/w_rook.png", "../assets/w_queen.png", "../assets/w_king.png",
        "../assets/b_pawn.png", "../assets/b_knight.png", "../assets/b_bishop.png",
        "../assets/b_rook.png", "../assets/b_queen.png", "../assets/b_king.png"
    };

    for (int i = 0; i < 12; ++i) {
        if (!textures[i].loadFromFile(pieceFiles[i])) {
            std::cerr << "Failed to load " << pieceFiles[i] << std::endl;
            return 1;
        }
        pieceSprites[i].setTexture(textures[i]);
        pieceSprites[i].setScale(static_cast<float>(SQUARE_SIZE) / textures[i].getSize().x,
                                 static_cast<float>(SQUARE_SIZE) / textures[i].getSize().y);
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                // Handle mouse click
                int mouse_col = event.mouseButton.x / SQUARE_SIZE;
                int mouse_row = event.mouseButton.y / SQUARE_SIZE;

                Piece piece = board.at(mouse_row, mouse_col);

                // First click = empty square, do nothing
                if (piece.type == PieceType::NONE && piece.color == PieceColor::NONE) {
                    if (DEBUG)
                        std::cout << "Clicked on empty square at (" << mouse_row << ", " << mouse_col << ")\n";
                    continue;
                }

                if (DEBUG) {
                    std::string typeStr, colorStr;
                    switch (piece.type) {
                        case PieceType::PAWN:   typeStr = "Pawn"; break;
                        case PieceType::KNIGHT: typeStr = "Knight"; break;
                        case PieceType::BISHOP: typeStr = "Bishop"; break;
                        case PieceType::ROOK:   typeStr = "Rook"; break;
                        case PieceType::QUEEN:  typeStr = "Queen"; break;
                        case PieceType::KING:   typeStr = "King"; break;
                        default:                typeStr = "None"; break;
                    }
                    switch (piece.color) {
                        case PieceColor::WHITE: colorStr = "White"; break;
                        case PieceColor::BLACK: colorStr = "Black"; break;
                        default:                colorStr = "None"; break;
                    }
                    std::cout << "Clicked on " << colorStr << " " << typeStr
                            << " at (" << mouse_row << ", " << mouse_col << ")\n";
                }

                std::vector<Square> validMoves = board.getValidMoves(piece, mouse_row, mouse_col);

                // First click = piece, highlight all valid moves
                // Release, if on same square as click, prepare for second click
                // Second click = move piece to new position
                // If second click in same place, unselect piece
                

                // First click = piece, highlight all valid moves
                // Release, if on different square as click, attempt move, otherwise do nothing
            }
        }
        window.clear();
        drawBoard(window);
        drawPieces(window, board, pieceSprites);
        window.display();
    }
    
    return 0;
}