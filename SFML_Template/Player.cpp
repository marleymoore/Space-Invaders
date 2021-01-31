#include "Player.h"
#include <iostream>


using namespace std;

//constructor sets ID number, loads sprite
Player::Player(const int id, float speed)
{
	alive = true;
	sprite.setPosition(250, 500);
	if (!texture.loadFromFile("include/images/Ship.png")); // creates an if function for setting the texture as the player image
}
	void Player::setLocation(float xpos, float ypos) //This is to set the players position, two float variables allow it to be altered.
{
	sprite.setPosition(xpos, ypos); //sprite goes into the same position as the two float variables
}

sf::Sprite & Player::getSprite() //sfml function to get the players sprite that was previously loaded
{
	return sprite;
}

void Player::kill() //allows the player to be killed
{
	alive = false;
}

bool Player::isAlive() //a boolean variable so "isAlive" status can be changed
{
	return alive;
}

void Player::draw(sf::RenderWindow &win) //draws the player sprite in the window
{
	
	sprite.setTexture(texture); //sets the texture of the player
	win.draw(sprite);
}

void Player::respawn()
{
	alive = true;
}