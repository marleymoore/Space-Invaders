#include "Projectile.h"
#include <iostream>

using namespace std;

Projectile::Projectile(const int id, float speed) //float speed so it can be edited in the main.cpp file
{
	alive = false;

	
	if (!texture.loadFromFile("include/images/Bullet.png")); //load a sprite

	
	sprite.scale(sf::Vector2f(0.5, 0.5)); //scales the sprite to the appropriate size
}

sf::Sprite & Projectile::getSprite() //gets the sprite of the bullet
{
	return sprite;
}

void Projectile::setLocation(float xpos, float ypos) //allows the bullet to spawn from the players location
{
	sprite.setPosition(xpos, ypos);
}

void Projectile::kill()
{
	alive = false;
}

bool Projectile::isAlive()
{
	return alive;
}

void Projectile::spawn(bool bullet)
{
	alive = bullet;
}

void Projectile::draw(sf::RenderWindow &win)
{
	//set texture
	sprite.setTexture(texture);
	win.draw(sprite);
}
