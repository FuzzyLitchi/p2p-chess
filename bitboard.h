#ifndef BITBOARD
#define BITBOARD

#include "types.h"

class BitBoard {
public:
  u64 value;

  BitBoard(u64 v) {
    value = v;
  }

  void print();

  BitBoard operator & (BitBoard other) {
    return BitBoard(value & other.value);
  };

  BitBoard operator | (BitBoard other) {
    return BitBoard (value | other.value);
  };

  BitBoard operator ^ (BitBoard other) {
    return BitBoard(value ^ other.value);
  };
};

#endif