#include "piece.h"

Piece::Piece(bool isWhite, char symbol) : white(isWhite), symbol(symbol) {}

char Piece::getSymbol() const {
    return symbol;
}

// No need to implement isValidMove or getSymbol here as they are pure virtual in the base class
