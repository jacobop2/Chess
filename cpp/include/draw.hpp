#ifndef DRAW_HPP
#define DRAW_HPP

#include <SFML/Graphics.hpp>
#include "board.hpp"

void drawBoard(sf::RenderWindow& window);
void drawPieces(sf::RenderWindow& window, Board& board, sf::Sprite pieceSprites[]);

#endif // DRAW_HPP