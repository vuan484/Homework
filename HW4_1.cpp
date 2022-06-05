#include<iostream>
#include<cmath>
#define max 100
using namespace std;
void input(int a[][max], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << "enter a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	}
}
void output(int a[][max], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}
int positivesum(int a[][max], int row, int col)
{
	int  s= 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (a[i][j] > 0)
			{
			s += a[i][j];
			}
		}
	}
	return s;
}
 
int main()
{
	int a[max][max];
	int row, col;
	do
	{
		cout << "enter row:" << endl;
		cin >> row;
		if (row<1 || row>max)
		{
			cout << "illegal" << endl;
		}
	} while (row<1 || row>max);
	do
	{
		cout << "enter col:" << endl;
		cin >> col;
		if (col<1 || col>max)
		{
			cout << "illegal:" << endl;
		}
	} while (col<1 || col>max);
	input(a, row, col);
	output(a, row, col);
	cout << "sum=" << positivesum(a, row, col);
}