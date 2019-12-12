#include "bitboard.h"
#include "chessboard.h"

#include <iostream>
#include "types.h"


    BitBoard ChessBoard::getWhitePawns() {
        return pieces[piece(pawn)] & pieces[piece(white)]; 
    }