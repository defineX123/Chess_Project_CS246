#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece {
public:
    Knight(bool isWhite, char symbol);  // Constructor: Initializes Knight with color
    bool isValidMove(const std::string &from, const std::string &to) const override;  // Overrides to check if the move is valid for a Knight
    char getSymbol() const override;  // Provides the symbol for the Knight
};

#endif // KNIGHT_H
