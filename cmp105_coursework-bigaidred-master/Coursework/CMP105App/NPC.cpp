#include "NPC.h"
#include <iostream>

NPC::NPC()
{
	//TEXTURE LOAD AND SET
	npcTexture.loadFromFile("gfx/npcSheet.png");	//Loads the player's texture upon creation of the player object.
	setTexture(&npcTexture);	//Sets the player's texture to the loaded sprite sheet

	//ANIMATION CREATION
	//Creates idle animation using loaded sprite sheet
	idle.addFrame(sf::IntRect(0, 0, 10, 32));
	idle.addFrame(sf::IntRect(10, 0, 10, 32));
	idle.setFrameSpeed(1.0f/1.0f);	//Framerate is 6fps

	idle.animate(0);	//Activates idle stance as standard animation

	//Creates talk animation using loaded sprite sheet
	talk.addFrame(sf::IntRect(20, 0, 10, 32));
	talk.addFrame(sf::IntRect(30, 0, 10, 32));
	talk.setFrameSpeed(1.0f / 6.0f);	//Framerate is 6fps

	//NPC's text variables set

	npcFont.loadFromFile("font/impact.ttf");
	speech.setFont(npcFont);

	speech.setString("I'm too scared for this jump");
	speech.setCharacterSize(16);
	speech.setPosition(sf::Vector2f(270.0f, 500.0f));
	speech.setFillColor(sf::Color::Yellow);

	//Other important variables set
	setSize(sf::Vector2f(20, 64));
	setCollisionBox(0, 0, 20, 64);
	talkTime = 5.0f;

}

NPC::~NPC()
{

}

void NPC::update(float dt, int scene)
{
	talkTime = talkTime + dt;	//Talk time updated

	//NPC relocated based on level player is on
	if (scene == 0)
	{
		setPosition(sf::Vector2f(650.0f, 536.0f));
	}

	if (scene == 9)
	{
		setPosition(sf::Vector2f(300.0f, 536.0f));
	}

	if (talkTime < 5)
	{
		npcStance = Stance::TALKING;
	}

	else
	{
		npcStance = Stance::IDLE;
	}

	switch (npcStance)
	{
	case(Stance::IDLE):
		idle.animate(dt);
		setTextureRect(idle.getCurrentFrame());
		break;
	case(Stance::TALKING):
		talk.animate(dt);
		setTextureRect(talk.getCurrentFrame());
		break;
	};	
}

void NPC::collisionResponse(GameObject* collider, int scene, GameState* state)
{
	//If player is in tutorial and interacts with NPC, they are returned to menu
	if (scene == 0 && input->isKeyDown(sf::Keyboard::E))
	{
		input->setKeyUp(sf::Keyboard::E);
		state->setCurrentState(State::MENU);
	}

	if (scene == 9 && input->isKeyDown(sf::Keyboard::E) && npcStance != Stance::TALKING)
	{
		input->setKeyUp(sf::Keyboard::E);
		talkTime = 0;
		npcStance == Stance::TALKING;
	}
}

void NPC::setStance(Stance stance)
{
	npcStance = stance;
}

float NPC::getTalkTime()
{
	return talkTime;
}