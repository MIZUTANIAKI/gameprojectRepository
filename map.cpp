#include <DxLib.h>
#include "scene/SceneMng.h"
#include "map.h"

Map* Map::sInstance = nullptr;

void Map::Update(void)
{
	lpSceneMng.AddDrawQuenex(mapmodel);	//描画要求
}

Map::Map()
{
	mapmodel = MV1LoadModel("mv/men.mv1");
	MV1SetPosition(mapmodel, VGet(0.0f, 0.0f, 0.0f));	//座標変更

	MV1SetOpacityRate(mapmodel, 0.5f);
}

Map::~Map()
{
}
