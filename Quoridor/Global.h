#pragma once

#include "stdafx.h"

using namespace std;

#define SIZE_SQUARE		40
#define SIZE_WALL		8
#define STARTAXIS_X		280
#define STARTAXIS_Y		100
#define NUM_SQUARE		7
#define WALLNUM			8



#define RGBA(r,g,b,a)	((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16))|(((DWORD)(BYTE)(a))<<24)))
#define COLOR_BLACK		RGB(0, 0, 0)
#define COLOR_RED		RGB(255, 0, 0)
#define COLOR_EMPTY		RGB(240, 240, 240)

#define CONDITION_PLAYER1_WIN(p)	( p.y == NUM_SQUARE - 1 )
#define CONDITION_PLAYER1_START(p)	{ p.x = (NUM_SQUARE - 1) / 2; p.y = 0; }
#define CONDITION_PLAYER2_WIN(p)	( p.y == 0 )
#define CONDITION_PLAYER2_START(p)	{ p.x = (NUM_SQUARE - 1) / 2; p.y = NUM_SQUARE - 1; }
#define CONDITION_PLAYER3_WIN(p)	( p.x == NUM_SQUARE - 1 )
#define CONDITION_PLAYER3_START(p)	{ p.x = 0; p.y = (NUM_SQUARE - 1) / 2; }
#define CONDITION_PLAYER4_WIN(p)	( p.x == 0 )
#define CONDITION_PLAYER4_START(p)	{ p.x = NUM_SQUARE - 1; p.y = (NUM_SQUARE - 1) / 2; }

enum OrderType {
	WALLH,
	WALLV,
	MOVE,
	NONE,
};

struct Order {
	OrderType type;
	CPoint point;
	Order() { type = NONE; point = CPoint(0, 0); };
	Order(int t, CPoint p) : type((OrderType)t), point(p) {}
	Order(int t, int x, int y) : type((OrderType)t), point(CPoint(x, y)) {}
};

#define MAX_PLAYER_NUM  4
enum Players
{
	EMPTY = -1,
	PLAYER1 = 0,
	PLAYER2 = 1,
	PLAYER_NUM = 2,
};

#define TEXT_HELP \
"欢迎，这是一个步步为营游戏\r\n\r\n\r\n\
选择先手后开始游戏\r\n\r\n\r\n规则：\r\n\r\n\
--游戏开始时，角色放在边界，开始走向对面边界。每个玩家都有 8 块障碍，\
每个回合你可以选择移动自己的小人一格，或者选择摆放一块障碍阻挡对方，\
谁最先到达对面边界则为胜利者。\r\n\r\n\r\n\
\r\n\r\n\r\n作者：刘力铭\r\n\
时间：2018.8.6\r\n"
