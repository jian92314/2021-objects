#ifndef Game_h
#define Game_h
#define MAXROW       16  //y
#define MAXCOL       16  //x
#define BOOM          9  //遊戲結束
#define SAFE         10  //未翻開
#define BOMB         11  //炸彈
class Game
{
private:
	int MAP[MAXROW][MAXCOL];
	int bomb;
public:
	Game();
	int Neighbors(int, int);
	void input_MAP();
	void output_MAP();
	int END;
};
#endif
