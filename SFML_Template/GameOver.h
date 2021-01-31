#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;

class GameOver
{
public:

	GameOver();
	sf::Sprite & getSprite();
	void setLocation(float, float);
	void draw(sf::RenderWindow & win); //draws the game over window, sets the location to two float variables that are given in the GameOver.cpp

private:
	sf::Sprite sprite;
	sf::Texture texture;

};

