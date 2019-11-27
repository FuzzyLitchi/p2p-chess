#include "bitboard.h"

#include <iostream>
#include "types.h"

void BitBoard::print() {
  for (u64 x = 0; x < 64; x++) {
    if ((value & ((u64)1 << x)) == ((u64)1 << x)) {
      std::cout << "X ";
    } else {
      std::cout << ". ";
    }
    if (x % 8 == 7) {
      std::cout << "\n";
    }
  }
}
