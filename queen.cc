#include "queen.h"


// Constructor: Initializes Queen with color
Queen::Queen(bool isWhite, char symbol) : Piece(isWhite, symbol) {}


// Overrides to check if the move is valid for a Queen
bool Queen::isValidMove(const std::string &from, const std::string &to) const {
   // Extract coordinates from strings
   int startX = from[0] - 'a'; // Convert 'a'-'h' to 0-7
   int startY = from[1] - '1'; // Convert '1'-'8' to 0-7
   int endX = to[0] - 'a'; // Convert 'a'-'h' to 0-7
   int endY = to[1] - '1'; // Convert '1'-'8' to 0-7


   // Check if move is diagonal
   if (abs(startX - endX) == abs(startY - endY)) {
       return true;
   }


   // Check if move is horizontal
   if (startY == endY) {
       return true;
   }


   // Check if move is vertical
   if (startX == endX) {
       return true;
   }

   // If not diagonal, horizontal, or vertical, move is invalid
   return false;
}


// Provides the symbol for the Queen
char Queen::getSymbol() const {
   return this->symbol;
}
