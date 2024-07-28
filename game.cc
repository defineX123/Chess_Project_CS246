#include "game.h"
using namespace std;

Game::Game(){
  board = make_unique<Board>();
  scoreBoard["white"] = 0;
  scoreBoard["black"] = 0;
  board->init();
}

void Game::start(unique_ptr<Player> white, unique_ptr<Player> black) {
  player1 = move(white);
  player2 = move(black);
  gameStart = true;
  display();
}

void Game::makeMove(const string &from, const string &to, const string &promotion) {
  //char thePiece = board->getPiece(from)->getSymbol();

  if (white) {

    bool valid = player1->makeMove(board, from, to, promotion);

    if (board->isInCheckmate(!white)) {
      cout << "Black is in Checkmate!" << endl;
      isWinner(white);
      end();
    } else if (board->isInCheck(!white)) {
      cout << "Black is in Check!" << endl;
    } else if(board->isStalemate(!white)) {
      cout << "Stalemate!" << endl;
    }
     if (!valid) {
      cout << "not valid" << endl;

    } else {
      display();
      changePlayer();
    }
  } else {
     bool valid = player2->makeMove(board, from, to, promotion);

    if (board->isInCheckmate(!white)) {
      cout << "White is in Checkmate!" << endl;
      isWinner(white);
      end();
    } else if (board->isInCheck(!white)) {
      cout << "White is in Check!" << endl;
    } else if(board->isStalemate(!white)) {
      cout << "Stalemate!" << endl;
    }
     if (!valid) {
      cout << "not valid" << endl;
    } else {
      display();
      changePlayer();
    } 
  }
}

void Game::changePlayer() {
  white = !white;
  cout << "It's " ;
  if (white) {
    cout << "white turn" << endl;
  } else {
    cout << "black turn" << endl;
  }
}

void Game::isWinner(bool white) {
  if(white) {
    cout << "CheckMate! White wins!" << endl;
    addScore(true);
  } else {
    cout << "CheckMate! Black wins!" << endl;
    addScore(false);
  }
}

void Game::addScore(bool white) {
  if (white) {
    scoreBoard["white"] += 1;
  } else {
    scoreBoard["black"] += 1;
  }
}

void Game::resign() {
  if(!white) {
    cout << "CheckMate! white wins!" << endl;
    addScore(true);
    end();
  } else {
    cout << "CheckMate! Black wins!" << endl;
    addScore(false);
    end();
  }
}

void Game::printFinalScore() {
  cout << "Final Score:" << endl;
  cout << "White: " << scoreBoard["white"] << endl;
  cout << "Black: " << scoreBoard["black"] << endl;
}

void Game::setup() {
  board->setupBoard();
}

void Game::display() {
  board->display();
}

void Game::end() {
  cout << "The game has ended." << endl;
    printFinalScore();
    // Reset the game state if necessary
    board = make_unique<Board>();
    player1.reset();
    player2.reset();
    gameStart = false;
    white = true;
}

bool Game::getWhite() {
  return white;
}

bool Game::getGameStart() {
  return gameStart;
}

string Game::getPlayer() {
  if (white) {
    return whiteplayer;
  } else {
    return blackplayer;
  }
}

void Game::setPlayer(string player, bool whiteOrBlack) {
  if (whiteOrBlack) {
    whiteplayer = player;
  } else {
    blackplayer = player;
  }
}

void Game::removePiece(string coord) {
  board->removePiece(coord);
  display();
}
void Game::setup(char piece, string coord) {


  string position;
  for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            string currentCoord = string(1, 'a' + x) + to_string(y + 1);

            Piece *curpiece = board->getPiece(currentCoord);
            if (curpiece && curpiece->getSymbol() == piece) {
                cout << currentCoord << endl;
                position = currentCoord;
                break; // Exit the loop once the king is found
            }
        }
        if (!position.empty()) break; // Exit the outer loop if the king is found
    }

  board->changeBoard(position, coord, piece);
  cout << "on" << endl;
  display();
}
void Game::setWhite(bool iswhite) {
  white = iswhite;
}
