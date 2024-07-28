#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H
#include "player.h"

#include <vector>
#include <ctime>
#include <map>
#include <string>
#include <iostream>



class ComputerPlayer : public Player {
    int level; 
    //bool isWhite;
  public:
    ComputerPlayer(int level, bool isWhite);
    bool makeMove(std::unique_ptr<Board>& board, const std::string &from, const std::string &to, const std::string &promotion) override;
    bool level1(std::unique_ptr<Board>& board, bool isWhite);
    bool level2(std::unique_ptr<Board>& board, bool isWhite);
    bool level3(std::unique_ptr<Board>& board, bool isWhite);

};

#endif
