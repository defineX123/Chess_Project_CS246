#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "board.h"
#include "pawn.h"


// Abstract class for player

class Player{
  protected:
  bool isWhite; // to determine if the player is assigned white or black pieces

  public:
    Player(bool isWhite) :isWhite(isWhite){} // true = white, false = black 
    virtual bool makeMove(std::unique_ptr<Board>& board, const std::string &from, const std::string &to, const std::string &promotion) = 0;
    // determine if player can move or not
    // some other function
    virtual ~Player() = default;
    bool isWhiteOrBlack() {return isWhite;}  // Returns true if the player is White, false if Black

};

#endif
