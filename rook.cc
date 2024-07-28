#include "rook.h"
#include <cmath>

// Constructor for the Rook class
Rook::Rook(bool isWhite, char symbol) : Piece(isWhite, symbol), moved(false) {}

// Checks if the move from 'from' to 'to' is valid for a Rook
bool Rook::isValidMove(const std::string &from, const std::string &to) const {
    // Convert board coordinates from string to numeric indices
    int fromX = from[0] - 'a'; // Convert column 'a'-'h' to 0-7
    int fromY = from[1] - '1'; // Convert row '1'-'8' to 0-7
    int toX = to[0] - 'a';     // Convert column 'a'-'h' to 0-7
    int toY = to[1] - '1';     // Convert row '1'-'8' to 0-7

    // Check if the move is horizontal or vertical
    if (fromX == toX || fromY == toY) {
        // For horizontal moves (same row)
        if (fromY == toY) {
            // Move is horizontal
            return true;
        }
        // For vertical moves (same column)
        else if (fromX == toX) {
            // Move is vertical
            return true;
        }
        // This return is redundant and can be removed; added for clarity
        return true; // The move is valid (horizontal or vertical)
    }

    // The move is not horizontal or vertical
    return false; // The move is not valid
}

// Provides the symbol for the Rook
char Rook::getSymbol() const {
    return this->symbol; // Return the symbol of the Rook ('R' or 'r')
}

// Checks if the Rook has moved
bool Rook::hasMoved() const {
    return moved; // Return the moved status of the Rook
}

// Sets the moved status of the Rook
void Rook::setMoved(bool moved) {
    this->moved = moved; // Update the moved status of the Rook
}
