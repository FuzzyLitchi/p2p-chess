p2p-chess: main.o bitboard.o chessboard.o
	g++ -DQT_WIDGETS_LIB -I/usr/include/qt/QtWidgets -I/usr/include/qt -I/usr/include/qt/QtCore -DQT_GUI_LIB -I/usr/include/qt/QtGui -DQT_CORE_LIB -lQt5Widgets -lQt5Gui -lQt5Core -fPIC -o p2p-chess main.o bitboard.o chessboard.o

main.o: main.cpp bitboard.h
	g++ -c main.cpp

bitboard.o: bitboard.cpp bitboard.h
	g++ -c bitboard.cpp

chessboard.o: chessboard.cpp bitboard.o chessboard.h
	g++ -c chessboard.cpp

clean:
	rm p2p-chess main.o bitboard.o chessboard.o
