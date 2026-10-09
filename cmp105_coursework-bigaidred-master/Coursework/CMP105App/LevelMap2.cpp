#include "LevelMap2.h"

LevelMap2::LevelMap2()
{
	//CODE ADAPTED FROM ABERTAY UNIVERSITY "Computer Games Application Development" COURSE - LECTURE TITLE "Tile-Based Rendering", created by William Kavanagh
	//2023	
	loadTexture("gfx/TileSheet.png");	//Tile sheet loaded

	GameObject tile;	//Creates a tile object

	//Creating tiles
	for (int counter = 0; counter < 19; counter++)
	{
		tile.setSize(sf::Vector2f(50, 50));
		tile.setCollisionBox(0, 0, 50, 50);
		tile.setCollider(true);
		tileSet.push_back(tile);
	}

	//Setting tile set textures
	tileSet[0].setCollider(false);
	tileSet[0].setTextureRect(sf::IntRect(80, 20, 20, 20));
	tileSet[1].setTextureRect(sf::IntRect(0, 0, 20, 20));
	tileSet[2].setTextureRect(sf::IntRect(20, 0, 20, 20));
	tileSet[3].setTextureRect(sf::IntRect(40, 0, 20, 20));
	tileSet[4].setTextureRect(sf::IntRect(60, 0, 20, 20));
	tileSet[5].setTextureRect(sf::IntRect(80, 0, 20, 20));
	tileSet[6].setTextureRect(sf::IntRect(100, 0, 20, 20));
	tileSet[7].setTextureRect(sf::IntRect(120, 0, 20, 20));
	tileSet[8].setTextureRect(sf::IntRect(0, 20, 20, 20));
	tileSet[9].setTextureRect(sf::IntRect(20, 20, 20, 20));
	tileSet[10].setTextureRect(sf::IntRect(40, 20, 20, 20));
	tileSet[11].setTextureRect(sf::IntRect(60, 20, 20, 20));
	tileSet[12].setTextureRect(sf::IntRect(0, 40, 20, 20));
	tileSet[13].setTextureRect(sf::IntRect(20, 40, 20, 20));
	tileSet[14].setTextureRect(sf::IntRect(40, 40, 20, 20));
	tileSet[15].setTextureRect(sf::IntRect(60, 40, 20, 20));
	tileSet[16].setTextureRect(sf::IntRect(80, 40, 20, 20));
	tileSet[17].setTextureRect(sf::IntRect(100, 40, 20, 20));
	tileSet[18].setTextureRect(sf::IntRect(120, 40, 20, 20));

	//Setting dimension of level

	mapDimensions = sf::Vector2u(14, 14);

	setPosition(sf::Vector2f(0, 0));

	//Level two map set and loaded
	tileMap = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 9, 10, 0, 0,
		0, 0, 0, 8, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 8, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 8, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 8, 9, 9, 9, 9, 9, 9, 9, 9, 10,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};

	buildLevel();
}

LevelMap2::~LevelMap2()
{

}

void LevelMap2::update(float dt)
{

}
