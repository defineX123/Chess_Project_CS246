#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <memory>
#include "piece.h"
#include "pawn.h"
#include <iostream>
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "rook.h"
#include "king.h"
#include <map>

using namespace std;

// purpose: To create a board
// Abstract Class


class Board {
  protected:
    vector<vector<unique_ptr<Piece>>> board;
    //vector<unique_ptr<Move>> moveHistory;

  public:
    Board();      // constructing a board;
    void init();    // initializing a board by putting all the necessary piece in *board
    void display();// (or ostream)
    // display/output the current board
    void setupBoard();
    void setBoard(char piece, string coord);
    // set PIECE at COORD, replace if COORD already has a piece
    // restriction: pawn is not at first row or last row
    //              special piece can only appear once in the board
    void removePiece(string coord);
    // remove PIECE at current COORD:
    Piece *getPiece(const string &coord) const;
    // return PIECE at COORD in BOARD
    

    // additional
    //void addMove(string from, string to, string piece, string promotion = "", string capture = "");

    void changeBoard(const string &from, const string &to, char piece);
    bool checkValidMove(const string &from, const string &to) const;
    bool isPathClear(const std::string &from, const std::string &to) const;
    bool canPromote(const std::string &to);
    bool isInCheck(bool white) const;
        bool isInCheckmate(bool white);  // Checks if the given color (white) is in checkmate
    bool isStalemate(bool white);  // Checks if the game is in a stalemate 
    map<string, char> pieceCoords(bool isWhite) const; // returns the coordinates of pieces left on board 
    map<string, int> possibleMoves(string coord, bool isWhite) const; // returns possible moves for piece
    map<string, map<string, int>> allMoves(bool isWhite) const; // finds all possible moves and classifies

    int moveValue(const std::string &fromCoord, const std::string &toCoord, bool isWhite)const ;
    map<string, int> getPawnMoves(string coord, bool isWhite) const;
    map<string, int> getKnightMoves(string coord, bool isWhite) const;
    map<string, int> getBishopMoves(string coord, bool isWhite) const;
    map<string, int> getRookMoves(string coord, bool isWhite) const;
    map<string, int> getQueenMoves(string coord, bool isWhite) const;
    map<string, int> getKingMoves(string coord, bool isWhite) const;
    bool isEnPassantMove(const std::string &from, const std::string &to);

};



#endif
