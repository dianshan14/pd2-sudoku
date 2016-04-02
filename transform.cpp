#include"Sudoku.h"

void Sudoku::transform()
{
	srand(time(NULL));
	changeNum(rand()%8+1,rand()%8+2);
	changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
	int i;
	for(i=0;i<size;++i)
		printf("%d%c",map[i],(i+1)%9==0?'\n':' ');
}
