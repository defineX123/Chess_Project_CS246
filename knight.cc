#include "knight.h"

// Constructor: Initializes Knight with color and symbol
Knight::Knight(bool isWhite, char symbol) : Piece(isWhite, symbol) {}

// Provides the symbol for the Knight
char Knight::getSymbol() const {
    return this->symbol; // Use the symbol provided at initialization
}

// Overrides to check if the move is valid for a Knight
bool Knight::isValidMove(const std::string &from, const std::string &to) const {
    int startX = from[0] - 'a'; // Convert 'a'-'h' to 0-7
    int startY = from[1] - '1'; // Convert '1'-'8' to 0-7
    int endX = to[0] - 'a'; // Convert 'a'-'h' to 0-7
    int endY = to[1] - '1'; // Convert '1'-'8' to 0-7

    int dx = std::abs(endX - startX);
    int dy = std::abs(endY - startY);

    // Knight moves in an L-shape: 2 squares in one direction and 1 square in the perpendicular direction
    if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2)) {
        // Check if destination is occupied by a friendly piece
        return true; // Move is valid if it's an L-shape and destination is not occupied by a friendly piece
    }

    return false; // Move is invalid if it's not an L-shape
}
