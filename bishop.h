#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece {
public:
    Bishop(bool isWhite, char symbol);  // Constructor: Initializes Bishop with color
    bool isValidMove(const std::string &from, const std::string &to) const override;  // Overrides to check if the move is valid for a Bishop
    char getSymbol() const override;  // Provides the symbol for the Bishop
    //bool Bishop::isPathClear(const std::string &from, const std::string &to, const std::unique_ptr<Board> &board) const;
};

#endif // BISHOP_H
