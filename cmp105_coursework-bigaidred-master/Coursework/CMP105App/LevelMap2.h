#pragma once

#include "Framework/TileMap.h"

//Map class created for level 2 tile map: inherits from tile map class
class LevelMap2 : public TileMap
{
public:
	LevelMap2();
	~LevelMap2();

	void update(float dt);

private:

};