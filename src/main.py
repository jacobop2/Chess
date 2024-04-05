import pygame
import sys

# Define colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)

pygame.init()

##### GLOBAL VARS #####
# Set the dimensions of the window
WINDOW_SIZE = (600, 600)
# Calculate the size of each square on the board based on the window size
BLOCK_SIZE = min(WINDOW_SIZE) // 8

screen = pygame.display.set_mode(WINDOW_SIZE)
pygame.display.set_caption("Chess By Jacob Poeschel")

# Load the piece images
b_piece_images = {
    'r': pygame.image.load("img/b_rook.png"),
    'n': pygame.image.load("img/b_knight.png"),
    'b': pygame.image.load("img/b_bishop.png"),
    'q': pygame.image.load("img/b_queen.png"),
    'k': pygame.image.load("img/b_king.png"),
    'p': pygame.image.load("img/b_pawn.png")
}

w_piece_images = {
    'r': pygame.image.load("img/w_rook.png"),
    'n': pygame.image.load("img/w_knight.png"),
    'b': pygame.image.load("img/w_bishop.png"),
    'q': pygame.image.load("img/w_queen.png"),
    'k': pygame.image.load("img/w_king.png"),
    'p': pygame.image.load("img/w_pawn.png")
}

# ChessPiece Class can have the following values:
#   TYPE: r (rook), n (knight), b (bishop), q (queen), k (king), p (pawn)
#   COLOR: 0 (black), 1 (white)
#   ROW: value 0 - 7 representing board rows 8 - 1
#   COL: value 0 - 7 representing board columns a - h
class ChessPiece:
    def __init__(self, type, color, row, column):
        self.type = type
        self.color = color
        self.row = row
        self.column = column

class Board:
    def __init__(self):
        # Initialize board to empty for safety
        self.board = [[None for _ in range(BLOCK_SIZE)] for _ in range(BLOCK_SIZE)]
        setup_board_standard(self.board)

# Setup the board 
def setup_board_standard(board):
    for row in range(BLOCK_SIZE):
        for col in range(BLOCK_SIZE):
            # place pieces
            if row == 0:
                if col == 0 or col == 7:
                    board[row][col] = ChessPiece('r', 0, row, col)
                elif col == 1 or col == 6:
                    board[row][col] = ChessPiece('n', 0, row, col)
                elif col == 2 or col == 5:
                    board[row][col] = ChessPiece('b', 0, row, col)
                elif col == 3:
                    board[row][col] = ChessPiece('q', 0, row, col)
                elif col == 4:
                    board[row][col] = ChessPiece('k', 0, row, col)
            elif row == 1:
                board[row][col] = ChessPiece('p', 0, row, col)
            elif row == 6:
                board[row][col] = ChessPiece('p', 1, row, col)
            elif row == 7:
                if col == 0 or col == 7:
                    board[row][col] = ChessPiece('r', 1, row, col)
                elif col == 1 or col == 6:
                    board[row][col] = ChessPiece('n', 1, row, col)
                elif col == 2 or col == 5:
                    board[row][col] = ChessPiece('b', 1, row, col)
                elif col == 3:
                    board[row][col] = ChessPiece('q', 1, row, col)
                elif col == 4:
                    board[row][col] = ChessPiece('k', 1, row, col)


# Draw the board
def draw_board(screen, board_obj):
    board = board_obj.board
    for row in range(BLOCK_SIZE):
        for col in range(BLOCK_SIZE):
            # If the board space is empty, draw empty tile
            if board[row][col] is None:
                if (row + col) % 2 == 0:
                    color = WHITE
                else:
                    color = BLACK
                rect = pygame.Rect(col * BLOCK_SIZE, row * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE)
                pygame.draw.rect(screen, color, rect)
            else:
                # Draw the piece image
                piece = board[row][col]

                if piece.color == 0:
                    image = b_piece_images[piece.type]
                    screen.blit(image, (col * BLOCK_SIZE, row * BLOCK_SIZE))
                else:
                    image = w_piece_images[piece.type]  # Use piece type to get the image
                    screen.blit(image, (col * BLOCK_SIZE, row * BLOCK_SIZE))

# Main game loop
def main():

    board = Board()

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

        screen.fill(WHITE)  # Fill the screen with white color
        draw_board(screen, board)        # Draw the board
        pygame.display.flip()   # Update the display

if __name__ == "__main__":
    main()
