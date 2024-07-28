#ifndef ROOK_H
#define ROOK_H


#include "piece.h"
#include <memory>
#include <string>


class Rook : public Piece {
public:
   Rook(bool isWhite, char symbol); // Constructor
   bool isValidMove(const std::string &from, const std::string &to) const override; // Overrides to check if the move is valid for a Rook
   bool hasMoved() const; // Checks if the Rook has moved
   void setMoved(bool moved); // Sets the moved status of the Rook
    char getSymbol() const override;
private:
   bool moved; // Indicates whether the Rook has moved
};


#endif // ROOK_H
