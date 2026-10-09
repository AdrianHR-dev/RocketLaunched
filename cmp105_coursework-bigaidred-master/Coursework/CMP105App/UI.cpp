#include "UI.h"
#include <iostream>

UI::UI()
{
	//Sets scene for game start
	scene = 0;

	//Intitialise time
	playTime = 0;

	//Font loaded and applied to each text variable
	uIFont.loadFromFile("font/impact.ttf");
	sceneNumber.setFont(uIFont);
	gameOver.setFont(uIFont);
	location.setFont(uIFont);
	tutorial1.setFont(uIFont);
	tutorial2.setFont(uIFont);
	tutorial3.setFont(uIFont);
	tutorial4.setFont(uIFont);
	tutorial5.setFont(uIFont);
	tutorial6.setFont(uIFont);
	tutorial7.setFont(uIFont);
	tutorial8.setFont(uIFont);

	//All text variables set
	sceneNumber.setString("Level " + std::to_string(scene));
	sceneNumber.setCharacterSize(32);
	sceneNumber.setPosition( 10, 10);
	sceneNumber.setFillColor(sf::Color::Red);

	gameOver.setString("GAME OVER");
	gameOver.setCharacterSize(64);
	gameOver.setPosition(250, 300);
	gameOver.setFillColor(sf::Color::Red);

	location.setString("Plains");
	location.setCharacterSize(32);
	location.setPosition(550, 10);
	location.setFillColor(sf::Color::Red);

	tutorial1.setString("A TO MOVE LEFT"); 
	tutorial1.setCharacterSize(32);
	tutorial1.setPosition(10, 10);
	tutorial1.setFillColor(sf::Color::Red);

	tutorial2.setString("D TO MOVE RIGHT"); 
	tutorial2.setCharacterSize(32);
	tutorial2.setPosition(10, 46);
	tutorial2.setFillColor(sf::Color::Red);

	tutorial3.setString("MOUSE TO MOVE CURSOR"); ;
	tutorial3.setCharacterSize(32);
	tutorial3.setPosition(10, 82);
	tutorial3.setFillColor(sf::Color::Red);

	tutorial4.setString("LEFT MOUSE BUTTON TO LAUNCH"); 
	tutorial4.setCharacterSize(32);
	tutorial4.setPosition(10, 118);
	tutorial4.setFillColor(sf::Color::Red);

	tutorial5.setString("E TO INTERACT WITH NPCS");  
	tutorial5.setCharacterSize(32);
	tutorial5.setPosition(10, 154);
	tutorial5.setFillColor(sf::Color::Red);

	tutorial6.setString("INTERACT WITH NPC TO RETURN TO MENU");
	tutorial6.setCharacterSize(32);
	tutorial6.setPosition(10, 190);
	tutorial6.setFillColor(sf::Color::Red);

	tutorial7.setString("(If you press space in game, you");
	tutorial7.setCharacterSize(32);
	tutorial7.setPosition(10, 226);
	tutorial7.setFillColor(sf::Color::Red);

	tutorial8.setString("get a little treat to help you)");
	tutorial8.setCharacterSize(32);
	tutorial8.setPosition(10, 262);
	tutorial8.setFillColor(sf::Color::Red);

}

UI::~UI()
{

}

void UI::update(float dt)
{
	//Updates play time
	playTime = playTime + dt;
	timeRound = playTime;	//Time rounded

	//Updates text variables
	sceneNumber.setString("Level " + std::to_string(scene));

	//Scene text variable updated based on player's level
	if (scene < 1)
	{
		location.setString("Tutorial");
	}

	else if (scene < 3)
	{
		location.setString("Plains");
	}
	else if (scene < 5)
	{
		location.setString("Hills");
	}
	else if (scene < 7)
	{
		location.setString("Mountains");
	}
	else
	{
		location.setString("Space");
	}
}


void UI::updateScene(int newScene)
{
	scene = scene + newScene;	//Updates scene appropriately
}

//Scene getter
int UI::getScene()
{
	return scene;
}

//Time getter
int UI::getTime()
{
	return timeRound;
}

//Time setter
void UI::setTime(int reset)
{
	playTime = reset;
	timeRound = reset;
}

//Scene setter
void UI::setScene(int newScene)
{
	scene = newScene;
}