
#include "player.h"
#include <limits>
// for INT_MAX/MIN, max(), min()


#include "computerplayer.h"
using namespace std;


ComputerPlayer::ComputerPlayer(int level, bool isWhite) : Player{isWhite}, level{level} {}

bool ComputerPlayer::level1(std::unique_ptr<Board>& board, bool isWhite) { 

    char random_char = 'a' + (std::rand() % 8);

    // Generate a random number between 1 and 8
    int random_number = 1 + (std::rand() % 8);

    // Combine the random character and number into a coordinate
    //std::cout << "Random coordinate: " << random_char << random_number << std::endl;
    string to = string(1, random_char) + to_string(random_number);
    //cout << to << endl;
    std::vector<char> pieceWhite = {
        'K', 'Q', 'R', 'B', 'N', 'P'
    };

    std::vector<char> pieceBlack = {
        'k', 'q', 'r', 'b', 'n', 'p'
    };

    int randomPiece = 1 + (std::rand() % 5);
    //cout << randomPiece << endl;
    char piece;
    if (isWhite) {
        piece = pieceWhite[randomPiece];
        //std::cout << "Random Piece: " << piece << std::endl;
    } else {
        piece = pieceBlack[randomPiece];
        //std::cout << "Random Piece: " << piece << std::endl;
    }

    string position;

    // Find the position of the king
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            string currentCoord = string(1, 'a' + x) + to_string(y + 1);
            Piece *piec = board->getPiece(currentCoord);
            if (piec && piec->getSymbol() == piece) {
                position = currentCoord;
                break; // Exit the loop once the king is found
            }
        }
        if (!position.empty()) break; // Exit the outer loop if the king is found
    }
    //std::cout << "Position: " << position << std::endl;

    if (board->checkValidMove(position, to)) {
        //cout << board->checkValidMove(position, to) << endl;
        board->changeBoard(position, to, piece);
        return true;
    } else {
        return level1(board, isWhite);
    }
    

}

// logic for level 2
bool ComputerPlayer::level2(unique_ptr<Board>& board, bool isWhite) {
    // prefers capturing moves and checks over other moves
    //cout << (isWhite ? "white" : "black") << endl;

    // cout << "2" << endl;
    // map<string, map<string, int>> allMoves(bool isWhite) const; // finds all possible moves and classifies
    Board* temp = dynamic_cast<Board*>(board.get());

    map<string, map<string, int>> allMoves = temp->allMoves(isWhite);
    //cout << "2" << endl;
    string from, to;
    map<string, string> moves;
    map<string, string> moves1;
    

    for (auto& pieceMoves : allMoves) {
        // pieceMoves.first : map<string, char>
        // pieceMoves.second : vector<map<string, int>>
        from = pieceMoves.first;

        map<string, int>& toCoords = pieceMoves.second;

        for (auto & coord : toCoords) {
            to = coord.first;
            if (coord.second > 1) {
                moves[from] = to;
            } else {
                moves1[from] = to;
            }
        }

        
    }

    string fromCoord, toCoord;

    if (moves.size() > 0) {
        auto it = moves.begin();
        advance(it, rand() % moves.size());
        fromCoord = it->first;
        toCoord = it->second;
    } else if (moves1.size() > 0) {
        auto it = moves1.begin();
        advance(it, rand() % moves1.size());
        fromCoord = it->first;
        toCoord = it->second;
    } else {
        return level1(board, isWhite);
    }


    Piece *piece = (*temp).getPiece(fromCoord);
    
    (*board).changeBoard(fromCoord, toCoord, piece->getSymbol());
    return true;

}

// logic for level3
bool ComputerPlayer::level3(unique_ptr<Board>& board, bool isWhite) {
    Board* temp = dynamic_cast<Board*>(board.get());
    map<string, map<string, int>> allMovesOpp = temp->allMoves(!isWhite);
    
    map<string, string> movesOpp;
    map<string, string> avoidCapture;
    map<string, string> avoidCapture1;

    // Collect opponent's capturing moves
    for (auto& pieceMoves : allMovesOpp) {
        string from = pieceMoves.first;
        map<string, int>& toCoords = pieceMoves.second;

        for (auto& coord : toCoords) {
            if (coord.second > 1) {
                movesOpp[from] = coord.first;
            }
        }
    }

    // Find moves to avoid capture
    for (auto& pieceMoves : movesOpp) {
        string couldCapture = pieceMoves.second;
        map<string, int> avoidMove = temp->possibleMoves(couldCapture, isWhite);

        for (auto& move : avoidMove) {
            if (move.second > 1) {
                avoidCapture[couldCapture] = move.first;
            } else {
                avoidCapture1[couldCapture] = move.first;
            }
        }
    }

    string fromCoord, toCoord;

    // Randomly choose a move from the best options
    if (!avoidCapture.empty()) {
        auto it = avoidCapture.begin();
        advance(it, rand() % avoidCapture.size());
        fromCoord = it->first;
        toCoord = it->second;
    } else if (!avoidCapture1.empty()) {
        auto it = avoidCapture1.begin();
        advance(it, rand() % avoidCapture1.size());
        fromCoord = it->first;
        toCoord = it->second;
    } else {
        return level2(board, isWhite);
    }

    // Perform the move
    Piece* piece = temp->getPiece(fromCoord);
    board->changeBoard(fromCoord, toCoord, piece->getSymbol());

    return true;
} 

// makeMove will change the overall state of the board
bool ComputerPlayer::makeMove(std::unique_ptr<Board>& board, const std::string &from, const std::string &to, const std::string &promotion) {
    switch(level) {
        case 1:
            return level1(board, isWhite); // if level 1
            break;
        case 2:
            return level2(board, isWhite); // if level 2
            break;
        case 3:
             return level3(board, isWhite); // if level 3
            break;
    }

    return false;
}
