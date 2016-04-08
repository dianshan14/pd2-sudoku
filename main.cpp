#include<cstdio>
#include<cstdlib>
#include<iostream>
#include"Sudoku.h"
using namespace std;

int main()
{
	Sudoku s;
	int i;
	s.readIn();
	printf("\n");
	int a,b;
	//  scanf("%d",&a);
	//  scanf("%d %d",&a,&b);
	//  while(scanf("%d",&a)!=EOF)
	//  s.flip(0);
	//  printf("%d\n",s.isCorrect());
	s.solve();
	//  s.rotate(a);
}

