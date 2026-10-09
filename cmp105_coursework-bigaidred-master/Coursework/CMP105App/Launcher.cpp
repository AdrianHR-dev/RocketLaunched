#include "Launcher.h"

Launcher::Launcher()
{
	//Loads launcher texture from file and applies it
	launcherTexture.loadFromFile("gfx/Launcher.png");
	setTexture(&launcherTexture);

	//Sets launcher's idle frame for when it may need to be flipped
	idleLauncher.addFrame(sf::IntRect(0, 0, 30, 10));

	//Set launcher size
	setSize(sf::Vector2f(30.0f, 10.0f));

}

Launcher::~Launcher()
{

}
void Launcher::update(float dt)
{
	idleLauncher.animate(dt);	//Launcher idle frame displayed
	setTextureRect(idleLauncher.getCurrentFrame());
}

void Launcher::followPlayer(GameObject* p, Input* input)	//Function takes in player to follow them
{
	setPosition(p->getPosition().x - 5.0f , p->getPosition().y + 26.5f);	//Sets position of launcher to player's hands

	if (input->isKeyDown(sf::Keyboard::A))
	{
		idleLauncher.setFlipped(true);	//If player is facing left, so too will the launcher


		//Displays flipped launcher frame
		idleLauncher.animate(0);
		setTextureRect(idleLauncher.getCurrentFrame());
	}

	else if(input->isKeyDown(sf::Keyboard::D))
	{
		idleLauncher.setFlipped(false);	//Otherwise, if player is going right, launcher faces right

		//Displays standard launcher frame
		idleLauncher.animate(0);
		setTextureRect(idleLauncher.getCurrentFrame());
	}
}
