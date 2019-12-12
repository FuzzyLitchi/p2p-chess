#include <iostream>
#include "bitboard.h"
#include "chessboard.h"
//#include "types.h"
#include <QApplication>
#include <QLabel>

int main(int argc, char **argv) 
{
    BitBoard boards[8] = {65535, 18446462598732840960, 71776119061282560, 4755801206503243842, 2594073385365405732, 9295429630892703873, 1152921504606846992, 576460752303423496};
    ChessBoard chessboard {boards};
    //BitBoard bitboard { 18446462598732906495 };
    //BitBoard filter { 89888890099 };
    //BitBoard stuff = filter & bitboard;

    chessboard.getWhitePawns().print();

/*
    bitboard.print();
    std::cout << "\n";
    filter.print();
    std::cout << "\n";
    stuff.print();*/
    QApplication app(argc, argv);
    QLabel hello("Hello world!");

    hello.show();
    return app.exec();
}
