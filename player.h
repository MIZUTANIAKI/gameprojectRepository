#pragma once
#include "obj.h"

// 移動速度
#define MOVESPEED					10.0f

class Player :
	public Obj
{
public:
	Player();
	~Player();
	void Updata(void);
private:
	VECTOR _pos;
	int    playerobj;			//ﾌﾟﾚｲﾔモデル格納用
};

