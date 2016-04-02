out: main.o Sudoku.o giveQuestion.o transform.o solve.o
	g++ -o out main.o Sudoku.o solve.o transform.o giveQuestion.o

main.o: main.cpp Sudoku.h
	g++ -c main.cpp

Sudoku.o: Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp

transform.o: transform.cpp Sudoku.h
	g++ -c transform.cpp

solve.o: solve.cpp Sudoku.h
	g++ -c solve.cpp

giveQusetion.o: giveQuestion.cpp Sudoku.h
	g++ -c giveQuestion.cpp

clean:
	rm out *.o
