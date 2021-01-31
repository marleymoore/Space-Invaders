#include "Aliens.h"
#include <iostream>

using namespace std;

Aliens::Aliens(const int id, float sp)
{
	alive = true;

	
	speed = sp;   //set speed

	
	if (!texture.loadFromFile("include/images/InvaderB2.png"));  // Load an enemy texture

	
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(0.8, 0.8));   //scale sprite and set texture so we know size
}

sf::Sprite & Aliens::getSprite() 
{
	return sprite;
}

void Aliens::setLocation(float xpos, float ypos)  //sets location of the every function that falls under the "Alien" class
{
	sprite.setPosition(xpos, ypos);
}

void Aliens::kill()
{
	alive = false;         //prevents the alien from dying until the boolean variable is altered
}

bool Aliens::isAlive()
{
	return alive;
}

void Aliens::draw(sf::RenderWindow &win)
{
	//set texture
	sprite.setTexture(texture);    //sets the texture of the alien sprite
	//draw
	win.draw(sprite);
}

float Aliens::getSpeed() const //constant speed
{
	return speed;
}
