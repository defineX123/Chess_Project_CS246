#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "player.h"  
#include <vector>    
#include <map>     
#include <string>    
#include <iostream> 

// Declaration of the HumanPlayer class which inherits from Player
class HumanPlayer : public Player {
  
  public:
    // Constructor for HumanPlayer, initializing with color (isWhite)
    HumanPlayer(bool isWhite);

    // Override the makeMove function to handle human player moves
    bool makeMove(std::unique_ptr<Board>& board, const std::string &from, const std::string &to, const std::string &promotion) override;
};

#endif // End of header guard
