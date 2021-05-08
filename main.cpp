#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Game.h"

using namespace std;

int main()
{
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
