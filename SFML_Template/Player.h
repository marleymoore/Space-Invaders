#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
class Player //creating the player class in the header file for use in the .cpp file
{
public:
	//constructor sets ID number, loads sprite
	Player(const int, float);    //constructor sets the id number and loads the sprite
	sf::Sprite & getSprite();
	void setLocation(float, float);
	void kill();
	bool isAlive();
	void respawn();
	void draw(sf::RenderWindow &win);
private:
	sf::Sprite sprite;
	sf::Texture texture;
	bool alive;
};
