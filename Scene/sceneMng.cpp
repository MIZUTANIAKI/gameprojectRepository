#include<DxLib.h>
#include "sceneMng.h"
#include "GameScene.h"

SceneMng* SceneMng::sInstance = nullptr;


SceneMng::SceneMng()
{
}

SceneMng::~SceneMng()
{
}

void SceneMng::AddDrawQue(int que)
{
	//描画用のQueを追加
	_drawList.emplace_back(que);
}

void SceneMng::AddDrawQuenex(int que)
{
	//描画用のQueを追加
	_drawListnex.emplace_back(que);
}

void SceneMng::Draw(void)
{
	ClsDrawScreen();

		//一つずつ描画
	for (auto dQue : _drawList)
	{
		MV1DrawModel(dQue);
	}

	//すけるのを描画
	for (auto dQue : _drawListnex)
	{
		MV1DrawModel(dQue);
	}
	DrawSphere3D(VGet(0.0f, 0.0f, 0.0f), 100.0f, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);	//通常物をすべて描画後、ガラスなどの透けたいものを描画するといい



	ScreenFlip();
}

void SceneMng::Run(void)
{
	if (SysInit() != true)
	{
		return;
	}
	_activeScene = std::make_unique<GameScene>();
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		_drawList.clear();
		_drawListnex.clear();
		_activeScene = (*_activeScene).Update(std::move(_activeScene));
		Draw();
		_fcon++;
	}
}

bool SceneMng::SysInit(void)
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
	SetBackgroundColor(100, 255, 255);
	SetUseZBufferFlag(TRUE);
	return true;
}
