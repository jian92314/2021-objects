#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "Game.h"
#include "Introduction.h"
#include "End.h"

using namespace std;

int main()
{
	End end;
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

	end.EndPrint();
	return 0;
}
