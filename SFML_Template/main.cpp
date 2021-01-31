#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <list>
#include <iostream>
#include "Player.h"
#include "Aliens.h"
#include "Projectile.h"
#include "Colliders.h"
#include "Audio.h"
#include "GameOver.h"
#include "Win.h"
#include <vector>
#include <stdexcept>




using namespace std;

int main()
{
	const float playerSpeed = 450.f; //sets the players speed variable to a constant 450.f
	const int invaderMaxSpeed = 1000; //max speed of the invaders is 1000
	const int invaderMinSpeed = 400; //minimum speed of the invaders is 400
	const float projectileSpeed = 400.f;//projectile speed matches the invaders minimum speed
	bool gameOver = false;
	bool victory = false;

	Win win;
	GameOver lose;

	sf::RenderWindow window(sf::VideoMode(500, 600), "SPACE INVADERS", sf::Style::Default); //draws the actual window for the game to take place in
	window.setVerticalSyncEnabled(true);

	Audio music; //the music under the audio class begins to play
	music.PlayMusic();

	Projectile projectile(0, projectileSpeed);
	Player player(0, playerSpeed);
	player.setLocation(250, 500-player.getSprite().getGlobalBounds().height); //sets location of the player sprite
	
	
	Aliens invaderArray [6]; //created an array for the invaders to spawn in, allowing multiple invaders to spawn
	for (int i = 0; i < 6; i++)
	{
		{
			Aliens alien(i, invaderMinSpeed + (rand() % invaderMaxSpeed)); //randomly selects the speed of each invader spawned from the minumum speed to the mak speed
			alien.setLocation(i * 75 + 50, alien.getSprite().getGlobalBounds().height / 2); //sets location of the alien sprites.
			invaderArray[i] = alien;
		
		}
	}

	sf::Clock clock; //creates the main clock class
	sf::Clock alienClock; //this is a clock used exlusively for the aliens
	alienClock.restart().asSeconds(); //represents the time on the clock as seconds
	sf::Clock projectileClock; //personal clock for the projectile
	projectileClock.restart().asSeconds(); //cooldown for the porojectiles
	

	while (window.isOpen()) //main game while loop
	{
		float Time = clock.restart().asSeconds();
		sf::Event event; //makes the event take place
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) //when the escape key is pressed the game will exit
			{
				if (gameOver) //if the game over class is triggered it will restart the clock
				{
					gameOver = false;
					clock.restart();
					for (int i = 0; i < 11; i++)
					{
						for (int j = 0; j < 5; j++)
						{
							Aliens alien(i, invaderMinSpeed + (rand() % invaderMaxSpeed));
							alien.setLocation(i * 75 + 50, alien.getSprite().getGlobalBounds().height / 2); //meant to reset the array 
							invaderArray[i] = alien;
						}
					}
					player.setLocation(250, 500); //respawns the player
					player.respawn();
					music.PlayMusic();//restarts the background music
			
				}
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) //when the space key is pressed it fires a projectile from the player
			{
				if (!projectile.isAlive() && !gameOver)
				{
					projectile.spawn(true);
					projectile.setLocation(player.getSprite().getPosition().x + 31, player.getSprite().getPosition().y - 15); //gets the players position and spawns the bullet from the player
				}
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) //when the escape key is pressed the game will exit
			{
				window.close();
			}
		}

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
		{
			if (player.getSprite().getPosition().x + player.getSprite().getGlobalBounds().width < 500) //allows the player to move to the right of the screen if the players position in the window is less than 500
			{
				
				player.getSprite().move(playerSpeed * Time, 0.f);
			}
		}

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) //allows the player to move left if the players position is grerater than 0
		{
			if (player.getSprite().getPosition().x > 0.f)
			{
				
				player.getSprite().move(-playerSpeed * Time, 0.f);
			}
		}

		sf::Time t = alienClock.getElapsedTime(); //puts "t" under the Time Class
		
		if (t.asSeconds() > 0.5)
		{
			for (size_t i = 0; i < 6; i++)
			{
				invaderArray[i].getSprite().move(0.f, invaderArray[i].getSpeed()*Time); //allows the aliens to move down with the clock being used for ticks
			}
			alienClock.restart();
		}
		window.clear(); //clears window so there aren't multiple aliens being spawned
		sf::Time pc = projectileClock.getElapsedTime(); 
		if (pc.asSeconds() > 1.0)
		{
			if (projectile.isAlive() && !gameOver)
			{
				projectile.draw(window);
				projectile.getSprite().move(0.f, -20);
			}
		}
		for (int i = 0; i < 6; i++)
		{
			if (Colliders::collidesWith(player, invaderArray[i]) && invaderArray[i].isAlive()) //makes the alien collide with the player causing game over
			{
				if (!gameOver)
					music.ShipHit();
				player.kill(); 
				gameOver = true;
				
			}
		}
		for (int i = 0; i < 6; i++)
		{
			if (Colliders::collidesWith(projectile, invaderArray[i]) && invaderArray[i].isAlive()) //when the projectile collides with the aliens the invader is subsequently killed
			{
				music.InvaderHit();
				invaderArray[i].kill();
				projectile.kill();
			}
		}

		int aliensDefeated = 0;

		for (int i = 0; i < 6; i++)
		{
			if (!invaderArray[i].isAlive())
				aliensDefeated++;

			if (aliensDefeated == 6)
			{
				if (!gameOver)
				victory = true;
				gameOver = true;
			}
		}

		if (projectile.getSprite().getPosition().y < 0) //eliminates the projectile after hitting the aliens
			projectile.kill();

		if (!gameOver)
		{
			for (size_t i = 0; i < 6; i++)
			{
				if (invaderArray[i].isAlive())
				{
					invaderArray[i].draw(window);
				}
			}

			if (player.isAlive())
			{
				player.draw(window);
			}

			
			window.display(); //displays the window
			
		}
		else
		{
			music.PauseMusic();
			if (victory)
				win.draw(window);
			else
				lose.draw(window);
			window.display(); //closes the window
		}
		
	}
	
}
