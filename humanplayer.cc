#include "humanplayer.h"

// Constructor: Initializes HumanPlayer with color
HumanPlayer::HumanPlayer(bool isWhite) : Player{isWhite} {}

// Method to make a move for the human player
bool HumanPlayer::makeMove(std::unique_ptr<Board>& board, const std::string &from, 
    const std::string &to, const std::string &promotion) {
    
    bool canMove; // Flag to indicate if the move is valid
    Piece* movedPiece = board->getPiece(from); // Get the piece at the 'from' position
    char symbol = movedPiece->getSymbol(); // Get the symbol of the piece
    
    // Check if the piece exists
    if (movedPiece) { 
        // Check if the piece belongs to the correct side
        if ('a' < symbol && symbol < 'z') { // If the piece is black
            if (isWhite) { // If the player is white
                canMove = false; // White player cannot move black pieces
            } else {
                canMove = board->checkValidMove(from, to); // Validate the move
            }
        } else { // If the piece is white
            if (isWhite != true) { // If the player is black
                canMove = false; // Black player cannot move white pieces
            } else {
                canMove = board->checkValidMove(from, to); // Validate the move
            }
        }
        // Additional checks for check and checkmate can be added here
    } else {
        canMove = false; // Piece does not exist at 'from' position
    }

    // If the move is valid, execute it
    if (canMove) {
        if ((symbol == 'p' || symbol == 'P') && board->canPromote(to)) { // Check if promotion is possible
            char prom = promotion.at(0); // Get the promotion piece type
            board->changeBoard(from, to, prom); // Execute promotion
        } else {
            board->changeBoard(from, to, symbol); // Move the piece
        }
        return true; // Move was successful
    } else {
        return false; // Move was not valid
    }
}
