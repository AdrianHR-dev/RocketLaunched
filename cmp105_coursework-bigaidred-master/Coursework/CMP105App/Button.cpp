#include "Button.h"

Button::Button()
{
	//Load and set button texture
	startTexture.loadFromFile("gfx/PlayButton.png");
	helpTexture.loadFromFile("gfx/HelpButton.png");
	creditsTexture.loadFromFile("gfx/CreditsButton.png");

	setSize(sf::Vector2f(150.0f, 100.0f));
	setCollisionBox(0, 0, 150.0f, 100.0f);

	//Adding animation frames
	idle.addFrame(sf::IntRect(0, 0, 150, 100));
	select.addFrame(sf::IntRect(0, 100, 150, 100));

	//Sets button to spawn with idle animation
	idle.animate(0);
	setTextureRect(idle.getCurrentFrame());

}

Button::~Button()
{

}

void Button::update(float dt)
{

	switch (type)
	{
	case(Type::PLAY):
	{
		//Texture set
		setTexture(&startTexture);
		
		//Type specific variables set
		setPosition(sf::Vector2f(275.0f, 300.0f));

	};	break;
	case(Type::HELP):
	{
		//Help texture set
		setTexture(&helpTexture);

		//Type specific variables set
		setPosition(sf::Vector2f(275.0f, 450.0f));
	};	break;
	case(Type::CREDITS):
	{
		//Help texture set
		setTexture(&creditsTexture);

		//Type specific variables set
		setPosition(sf::Vector2f(275.0f, 600.0f));
	};	break;
	}
	//Resets button texture if its not being hovered over by cursor
	idle.animate(0);
	setTextureRect(idle.getCurrentFrame());
}

void Button::collisionResponse(GameObject* collider)
{
	//Changes button texture when hovered over
	select.animate(0);
	setTextureRect(select.getCurrentFrame());
}

Type Button::getType()
{
	return type;
}

void Button::setType(Type buttonType)
{
	type = buttonType;
}
