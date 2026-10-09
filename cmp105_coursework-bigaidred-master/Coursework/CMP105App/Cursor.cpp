#include "Cursor.h"
#include <iostream>

Cursor::Cursor()
{
	cursorTexture.loadFromFile("gfx/Cursor.png");	//Loads cursor sprite sheet
	setTexture(&cursorTexture);	//Sets cursor texture to previously loaded cursor sprite sheet

	//Adds aiming frame and sets it intially
	aim.addFrame(sf::IntRect(0, 64, 64, 64));
	aim.animate(0);
	setTextureRect(aim.getCurrentFrame());

	//Adds explosion frame
	explode.addFrame(sf::IntRect(0, 0, 64, 64));
	
	setSize(sf::Vector2f(16.0f, 16.0f));	//Sets size of cursor object
	setCollisionBox(0, 0, 0, 0);	//Collision box only needed for explosion, so initially set to 0

	//Important member variables set
	time = 0.5f;

}


Cursor::~Cursor()
{

}

void Cursor::handleInput(float dt)
{
	
}

void Cursor::update(float dt)
{

	if (explosion == false)	//If there is no explosion, mouse cursor is set to standard size,texture, position and collision box
	{
		setCollisionBox(0, 0, 0, 0);	
		setSize(sf::Vector2f(24.0f, 24.0f));
		aim.animate(0);
		setTextureRect(aim.getCurrentFrame());
		setPosition(sf::Vector2f(input->getMouseX()-12, input->getMouseY()-12));
	}
		
	else
	{	//Otherwise, cursor is updated to "explosion" settings
		setSize(sf::Vector2f(128.0f, 128.0f));	//Larger size for explosion
		explode.animate(0);	//Explosion animation
		setTextureRect(explode.getCurrentFrame());
		setPosition(sf::Vector2f(x - 64, y - 64));	//Position is held until explosion finishes
		
		time = time + dt;	//Adds dt to time each frame

		if (time >= 0.5f)	//Once half a second has passed, explosion status is set to false
		{
			explosion = false;
		}
	}
}

void Cursor::collisionResponse(GameObject* collider, AudioManager* audio)
{
	if (input->isLeftMouseDown() && explosion == false)
	{
		input->setLeftMouse(Input::MouseState::UP);	//Left mouse reset
		explosion = true;	//Explosion occurs

		audio->playSoundbyName("explosion");	//Explosion sound played

		setCollisionBox(0, 0, 128, 128);	//Collision box set to collision box of explosion
		
		//X and y position of explosion stored
		x = input->getMouseX();
		y = input->getMouseY();
		time = 0.0f;	//Time set to 0 to allow explosion to hold
	}
}

float  Cursor::getTime()	//Time getter
{
	return time;
}

float Cursor::getX()
{
	return x;	//Returns saved x-coord
}

float Cursor::getY()
{
	return y;	//Returns saved y-coord
}


