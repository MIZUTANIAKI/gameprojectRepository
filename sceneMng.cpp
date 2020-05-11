#include<DxLib.h>
#include "sceneMng.h"

sceneMng* sceneMng::sInstance = nullptr;

sceneMng::sceneMng()
{
}

sceneMng::~sceneMng()
{
}

void sceneMng::Run(void)
{
	if (SysInit() == true)
	{
		return;
	}

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{

	}
}

bool sceneMng::SysInit(void)
{
	SetGraphMode(1920, 1080, 16);
	ChangeWindowMode(true);										//画面windowﾓｰﾄﾞ
	if (DxLib_Init() == -1)										//DXﾗｲﾌﾞﾗﾘの初期化処理
	{
		return false;
	}
	SetDrawScreen(DX_SCREEN_BACK);
	SetCreate3DSoundFlag(false);
	SetFontSize(60);
	
	return true;
}
