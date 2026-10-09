#pragma once

#include "Framework/GameObject.h"
#include "Framework/GameState.h"

class UI : public GameObject
{
public:
	//Public UI functions (Constructor, destructor, update etc.)
	UI();
	~UI();

	void update(float dt);

	//Returns text displaying scene number
	sf::Text* getSceneText()
	{
		return &sceneNumber;
	};

	//returns game over text
	sf::Text* getGameOver()
	{
		return &gameOver;
	};

	//Returns location text
	sf::Text* getLocationText()
	{
		return &location;
	}

	//Returns tutorial text
	sf::Text* getTutorialText(int textLine)
	{
		switch (textLine)
		{
		case(0):
			return &tutorial1;	break;
		case(1):
			return &tutorial2;	break;
		case(2):
			return &tutorial3;	break;
		case(3):
			return &tutorial4;	break;
		case(4):
			return &tutorial5;	break;
		case(5):
			return &tutorial6;	break;
		case(6):
			return &tutorial7;	break;
		case(7):
			return &tutorial8;	break;
		}
	};

	void updateScene(int newScene);

	//Getters and setters
	int getScene();	//Scene getter
	void setScene(int scenUpdate);


	//Getter for play time
	int getTime();
	void setTime(int reset);

private:
	//Private UI variables

	int scene;	//Keeps track of scene number
	float playTime;	//Keeps track of player's play time
	int timeRound;	//Variable used to round time

	sf::Font uIFont;	//Font for ui

	//Text variables
	sf::Text sceneNumber;	
	sf::Text location;
	sf::Text gameOver;
	sf::Text tutorial1;
	sf::Text tutorial2;
	sf::Text tutorial3;
	sf::Text tutorial4;
	sf::Text tutorial5;
	sf::Text tutorial6;
	sf::Text tutorial7;
	sf::Text tutorial8;
};

