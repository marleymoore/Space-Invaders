#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>


class Projectile
{
public:
	//constructor sets ID number, loads sprite
	Projectile(const int, float);
	sf::Sprite & getSprite();
	void setLocation(float, float);
	void kill();
	bool isAlive();
	void spawn(bool);
	//draw the sprite
	void draw(sf::RenderWindow &win);
private:
	sf::Sprite sprite;
	sf::Texture texture;
	bool alive;
};

