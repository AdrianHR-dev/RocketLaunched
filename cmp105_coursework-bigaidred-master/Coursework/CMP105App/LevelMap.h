#pragma once

#include "Framework/TileMap.h"

//Map class created for level 1 tile map: inherits from tile map class
class LevelMap : public TileMap
{
public:
	LevelMap();
	~LevelMap();

	void update(float dt);

private:

};
