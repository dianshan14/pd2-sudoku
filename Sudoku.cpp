#include"Sudoku.h"
#include<cstdio>
#include<cstdlib>
using namespace std;

void Sudoku::giveQuestion()
{
	int question[size]={8,0,0,0,0,0,0,0,0,0,0,3,6,0,0,0,0,0,0,7,0,0,9,0,2,0,0,0,5,0,0,0,7,0,0,0,0,0,0,0,4,5,7,0,0,0,0,0,1,0,0,0,3,0,0,0,1,0,0,0,0,6,8,0,0,8,5,0,0,0,1,0,0,9,0,0,0,0,4,0,0};
	int i;
	for(i=0;i<size;++i)
		map[i]=question[i];
//	transform();
	for(i=0;i<size;++i)
		printf("%d%c",map[i],(i+1)%9==0?'\n':' ');
}
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

void Sudoku::backtracking(int zero_element[],int count_zero,int zero_count,int* count_result,int tmp_store[])
{
	int filter[9]={0,0,0,0,0,0,0,0,0},j,k,l;
	if(count_zero==zero_count)
	{
		if(isCorrect()==true)
		{ 
//有答案就存 第二答案等等return之後不會print 會出2
		
			for(j=0;j<size;++j){
				tmp_store[j]=map[j];
//				printf("%d%c",tmp_store[j],(j+1)%9==0?'\n':' ');
		}
//	printf("\n");
			++(*count_result);
			if((*count_result)>=2)
			{
				printf("2\n");
				exit(0);
			}
	//	printf("\n");
			return;
		}
		else
			return ;
	}
//	else 
//	{	return ; }
	int row,culumn,grid;
//	for(i=0;i<zero_count;++i) // i跑每個element 過濾
	row=zero_element[count_zero]/9;
	culumn=zero_element[count_zero]%9;
//	grid=find_grid(9*row+culumn);
	grid=27*(row/3)+3*(culumn/3);
//			if(map[zero_element[i]]=)
	for(j=0;j<9;++j)
	{
		if(map[9*row+j]!=0) //row
			++filter[map[9*row+j]-1];
		if(map[9*j+culumn]!=0)
			++filter[map[9*j+culumn]-1];
	}
//	for(k=3*grid;k<(grid+27);k+=9)
//	{
//		for(l=k;l<(k+3);++l)
//		{
//			if(map[l]!=0)
//				++filter[map[l]-1];
//		}	
//	}
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
/////	printf("C:%d zero:%d\n",c,count_zero);//////////////////////////////////////
/////	for(j=0;j<9;j++)
/////		if(filter[j]==0)
/////			printf(" %dok:%d ",zero_element[count_zero],j+1);
	if(c==9) 
	{
		map[zero_element[count_zero]]=0; 
		return;
	}////////////// debug 當return時 現在的地方要保持0
	int i;
	for(i=0;i<9;++i)
	{
		if(filter[i]==0)
		{
			map[zero_element[count_zero]]=i+1;
//	//		if(count_zero!=(zero_count-1))
//	//			map[zero_element[count_zero+1]]=0;
/////	printf("ele:%d-%d\n",zero_element[count_zero],i+1);
			backtracking(zero_element,count_zero+1,zero_count,count_result,tmp_store);
		if(count_zero!=(zero_count-1))
			map[zero_element[count_zero+1]]=0;
			
// //			if(count_zero!=(zero_count-1))
// //			map[zero_element[count_zero]]=0;
//			if((*count_result)>=2)
//			{
//				printf("2\n");
//				exit(1);
//			}
		}
//		if((*count_result)>=2)
//		{
//			printf("2\n");
//			exit(1);
//		}
	}
//	if(i==8) 
//	{
///		map[zero_element[count_zero-1]]=0;
//		return;
//	}//debug1
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
//		for(i=0;i<size;++i)
//			if(zero[i]!=-1)
//			printf("%d\n",i);
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
//		for(i=0;i<size;++i)/////
//			printf("%d ",zero[i]);
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
void Sudoku::transform()
{
	int i;
    srand(time(NULL));
    changeNum(rand()%8+1,rand()%8+2);
    changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
	for(i=0;i<size;++i)
		printf("%d%c",map[i],(i+1)%9==0?'\n':' ');
}
