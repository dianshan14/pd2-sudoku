#include<iostream>
#include<cstdio>
#include<cstdlib>
class Sudoku{
	public:
		void giveQuestion();
		void readIn();
		void solve();
		void changeNum(int a , int b);
		void changeRow(int a , int b);
		void changeCol(int a , int b);
		void rotate(int n);
		void flip(int n);
		void transform();
		const static int size=81;
		bool go();
		bool checkarr(int in[]);
		bool checkArrFirst(int in[]);
		bool isCorrect();
		void backtracking(int zero_element[],int count_zero,int zero_count,int * count_result,int tmp_store[]);
	private:
		int map[size];
};
