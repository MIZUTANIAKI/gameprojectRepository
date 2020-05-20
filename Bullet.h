#pragma once
#include <tuple>
#include <vector>
#include "obj.h"

#define S_GRAVITY -9.8/60 //重力加速度

#define BULLETMAX 2

class Bullet
{
public:
	Bullet();
	~Bullet();

	void Run(void);

	void SetBullet(VECTOR pos,VECTOR vec);
private:
	VECTOR	_pos[BULLETMAX];
	VECTOR	_direction[BULLETMAX];
	bool	_Shotflag[BULLETMAX];

	int		bulletobj;			//
	int		bulletmodel[BULLETMAX];
	int		_bulletCon[BULLETMAX];
};

