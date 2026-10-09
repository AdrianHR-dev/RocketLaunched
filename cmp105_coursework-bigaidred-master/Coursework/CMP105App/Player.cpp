#include "Player.h"
#include <iostream>
Player::Player()
{
	//TEXTURE LOAD AND SET
	playerTexture.loadFromFile("gfx/Geezer.png");	//Loads the player's texture upon creation of the player object.
	setTexture(&playerTexture);	//Sets the player's texture to the loaded sprite sheet

	//ANIMATION CREATION
	//Creates idle animation using loaded sprite sheet
	idle.addFrame(sf::IntRect(0, 0, 10, 32));
	idle.animate(0);	//Actiivates idle stance for player spawning

	//Creates walk animation using loaded sprite sheet
	walk.addFrame(sf::IntRect(10, 0, 10, 32));
	walk.addFrame(sf::IntRect(20, 0, 10, 32));
	walk.addFrame(sf::IntRect(30, 0, 10, 32));
	walk.setFrameSpeed(1.0f / 6.0f);	//Framerate is 6fps

	//Creats fall animation
	fall.addFrame(sf::IntRect(0, 32, 10, 32));
	
	//OTHER IMPORTANT VARIABLES SET AT SPAWN
	//Sets important player variables for spawn: Collision, position, size
	setPosition(sf::Vector2f(450, 536));
	setSize(sf::Vector2f(20, 64));
	setCollisionBox(0, 0, 20, 64);
	velocity = (sf::Vector2f(0.7f, 0.0f));	//Set players standard velocity

	//Variables fo gravity calcs. 
	isFalling = false;	//Player is not falling from spawn
	scale = 200.0f;
	gravity = sf::Vector2f(0, 9.8*scale);	//Gravity is 9.8ms^-2, multiplied by scale to keep player from falling too fast

	launchSpeed = 1000.0f;	//Speed for launch set

	//Launcher input set
	launcher.setInput(input);

	//'Baby' mode set
	isBaby = false;

}

Player::~Player()
{

}

void Player::handleInput(float dt)
{
	//Inputs for player walking
	if (input->isKeyDown(sf::Keyboard::D) && isFalling == false)
	{
		if(getPosition().x >= 680)	//If player is at right window border, they may not surpass it
		{
			velocity.x = 0.0f;
		}

		else
		{
			velocity.x = 0.7f;
		}

		walk.setFlipped(false);	//Character faces right if D pressed
		fall.setFlipped(false);

		move(velocity.x, 0);	//Moves the character when D pressed

		//Walk animation active while input triggered
		walk.animate(dt);
		setTextureRect(walk.getCurrentFrame());	//Texture updated to current frame of animation
	
	}

	else if (input->isKeyDown(sf::Keyboard::A) && isFalling == false)
	{
		if (getPosition().x <= 0)	//If player is at window border, he will not be able to move beyond it
		{
			velocity.x = 0.0f;
		}
		else
		{
			velocity.x = 0.7f;
		}
		walk.setFlipped(true);	//Character faces left if A pressed
		fall.setFlipped(true);

		move(-velocity.x, 0);	//Character moves other direction while A is pressed

		//Walk animation active while input triggered
		walk.animate(dt);
		setTextureRect(walk.getCurrentFrame());	//Texture updated to current animation frame
	}	

	else	//If no input, player is idle
	{
		idle.animate(dt);
		setTextureRect(idle.getCurrentFrame());
	}

}

