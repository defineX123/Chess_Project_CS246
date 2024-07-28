#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "board.h"
#include "piece.h"
#include "pawn.h"
#include <map>
#include <string>
#include <memory>
#include <utility>

using namespace std;

// Chess game class
class Game {
  int level = 0;          // Game level: 0 for human, 1-4 for computer
  unique_ptr<Board> board;           // Game board
  unique_ptr<Player> player1;        // Player 1
  unique_ptr<Player> player2;        // Player 2
  bool white = true;    // Current player (white starts)
  bool gameStart = false; // Game started flag
  map<string, int> scoreBoard;            // Scoreboard for players
  string whiteplayer; // White player type
  string blackplayer; // Black player type

  public:
    Game(); // Constructor
    void start(unique_ptr<Player> white, unique_ptr<Player> black);     
    void makeMove(const string &from, const string &to, const string &promotion); 
    void display(); // Display the board
    void changePlayer(); // Switch current player
    void isWinner(bool white); // Declare winner and update score
    void addScore(bool white); // Increment score for a player
    void resign(); // Player resigns
    void printFinalScore(); // Print final score
    void setup(); // Set up the game
    void end(); // End the game
    bool getWhite(); // Get current player color
    bool getGameStart(); // Check if game has started
    void setPlayer(string player, bool whiteOrBlack); // Set player type
    string getPlayer(); // Get current player type
    void setup(char piece, string coord);
    void removePiece(string coord);
    void setWhite(bool iswhite);
};

#endif
