#include "bishop.h"
#include "board.h"
#include <cmath> // For std::abs

// Constructor: Initializes Bishop with color
Bishop::Bishop(bool isWhite, char symbol) : Piece(isWhite, symbol) {}

// Overrides to check if the move is valid for a Bishop
bool Bishop::isValidMove(const std::string &from, const std::string &to) const {
    // Extract coordinates from strings
    int startX = from[0] - 'a'; // Convert 'a'-'h' to 0-7
    int startY = from[1] - '1'; // Convert '1'-'8' to 0-7
    int endX = to[0] - 'a'; // Convert 'a'-'h' to 0-7
    int endY = to[1] - '1'; // Convert '1'-'8' to 0-7

    // Check if move is diagonal
    if (std::abs(startX - endX) == std::abs(startY - endY)) {
        return true;            // change later
    }

    // If not diagonal, move is invalid
    return false;
}

// Provides the symbol for the Bishop
char Bishop::getSymbol() const {
    return this->symbol; // Standard symbol for Bishop
}
