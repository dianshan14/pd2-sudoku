out: Sudoku.o giveQuestion.o transform.o solve.o main.o
	g++ -o out main.o Sudoku.o solve.o transform.o giveQuestion.o

Sudoku.o: Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp

transform.o: transform.cpp Sudoku.h
	g++ -c transform.cpp

solve.o: solve.cpp Sudoku.h
	g++ -c solve.cpp

giveQusetion.o: giveQuestion.cpp Sudoku.h
	g++ -c giveQuestion.cpp

main.o: main.cpp Sudoku.h
	g++ -c main.cpp

clean:
	rm out *.o
