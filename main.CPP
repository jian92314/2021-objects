#include"Introduction.h"
#include<iostream>
#include<Windows.h>
using namespace std;
int main()
{
	Introduction i;
	i.print();
	for (int i = 0; i < 100; i++)
	{
		cout << "\t\t\t\t\t\t遊戲加載中..."<<i<<"%";
		Sleep(80);
		cout << "\r";
	}

}
