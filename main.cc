#include <iostream>
#include "game.h"
#include "board.h"
#include "player.h"
#include "humanplayer.h"
#include "piece.h"
#include "pawn.h"
#include "computerplayer.h"

int main() {
    Game game;
    std::string whitePlayerType, blackPlayerType;
    std::string curPlayer = whitePlayerType;

    std::string command;
    
    while (std::cin >> command) {
        // Start a new game
        if (command == "game") {
            std::cin >> whitePlayerType >> blackPlayerType; // Read player types
            // Example: [game human computer2] means whitePlayer is human, blackPlayer is computer level 2
            cout << whitePlayerType << " vs " << blackPlayerType << endl;
            unique_ptr<Player> whitePlayer, blackPlayer;

            // Initialize white player based on type
            if (whitePlayerType == "human") {
                whitePlayer = make_unique<HumanPlayer>(true); // White human player
                game.setPlayer("human", true);
            } else if (whitePlayerType == "computer[1]") {
                whitePlayer = make_unique<ComputerPlayer>(1, true); // White computer level 1
                game.setPlayer("computer", true);
            } else if (whitePlayerType == "computer[2]") {
                whitePlayer = make_unique<ComputerPlayer>(2, true); // White computer level 2
                game.setPlayer("computer", true);
            } else if (whitePlayerType == "computer[3]") {
                whitePlayer = make_unique<ComputerPlayer>(3, true); // White computer level 3
                game.setPlayer("computer", true);
            }

            // Initialize black player based on type
            if (blackPlayerType == "human") {
                blackPlayer = make_unique<HumanPlayer>(false); // Black human player
                game.setPlayer("human", false);
            } else if (blackPlayerType == "computer[1]") {
                blackPlayer = make_unique<ComputerPlayer>(1, false); // Black computer level 1
                game.setPlayer("computer", false);
            } else if (blackPlayerType == "computer[2]") {
                blackPlayer = make_unique<ComputerPlayer>(2, false); // Black computer level 2
                game.setPlayer("computer", false);
            } else if (blackPlayerType == "computer[3]") {
                blackPlayer = make_unique<ComputerPlayer>(3, false); // Black computer level 3
                game.setPlayer("computer", false);
            }
            
            game.start(move(whitePlayer), move(blackPlayer)); // Start the game with players

        } else if (command == "move") { // Handle move command
        // Example command: [move f7 f8 Q] : Note the third command is optional, and is used for promotion
            cout << game.getPlayer()  << "Current Player" << endl;
            if (game.getPlayer().substr(0, 8) == "computer") {
                game.makeMove("", "", ""); // Computer's move (arguments not used)
            } else {
                std::string from, to, promotion;
                std::cin >> from >> to;
                if (std::cin.peek() != '\n') { // Check if there's an additional promotion argument
                    std::cin >> promotion;
                }

                // Validate move coordinate and promotion
                if (!(stoi(from.substr(1, 1)) <= 8 && stoi(from.substr(1, 1)) >= 1 && from.at(0) >= 'a' && from.at(0) <= 'h')) {
                    if (promotion != "") {
                        if (!(promotion == "Q" || promotion == "R" || promotion == "N" || promotion == "B")) {  // choose from Queen, Rook, Knight, Bishop during promotion.
                            cout << "Invalid Promotion" << endl;
                        }
                    } 
                    cout << "Invalid Move Coordinate" << endl;
                } else {
                    game.makeMove(from, to, promotion); // Make the move
                }
                
            }
            
        } else if (command == "resign") { // Handle resign command
            game.resign();
            cout << "Good Game. Restart the Game by typing the command game [player] [player]" << endl;
        } else if (command == "score") { // Print final score
            game.printFinalScore();
        } else if (command == "player") { // Print current player turn
            if (game.getWhite()) {
                cout << "It's White turn" << endl;
            } else {
                cout << "It's Black turn" << endl;
            }
        } else if (command == "setup") { // Check if setup is available
            if (game.getGameStart()) {
                cout << "The game is started, set up mode is no longer available" << endl;
            } else {
                string piece, coord;
                string set;
                while (cin >> set) {
                //std::cin >> command;
                    if (set == "done") {
                        break;
                    } else if (set == "+") {
                        cin >> piece >> coord;
                        game.setup(piece.at(0), coord);
                    } else if (set == "-") {
                        cin >> coord;
                        game.removePiece(coord);
                    } else if (set == "=") {
                        string color;
                        cin >> color;
                        bool play;

                        if (color == "white") {
                            play = true;
                        } else {
                            play = false;
                        }
                        game.setWhite(play); 
                    } else {
                        cout << "setup not done, no leaving mode" << endl;
                    }
                }
            }
        } else {
            cout << "Invalid command" << endl; // Handle invalid commands
        }
    }

    game.printFinalScore(); // Print final score on exit
    return 0;
}
