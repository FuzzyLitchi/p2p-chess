#ifndef CHESSBOARD
#define CHESSBOARD

#include "types.h"
#include <iostream>
#include "bitboard.h"

class ChessBoard {
public:
    BitBoard (&pieces)[8];

    ChessBoard(BitBoard (&p)[8]):pieces(p){
    }

    BitBoard getWhitePawns();

    enum piece {
        white,
        black,
        pawn,
        knight,
        bishop,
        rook,
        queen,
        king
    };

};

#endif