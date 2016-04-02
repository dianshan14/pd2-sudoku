#include"Sudoku.h"
#include<cstdio>
#include<cstdlib>
using namespace std;

void Sudoku::readIn()
{
	int i;
	for(i=0;i<size;++i)
		scanf("%d",&map[i]);
}
void Sudoku::changeNum(int a , int b)
{
	int i,j,ele,tmp,tmp_a=-1,tmp_b=-1;
	for(i=0;i<9;++i)	
		for(j=0;j<9;++j)
		{
			ele=27*(i/3)+3*(i%3)+9*(j/3)+(j%3);
			if(map[ele]==a)
				tmp_a=ele;
			if(map[ele]==b)
				tmp_b=ele;
			//直接交換X 或是 判斷tmp_a和b不為0 則交換 後設為0
			if(tmp_a!=-1 && tmp_b!=-1)
			{
				tmp=map[tmp_a];
				map[tmp_a]=map[tmp_b];
				map[tmp_b]=tmp;
				tmp_a=-1;
				tmp_b=-1;
			}
		}
	
//	printf("\n");
//	for(i=0;i<size;++i)
//	{
//		printf("%d%c",map[i],((i+1)%9==0)?'\n':' ');
//	}
}
void Sudoku::changeRow(int a , int b)
{
	int select=3*a+b,i,tmp;
	if(select==1 || select==3) //0 1
	{
		for(i=0;i<27;++i)
		{
			tmp=map[i];
			map[i]=map[i+27];
			map[i+27]=tmp;
		}
	}
	if(select==2 || select==6) //0 2
	{
		for(i=0;i<27;++i)
		{
			tmp=map[i];	
			map[i]=map[i+54];
			map[i+54]=tmp;
		}
	}
	if(select==5 || select==7) //1 2
	{
		for(i=0;i<27;++i)
		{
			tmp=map[i+27];
			map[i+27]=map[i+54];
			map[i+54]=tmp;
		}		
	}
	if(select==0 || select==4 || select==8) // 不變
		{;}
//	for(i=0;i<size;++i)
//		printf("%d%c",map[i],(i+1)%9==0?'\n':' ');
}
void Sudoku::changeCol(int a , int b)
{
	int select=3*a+b,i,j,tmp;
	if(select==1 || select==3)
	{
		for(i=0;i<3;++i)
		{
			for(j=0;j<9;++j)
			{
				tmp=map[i+9*j];
				map[i+9*j]=map[i+3+9*j];
				map[i+3+9*j]=tmp;
			}
		}
	}
	if(select==2 || select==6)
	{
		for(i=0;i<3;++i)
		{
			for(j=0;j<9;++j)
			{
				tmp=map[i+9*j];
				map[i+9*j]=map[i+6+9*j];
				map[i+6+9*j]=tmp;
			}
		}
	}
	if(select==5 || select==7)
	{
		for(i=0;i<3;++i)
		{
			for(j=0;j<9;++j)
			{
				tmp=map[i+3+9*j];
				map[i+3+9*j]=map[i+6+9*j];
				map[i+6+9*j]=tmp;
			}
		}
	}
	if(select==0 || select==4 || select==8)
	{;}
//	for(i=0;i<size;++i)
//		printf("%d%c",map[i],(i+1)%9==0?'\n':' ');
}
void Sudoku::rotate(int n)
{
	int i,j,out[size],c,cc;
	if(n%4==0) {;}
	else if(n%4==1)
	{
		c=8;
		for(i=0;i<9;++i)
		{
			for(j=0;j<9;++j)
			{
				out[c+9*j]=map[9*i+j];
			}
			c--;
		}
	}
	else if(n%4==2)
	{
		cc=8;
		for(i=0;i<9;++i)
		{
			c=8;
			for(j=0;j<9;++j)
			{
				out[9*cc+c]=map[9*i+j];
				c--;
			}
			cc--;
		}
	}
	else if(n%4==3)
	{
		for(i=0;i<9;++i)
		{
			c=8;
			for(j=0;j<9;++j)
			{
				out[9*c+i]=map[9*i+j];
				c--;
			}
			
		}
	}
	if(n%4==0)
	{ ;
//			printf("%d%c",map[i],(i+1)%9==0?'\n':' ');
	}
	else
	{
	for(i=0;i<size;++i)
	//	printf("%d%c",out[i],(i+1)%9==0?'\n':' ');
		map[i]=out[i];
	}
}
void Sudoku::flip(int n)
{
	int i,j,out[size],c;
	if(n==0)
	{
		c=8;
		for(i=0;i<9;++i)
		{
			for(j=0;j<9;++j)
			{
				out[9*c+j]=map[9*i+j];
			}
			c--;
		}
	}
	else if(n==1)
	{
		c=8;
		for(i=0;i<9;++i)
		{
			for(j=0;j<9;++j)
			{
				out[c+9*j]=map[i+9*j];
			}
			c--;
		}
	}
	for(i=0;i<size;++i)
	//	printf("%d%c",out[i],(i+1)%9==0?'\n':' ');
		map[i]=out[i];
}
bool Sudoku::isCorrect()
{
	bool check;
	int check_arr[9],ele,i,j;
	for(i=0;i<81;i+=9)
	{
		for(j=0;j<9;++j)
			check_arr[j]=map[i+j];
		check=checkarr(check_arr);
		if(check==false)
			return false;
	}
	for(i=0;i<9;++i)
	{
		for(j=0;j<9;++j)
			check_arr[j]=map[i+9*j];
		check=checkarr(check_arr);
		if(check==false)
			return false;
	}
	for(i=0;i<9;++i)
	{
		for(j=0;j<9;++j)
		{
			ele=27*(i/3)+3*(i%3)+9*(j/3)+(j%3);
			check_arr[j]=map[ele];
		}
		check=checkarr(check_arr);
		if(check==false)
			return false;
	}
	return true;
}
bool Sudoku::go()
{
	bool ok;
	int c_arr[9],ele,i,j;
	for(i=0;i<9;++i)
	{
		for(j=0;j<9;++j)
			c_arr[j]=map[9*i+j];
		ok=checkArrFirst(c_arr);
		if(ok==false)
		//	printf("1 ");
			return false;
	}
	for(i=0;i<9;++i)
	{
		for(j=0;j<9;++j)
			c_arr[i]=map[i+9*j];
		ok=checkArrFirst(c_arr);
		if(ok==false)
		//	printf("2 ");
			return false;
	}
	for(i=0;i<9;++i)
	{
		for(j=0;j<9;++j)
		{
			ele=27*(i/3)+3*(i%3)+9*(j/3)+(j%3);
			c_arr[j]=map[ele];
		}
		ok=checkArrFirst(c_arr);
		if(ok==false)
		//	printf("3 ");
			return false;
	}
	return true;
}
bool Sudoku::checkArrFirst(int in[])
//檢查最開始可不可以做，所以要注意0
{
	int i,fin[9];
	for(i=0;i<9;++i)
		fin[i]=0;
	for(i=0;i<9;++i)
	{
		if(in[i]!=0)//去掉element是0
		{
			++fin[in[i]-1];	//計算 有些是0(沒有這個數字)
			if(fin[in[i]-1]>1) //可以是1和0 不能是>1
			////////////////大錯 in[i]-1超過了
//printf("4 : %d %d/////",in[i]-1,fin[in[i]-1]);//
			return false;
		}
	}	
	return true;
}
bool Sudoku::checkarr(int in[])
{
//檢查最後答案對否 
//必要嗎 ?
	int i,fin[9];
	for(i=0;i<9;++i)
		fin[i]=0;
	for(i=0;i<9;++i)
		++fin[in[i]-1];
	for(i=0;i<9;++i)
		if(fin[i]!=1)
			return false;
	return true;
}

