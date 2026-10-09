#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	//INITIALISING OBJECTS 

	//Player input and window set
	player.setInput(input);
	player.setWindow(window);

	//NPC input
	npc.setInput(input);

	//Cursor input and window set
	cursor.setInput(input);
	cursor.setWindow(window);

	//Scene set for game start
	ui.setScene(1);

	//Hides cursor for new cursor texture to show
	window->setMouseCursorVisible(false);

	//Audio files loaded
	audio->addSound("sfx/Bonk.ogg", "wallHit");
	audio->addSound("sfx/Explosion.ogg", "explosion");

	//Various dialogue sound files loaded
	audio->addSound("sfx/5minutes.ogg", "5");
	audio->addSound("sfx/10minute.ogg", "10");
	audio->addSound("sfx/30minute.ogg", "30");
	audio->addSound("sfx/1hour.ogg", "hour");
	audio->addSound("sfx/3hour.ogg", "3hour");
	audio->addSound("sfx/24hour.ogg", "24hour");

	//Font and text for pause screen initialised
	pauseFont.loadFromFile("font/impact.ttf");
	pauseText.setFont(pauseFont);

	pauseText.setString("PAUSED");
	pauseText.setCharacterSize(64);
	pauseText.setPosition(250, 300);
	pauseText.setFillColor(sf::Color::Red);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Escape))	//If player presses escape key, game will pause or unpause as appropriate
	{

		input->setKeyUp(sf::Keyboard::Escape);	//Resets key
		if (gameState->getCurrentState() != State::PAUSE)
		{
			gameState->setCurrentState(State::PAUSE);
		}
		else
		{
			gameState->setCurrentState(State::LEVEL);
		}
	}

	//ADMIN MODE
	if (input->isKeyDown(sf::Keyboard::Space))
	{ 
		input->setKeyUp(sf::Keyboard::Space);
		ui.updateScene(1);
		player.setPosition(sf::Vector2f(300, 400));
		player.setBaby(true);
	}

	player.handleInput(dt);
	cursor.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	ui.update(dt);
	player.update(dt, audio, gameState, &ui);
	//Following objects only updated if game over state isn't triggered (24 hours no win)
	if (gameState->getCurrentState() != State::GAMEOVER)
	{
		cursor.update(dt);
		ground.update(dt);
		levelBackground.update(dt, gameState, ui.getScene());

		//Level map updated when appropriate
		if (player.getPosition().y > window->getSize().y)
		{
			//Player sent towards screen top to continue falling
			player.setPosition(player.getPosition().x, -(player.getSize().y / 3));
			ui.updateScene(-1);
		}

		else if (player.getPosition().y < -(player.getSize().y) / 2)
		{
			//Player sent to bottom of screen to continue ascent
			player.setPosition(player.getPosition().x, window->getSize().y);
			ui.updateScene(1);
		}

		//COLLISION CHECKS

		//PLAYER COLLISIONS

		if (Collision::checkBoundingBox(&player, &ground) && ui.getScene() == 1)	//Checks for collision between player and ground (lowest point in game)
		{
			player.collisionResponse(&ground, audio);
		}
		else
		{	//Player is falling
			player.setIsFalling(true);
		}

		//TILE MAP COLLISION
		switch (ui.getScene())
		{
		//Switch statement determines which tilemap to check collision for
		//CODE ADAPTED FROM ABERTAY UNIVERSITY "Computer Games Application Development" COURSE - LECTURE TITLE "Tile-Based Rendering", created by William Kavanagh
		//2023	
		case(1):

			for (GameObject tile : *levelMap.getLevel())
			{
				if (tile.isCollider())
				{
					if (Collision::checkBoundingBox(&tile, &player) && tile.isCollider())
					{
						player.collisionResponse(&tile, audio);
					}

					if (Collision::checkBoundingBox(&tile, cursor.getPosition()))
					{
						cursor.collisionResponse(NULL, audio);
					}
				}
			}; break;
		case(2):

			for (GameObject tile : *levelMap2.getLevel())
			{
				if (tile.isCollider())
				{
					if (Collision::checkBoundingBox(&tile, &player) && tile.isCollider())
					{
						player.collisionResponse(&tile, audio);
					}

					if (Collision::checkBoundingBox(&tile, cursor.getPosition()))
					{
						cursor.collisionResponse(NULL, audio);
					}
				}
			}; break;
		case(3):
			for (GameObject tile : *levelMap3.getLevel())
			{
				if (tile.isCollider())
				{
					if (Collision::checkBoundingBox(&tile, &player) && tile.isCollider())
					{
						player.collisionResponse(&tile, audio);
					}

					if (Collision::checkBoundingBox(&tile, cursor.getPosition()))
					{
						cursor.collisionResponse(NULL, audio);
					}
				}
			}; break;
		case(4):
			for (GameObject tile : *levelMap4.getLevel())
			{
				if (tile.isCollider())
				{
					if (Collision::checkBoundingBox(&tile, &player) && tile.isCollider())
					{
						player.collisionResponse(&tile, audio);
					}

					if (Collision::checkBoundingBox(&tile, cursor.getPosition()))
					{
						cursor.collisionResponse(NULL, audio);
					}
				}
			}; break;
		case(5):
			for (GameObject tile : *levelMap5.getLevel())
			{
				if (tile.isCollider())
				{
					if (Collision::checkBoundingBox(&tile, &player) && tile.isCollider())
					{
						player.collisionResponse(&tile, audio);
					}

					if (Collision::checkBoundingBox(&tile, cursor.getPosition()))
					{
						cursor.collisionResponse(NULL, audio);
					}
				}
			}; break;
		case(6):
			for (GameObject tile : *levelMap6.getLevel())
			{
				if (tile.isCollider())
				{
					if (Collision::checkBoundingBox(&tile, &player) && tile.isCollider())
					{
						player.collisionResponse(&tile, audio);
					}

					if (Collision::checkBoundingBox(&tile, cursor.getPosition()))
					{
						cursor.collisionResponse(NULL, audio);
					}
				}
			}; break;
		case(7):
			for (GameObject tile : *levelMap7.getLevel())
			{
				if (tile.isCollider())
				{
					if (Collision::checkBoundingBox(&tile, &player) && tile.isCollider())
					{
						player.collisionResponse(&tile, audio);
					}

					if (Collision::checkBoundingBox(&tile, cursor.getPosition()))
					{
						cursor.collisionResponse(NULL, audio);
					}
				}
			}; break;
		case(8):
			for (GameObject tile : *levelMap8.getLevel())
			{
				if (tile.isCollider())
				{
					if (Collision::checkBoundingBox(&tile, &player) && tile.isCollider())
					{
						player.collisionResponse(&tile, audio);
					}

					if (Collision::checkBoundingBox(&tile, cursor.getPosition()))
					{
						cursor.collisionResponse(NULL, audio);
					}
				}
			}; break;
		case(9):
			trophy.update(dt);	//Trophy update called in scene 9 only
			npc.update(dt, ui.getScene());	//NPC update only called in scene 9 as well

			for (GameObject tile : *levelMap9.getLevel())
			{
				if (tile.isCollider())
				{
					if (Collision::checkBoundingBox(&tile, &player) && tile.isCollider())
					{
						player.collisionResponse(&tile, audio);
					}

					if (Collision::checkBoundingBox(&tile, cursor.getPosition()))
					{
						cursor.collisionResponse(NULL, audio);
					}
				}
			}; 
			//Trophy also included in scene 9 collision
			if (Collision::checkBoundingBox(&player, &trophy))
			{
				//Game reset for if player wishes to play again
				ui.setTime(0);
				ui.setScene(1);
				player.setPosition(sf::Vector2f(450, 536));
				player.setVelocity(sf::Vector2f(0.0f, 0.0f));

				if (player.getBaby() == true)
				{
					gameState->setCurrentState(State::BADEND);
				}
				else
				{
					gameState->setCurrentState(State::GOODEND);
				}
			}
			//NPC also collidable in level 9
			if (Collision::checkBoundingBox(&player, &npc))
			{
				npc.collisionResponse(NULL, ui.getScene(), gameState);
			}
			else
			{
				//npc.setStance(Stance::IDLE);
			}
			break;
		}



		//CURSOR COLLISIONS

		if (Collision::checkBoundingBox(&ground, cursor.getPosition()) && ui.getScene() == 1)	//Cursor collision with ground
		{
			cursor.collisionResponse(NULL, audio);
		}



		if (Collision::checkBoundingBox(&player, &cursor) && cursor.getTime() < dt * 2)	//Checks for cursor - player collision, only possible when explosion occurs
		{
			player.collisionResponseExplosion(NULL, dt, cursor.getX(), cursor.getY());
		}
	}
}

	

