#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>  //adding the different libraries for later use.

class Aliens //creating the player class in the header file for use in the .cpp file
{
public:
	//constructor sets ID number, loads sprite
	Aliens(){};
	Aliens(const int, float);  //constructor sets the id number and loads the sprite
	sf::Sprite & getSprite();
	void setLocation(float, float); 
	void kill();
	bool isAlive();
	float getSpeed() const;
	void draw(sf::RenderWindow &win);
private:
	sf::Sprite sprite;    
	sf::Texture texture; 
	bool alive;
	float speed;
};