p2p-chess: main.o bitboard.o
	g++ -o p2p-chess main.o bitboard.o

main.o: main.cpp bitboard.h
	g++ -c main.cpp

bitboard.o: bitboard.cpp bitboard.h
	g++ -c bitboard.cpp

clean:
	rm p2p-chess main.o bitboard.o
