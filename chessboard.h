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
    BitBoard getWhiteKnights();
    BitBoard getWhiteBishops();
    BitBoard getWhiteRooks();
    BitBoard getWhiteQueens();
    BitBoard getWhiteKings();

    BitBoard getBlackPawns();
    BitBoard getBlackKnights();
    BitBoard getBlackBishops();
    BitBoard getBlackRooks();
    BitBoard getBlackQueens();
    BitBoard getBlackKings();

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