#include "king.h"
#include "rook.h"
#include <cmath>

// Constructor: Initializes King with color
King::King(bool isWhite, char symbol) : Piece(isWhite, symbol) {}

// Overrides to check if the move is valid for a King
bool King::isValidMove(const std::string &from, const std::string &to) const {
   // Extract coordinates from strings
   int startX = from[0] - 'a'; // Convert 'a'-'h' to 0-7
   int startY = from[1] - '1'; // Convert '1'-'8' to 0-7
   int endX = to[0] - 'a'; // Convert 'a'-'h' to 0-7
   int endY = to[1] - '1'; // Convert '1'-'8' to 0-7

   // Calculate the absolute difference between start and end positions
   int dx = std::abs(startX - endX);
   int dy = std::abs(startY - endY);

   // Check if the move is a valid king move (one square in any direction)
   if ((dx <= 1 && dy <= 1) && !(dx == 0 && dy == 0)) {
       // If the move is within the valid range for a king, return true
       return true;
   }

   // If not a valid king move, return false
   return false;
}

// Provides the symbol for the King
char King::getSymbol() const {
   return this->symbol; // 'K' for white king, 'k' for black king
}

bool King::hasMoved() const {
   return moved; // Return whether the king has moved
}

void King::setMoved(bool moved) {
   this->moved = moved; // Set the moved status of the king
}