// Render level
void Level::render()
{
	beginDraw();

	window->draw(levelBackground);
	switch (ui.getScene())
	{
	//Switch statement determines which tile map to render
	case(1):
		window->draw(ground);
		levelMap.render(window); break;
	case(2):
		levelMap2.render(window); break;
	case(3):
		levelMap3.render(window); break;
	case(4):
		levelMap4.render(window); break;
	case(5):
		levelMap5.render(window);	break;
	case(6):
		levelMap6.render(window);	break;
	case(7):
		levelMap7.render(window);	break;
	case(8):
		levelMap8.render(window);	break;
	case(9):
		levelMap9.render(window);
		window->draw(npc);	//NPC also drawn into level 9
		if (npc.getTalkTime() < 5)
		{
			window->draw(*npc.getSpeech());
		}
		window->draw(trophy);	//Trophy also drawn in scene 9
	}


	window->draw(player);
	window->draw(*player.getLauncher());
	window->draw(cursor);
	window->draw(*ui.getSceneText());
	window->draw(*ui.getLocationText());

	if (gameState->getCurrentState() == State::PAUSE)
	{
		window->draw(pauseText);
	}

	if (gameState->getCurrentState() == State::GAMEOVER)
	{
		window->draw(*ui.getGameOver());
	}

	endDraw();
}

