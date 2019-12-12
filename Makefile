p2p-chess: main.o bitboard.o chessboard.o
	g++ -o p2p-chess main.o bitboard.o chessboard.o

main.o: main.cpp bitboard.h
	g++ -c main.cpp

bitboard.o: bitboard.cpp bitboard.h
	g++ -c bitboard.cpp

chessboard.o: chessboard.cpp bitboard.o chessboard.h
	g++ -c chessboard.cpp

clean:
	rm p2p-chess main.o bitboard.o chessboard.o
