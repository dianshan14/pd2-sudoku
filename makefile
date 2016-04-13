Sudoku: Sudoku.h Sudoku.o main.o transform solve giveQuestion
	g++ -o Sudoku Sudoku.o main.o

Sudoku.o: Sudoku.h Sudoku.cpp
	g++ -c Sudoku.cpp

main.o: main.cpp Sudoku.h
	g++ -c main.cpp

giveQuestion: giveQuestion.cpp Sudoku.h Sudoku.o
	g++ -c giveQuestion.cpp
	g++ -o giveQuestion giveQuestion.o Sudoku.o

solve: solve.cpp Sudoku.h Sudoku.o
	g++ -c solve.cpp
	g++ -o solve solve.o Sudoku.o

transform: transform.cpp Sudoku.h Sudoku.o
	g++ -c transform.cpp
	g++ -o transform transform.o Sudoku.o

clean:
	rm  *.o
