#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Collision.h"
#include "Player.h"
#include "NPC.h"
#include "Cursor.h"
#include "Ground.h"
#include "Trophy.h"
#include "Background.h"
#include "UI.h"

//All level classes included
#include "LevelMap.h"
#include "LevelMap2.h"
#include "LevelMap3.h"
#include "LevelMap4.h"
#include "LevelMap5.h"
#include "LevelMap6.h"
#include "LevelMap7.h"
#include "LevelMap8.h"
#include "LevelMap9.h"

class Level : BaseLevel{
public:
	Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud);
	~Level();

	void handleInput(float dt) override;
	void update(float dt);
	void render();

private:	
	// Default variables for level class.

	Player player;	//New player object
	NPC npc;	//New NPC object
	Cursor cursor;	//New cursor object
	Ground ground;	//New ground object
	Trophy trophy;	//New trophy object
	Background levelBackground;	//Background for level state created
	UI ui;	//UI created

	//Level map objects
	LevelMap levelMap;	//New object for level 1 tile map
	LevelMap2 levelMap2;	//Object for level 2 map
	LevelMap3 levelMap3;	//Object for level 3 map
	LevelMap4 levelMap4;	//Object for level 4 map
	LevelMap5 levelMap5;	//Object for level 5 map
	LevelMap6 levelMap6;	//Object for level 6 map
	LevelMap7 levelMap7;	//Object for level 7 map
	LevelMap8 levelMap8;	//Object for level 8 map
	LevelMap9 levelMap9;	//Object for level 9 map

	//Font and text created for pause screen
	sf::Font pauseFont;
	sf::Text pauseText;
	
};