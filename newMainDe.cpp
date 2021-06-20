#include "Game.h"
#include <iostream>

using namespace std;

Game::Game()
{

	int col, row;
	bomb = 0;                           //炸彈數為0
	END = 0;                            //1為結束

	for (int r = 0; r < MAXROW; r++)           //全部歸為未翻開區域,並且為安全區域
	{
		for (int c = 0; c < MAXCOL; c++)
		{
			MAP[r][c] = SAFE;
		}
	}

	for (bomb = 1; bomb <= 40; bomb++)        //亂數散播炸彈
	{

		row = (rand() % (MAXROW)) + 0;
		col = (rand() % (MAXCOL)) + 0;

		if (MAP[row][col] != BOMB)
			MAP[row][col] = BOMB;
		else
			bomb = bomb - 1;
	}
}
int Game::Neighbors(int col, int row)
{
	int COUNT = 0, c, r;

	if (row - 1 >= 0 && row - 1 <= MAXROW)
		r = row - 1;
	else
		r = row;

	if (col - 1 >= 0 && col - 1 <= MAXCOL)
		c = col - 1;
	else
		c = col;

	if (MAP[r][c] == BOMB)                         //判斷是否為炸彈
		return BOOM;

	for (r = row - 2; r <= row; r++)                  //計算週遭炸彈數量
	{
		for (c = col - 2; c <= col; c++)
		{
			if (r < 0 || r >= MAXROW || c < 0 || c >= MAXCOL)
			{
				continue;
			}
			if (MAP[r][c] == BOMB)
			{
				COUNT++;
			}
		}
	}
	MAP[row - 1][col - 1] = COUNT;

	return COUNT;
}
void Game::input_MAP()
{
	int col, row;

	cout << "此遊戲為踩地雷,請輸入先輸入x(1~16)再輸入y(1~16)" << endl;
	cin >> col >> row;
	if(col > 16 || col < 0 && row > 16 || row < 0)   //判斷輸入值
	{
		cout << "請輸入x範圍(1~16)再輸入y範圍(1~16)" << endl;
		cin >> col >> row;
	}
	if (col == -1)
	{
		cout << "請輸入x範圍(1~16)再輸入y範圍(1~16)" << endl;
		cin >> col >> row;
	}
	if (row == -1)
	{
		cout << "請輸入x範圍(1~16)再輸入y範圍(1~16)" << endl;
		cin >> col >> row;
	}
	if (Neighbors(col, row) == 9)
	{
		END = 1;
	}
}
void Game::output_MAP()
{
	system("cls");
	cout << "   1  2  3  4  5  6  7  8  9  "
		<< "10 11 12 13 14 15 16" << endl;
	for (int r = 0; r < MAXROW; r++)
	{
		cout << r + 1;
		if (r < 9)
			cout << "  ";
		if (r >= 9)
			cout << " ";
		for (int c = 0; c < MAXCOL; c++)
		{
			if (MAP[r][c] >= 9)
			{
				cout << "*";
				cout << "  ";
			}
			else if (MAP[r][c] < 9 && MAP[r][c] >= 0)
			{
				cout << MAP[r][c];
				cout << "  ";
			}
		}
		cout << endl;
	}
}