void Player::update(float dt, AudioManager* audio, GameState* state, UI* ui)
{
	launcher.followPlayer(this, input);	//Launcher moves to player each frame
	

	if (state->getCurrentState() != State::GAMEOVER)
	{
		//CODE ADAPTED FROM ABERTAY UNIVERSITY "Computer Games Application Development" COURSE - LECTURE TITLE "Physics", created by Erin Michno Hughes
		if (isFalling == true)
		{
			if (velocity.y > 750)	//Player terminal velocity cannot be exceeded
			{
				velocity.y = 750;
			}

			sf::Vector2f pos = (velocity * dt) + (0.5f * gravity * dt * dt);	//Player's y displacement calculated, position vector created to store it
			velocity = velocity + gravity * dt;	//y velocity is updated based on time falling 
			setPosition(getPosition() + pos);	//Position updated to move player by previously calculated y displacement

			//Fall animation activated if player is falling
			fall.animate(dt);
			setTextureRect(fall.getCurrentFrame());

			if (getPosition().x <= 0)	//If player hits left window border, they will bounce
			{
				setPosition(1, getPosition().y);
				velocity.x = -(velocity.x / 3.0f);
				audio->playSoundbyName("wallHit");	//Hit noise played
			}

			else if (getPosition().x >= window->getSize().x - 20)	//If player hits right window border, they will also bounce
			{
				setPosition(window->getSize().x - 21, getPosition().y);
				velocity.x = -(velocity.x / 3.0f);
				audio->playSoundbyName("wallHit");	//Hit noise played
			}
		}
	}

	//Game checks for possible dialogue options based on playtime
	switch (ui->getTime())
	{
	//Following sounds play at various intervals throughout game
	case(300):
		audio->stopAllSounds();
		audio->playSoundbyName("5");	break;
	case(600):
		audio->stopAllSounds();
		audio->playSoundbyName("10");	break;
	case(1800):
		audio->stopAllSounds();
		audio->playSoundbyName("30");	break;
	case(3600):
		audio->stopAllSounds();
		audio->playSoundbyName("hour");	break;
	case(10800):
		audio->stopAllSounds();
		audio->playSoundbyName("3hour");	break;
	case(43200):
		audio->stopAllSounds();
		audio->playSoundbyName("24hour");	break;
	case(43214):
		state->setCurrentState(State::GAMEOVER);	break;
	case(43218):
		//Map restart occurs before main menu reboot
		ui->setTime(0);
		ui->setScene(1);
		setPosition(sf::Vector2f(450, 536));
		state->setCurrentState(State::MENU);	break;
	}
}

void Player::collisionResponse(GameObject* collider, AudioManager* audio)	
{

	//If player hits bottom of collider, they fall back down
	if (collider->getCollisionBox().top + (collider->getSize().y / 2) <= getCollisionBox().top && getVelocity().y < 0)
	{
		velocity.y = -velocity.y / 2;	//Player bounces back down
		setPosition(sf::Vector2f(getPosition().x, collider->getPosition().y + collider->getSize().y + 1.0f));
		audio->playSoundbyName("wallHit");	//Hit noise played
	}
	
	//If player collides with top of collider, they are no longer falling
	else if (collider->getCollisionBox().top <= getCollisionBox().top + getSize().y && collider->getCollisionBox().top + getSize().y / 16 >= getCollisionBox().top + getSize().y)
	{
		isFalling = false;
		velocity.y = 0.0f;
		setPosition(getPosition().x, collider->getPosition().y - getSize().y);
	}

	//Otherwise, player has hit either left or right wall
	//RIGHT WALL
	else if(collider->getCollisionBox().left + collider->getSize().x >= getCollisionBox().left && collider->getCollisionBox().left + collider->getSize().x <= getCollisionBox().left + getSize().x )
	{
		velocity.x = -velocity.x / 3.0f;	//Player directoin changed to bounce
		setPosition(collider->getPosition().x + collider->getSize().x + 1, getPosition().y);	//Player moved to wall they collided of.
		
		if (isFalling == true)
		{
			audio->playSoundbyName("wallHit");	//Hit noise played
		}
	}

	//LEFT WALL
	else if (collider->getCollisionBox().left <= getCollisionBox().left + getSize().x && collider->getSize().x < 100)
	{
		velocity.x = -velocity.x / 3.0f;	//Player directoin changed to bounce
		setPosition(collider->getPosition().x - getSize().x - 1, getPosition().y);	//Player moved to wall they collided of.
		
		if (isFalling == true)
		{
			audio->playSoundbyName("wallHit");	//Hit noise played
		}
	}
}

//Player's collision response for explosions
void Player::collisionResponseExplosion(GameObject* collider, float dt, float x, float y)
{
	//CODE ADAPTED FROM ABERTAY UNIVERSITY "Computer Games Application Development" COURSE - LECTURE TITLE "Physics", created by Erin Michno Hughes

	//Calculating player's trajectory
	target = sf::Vector2f(x, y);	//Previously saved coords used as point of origin for explosion
	direction = target - getPosition();	//Find the direction to explosion
	direction = VectorHelper::normalise(direction);	//Normalise direction to explosion
	
	velocity = -(direction * launchSpeed);	//Player is launched *away*, so velocity is -(direction*speed)

	setPosition(getPosition() + velocity*dt);	//Player's position updated in correspondence to the velocity from explosion

	isFalling == true;
}

bool Player::getIsFalling()
{
	return isFalling;	//Function returns falling status
}

void Player::setIsFalling(bool setFall)
{
	isFalling = setFall;	//Sets the player's falling status
}

bool Player::getBaby()
{
	return isBaby;
}

void Player::setBaby(bool babyMode)
{	
	isBaby = babyMode;
}