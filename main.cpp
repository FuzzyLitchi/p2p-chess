#include <iostream>
#include "bitboard.h"
//#include "types.h"

int main() 
{
    BitBoard bitboard { 18446462598732906495 };
    BitBoard filter { 89888890099 };

    BitBoard stuff = filter & bitboard;

    bitboard.print();
    std::cout << "\n";
    filter.print();
    std::cout << "\n";
    stuff.print();
    return 0;
}
