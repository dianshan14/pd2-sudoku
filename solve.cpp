#include"Sudoku.h"

void Sudoku::backtracking(int zero_element[],int count_zero,int zero_count,int* count_result,int tmp_store[])
{
	int filter[9]={0,0,0,0,0,0,0,0,0},j,k,l;
	if(count_zero==zero_count)
	{
		if(isCorrect()==true)
		{ 
			for(j=0;j<size;++j)
			{
				tmp_store[j]=map[j];
			}
			++(*count_result);
			if((*count_result)>=2)
			{
				printf("2\n");
				exit(0);
			}
			return;
		}
		else
			return;
	}
	
	int row,culumn,grid;
	row=zero_element[count_zero]/9;
	culumn=zero_element[count_zero]%9;
	grid=27*(row/3)+3*(culumn/3);
	for(j=0;j<9;++j)
	{
		if(map[9*row+j]!=0) //row
			++filter[map[9*row+j]-1];
		if(map[9*j+culumn]!=0)
			++filter[map[9*j+culumn]-1];
	}
	for(k=grid;k<(grid)+27;k+=9)
	{
		for(l=k;l<(k+3);++l)
		{
			if(map[l]!=0)
				++filter[map[l]-1];
		}
	}
	int c=0;
	for(j=0;j<9;++j)//debug 沒有可能的 filter=0代表可以填
		if(filter[j]!=0)
			c++;
	if(c==9) 
	{
		map[zero_element[count_zero]]=0; 
		return;
	}
	int i;
	for(i=0;i<9;++i)
	{
		if(filter[i]==0)
		{
			map[zero_element[count_zero]]=i+1;
			backtracking(zero_element,count_zero+1,zero_count,count_result,tmp_store);
			if(count_zero!=(zero_count-1))
				map[zero_element[count_zero+1]]=0;
		}
	}
}							
void Sudoku::solve()
{
	int zero[size]={0},i,tmp_count=0,n=0,result[size];
	int count_result=0;
	int * ptr=&count_result;
	if(!go()) printf("0\n");
	else
	{
		for(i=0;i<size;++i) //找element
		{	
			zero[i]=-1;
			if(map[i]==0)
			{
				zero[tmp_count]=i;
				++tmp_count;
			}
		}
		for(i=0;i<size;++i)
			if(zero[i]!=(-1))
				n++;
		if(n==0)
		{
			printf("1\n");
			for(i=0;i<size;++i)
				printf("%d%c",map[i],(i+1)%9==0?'\n':' ');
			return ;
		}
		backtracking(zero,0,n,ptr,result);
		if((*ptr)==1)
		{
			printf("1\n");
			for(i=0;i<size;++i)
				printf("%d%c",result[i],(i+1)%9==0?'\n':' ');
		}
		else if((*ptr)!=0 && (*ptr)!=1)
			printf("2\n");
		else
			printf("0\n");
	}
}	
