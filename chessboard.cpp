#include "bitboard.h"
#include "chessboard.h"

#include <iostream>
#include "types.h"

// White
BitBoard ChessBoard::getWhitePawns() {
    return pieces[piece(pawn)] & pieces[piece(white)]; 
}

BitBoard ChessBoard::getWhiteKnights() {
    return pieces[piece(knight)] & pieces[piece(white)]; 
}

BitBoard ChessBoard::getWhiteBishops() {
    return pieces[piece(bishop)] & pieces[piece(white)]; 
}

BitBoard ChessBoard::getWhiteRooks() {
    return pieces[piece(rook)] & pieces[piece(white)]; 
}

BitBoard ChessBoard::getWhiteQueens() {
    return pieces[piece(queen)] & pieces[piece(white)]; 
}

BitBoard ChessBoard::getWhiteKings() {
    return pieces[piece(king)] & pieces[piece(white)]; 
}

// Black
BitBoard ChessBoard::getBlackPawns() {
    return pieces[piece(pawn)] & pieces[piece(black)]; 
}

BitBoard ChessBoard::getBlackKnights() {
    return pieces[piece(knight)] & pieces[piece(black)]; 
}

BitBoard ChessBoard::getBlackBishops() {
    return pieces[piece(bishop)] & pieces[piece(black)]; 
}

BitBoard ChessBoard::getBlackRooks() {
    return pieces[piece(rook)] & pieces[piece(black)]; 
}

BitBoard ChessBoard::getBlackQueens() {
    return pieces[piece(queen)] & pieces[piece(black)]; 
}

BitBoard ChessBoard::getBlackKings() {
    return pieces[piece(king)] & pieces[piece(black)]; 
}
