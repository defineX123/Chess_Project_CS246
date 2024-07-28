#include "pawn.h"

Pawn::Pawn(bool isWhite, char symbol) : Piece(isWhite, symbol), enPassantPossible(false)  {}

bool Pawn::isValidMove(const std::string &from, const std::string &to) const {
    // Convert 'a'-'h' to 0-7 and '1'-'8' to 0-7
    int startX = from[0] - 'a';
    int startY = from[1] - '1';
    int endX = to[0] - 'a';
    int endY = to[1] - '1';

    int direction = (this->isWhite()) ? 1 : -1; // 1 for white pawn, -1 for black pawn

    // Check for standard one-step forward move
    if (endX == startX && endY == startY + direction) {
        //std::cout << "Standard one-step move valid\n";
        return true;
    }

    // Check for initial two-step forward move
    if (endX == startX && endY == startY + 2 * direction && 
        ((this->isWhite() && startY == 1) || (!this->isWhite() && startY == 6))) {
        //std::cout << "Initial two-step move valid\n";
        return true;
    }

    // Check for diagonal capture move
    if (std::abs(endX - startX) == 1 && endY == startY + direction) {
        //std::cout << "Diagonal capture move valid\n";
        return true;
    }

    //std::cout << "Move invalid\n";
    return false;
}


char Pawn::getSymbol() const {
    return symbol;
}
