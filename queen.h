#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"
#include <memory>
#include <string>

class Board; // Forward declaration of Board

class Queen : public Piece {
public:
    // Constructor
    Queen(bool isWhite, char symbol);

    // Override method to check if the move is valid for a Queen
    bool isValidMove(const std::string &from, const std::string &to) const override;

    // Provides the symbol for the Queen
    char getSymbol() const override;
};

#endif // QUEEN_H
