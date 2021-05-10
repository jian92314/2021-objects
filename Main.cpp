#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "Game.h"
#include "Introduction.h"

using namespace std;

int main()
{
	Introduction i;
	i.print();
	for (int i = 0; i < 100; i++)
	{
		cout << "\t\t\t\t\t\t遊戲加載中..." << i << "%";
		Sleep(80);
		cout << "\r";
	}
	srand(time(NULL));
	Game play1;
	while (play1.END == 0)
	{
		play1.output_MAP();
		play1.input_MAP();
	}

	cout << "\n遊戲結束" << endl;
	return 0;
}
