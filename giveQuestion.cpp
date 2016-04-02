#include"Sudoku.h"

void Sudoku::giveQuestion()
{
	int question[size]={8,0,0,0,0,0,0,0,0,0,0,3,6,0,0,0,0,0,0,7,0,0,9,0,2,0,0,0,5,0,0,0,7,0,0,0,0,0,0,0,4,5,7,0,0,0,0,0,1,0,0,0,3,0,0,0,1,0,0,0,0,6,8,0,0,8,5,0,0,0,1,0,0,9,0,0,0,0,4,0,0};
	int i;
	for(i=0;i<size;++i)
		map[i]=question[i];
	transform();
//	for(i=0;i<size;++i)
//		printf("%d%c",map[i],(i+1)%9==0?'\n':' ');
}
