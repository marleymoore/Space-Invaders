#include "GameOver.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;

GameOver::GameOver() //creates game over function
{
	if (!texture.loadFromFile("include/images/GameOver.png")); //loads game over screen .png file
	
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(1, 1)); //sets position of the game over screen
	sprite.setPosition(1, 1);
	
}

sf::Sprite & GameOver::getSprite()
{
	return sprite;      
}

void GameOver::setLocation(float xpos, float ypos)
{
	sprite.setPosition(xpos, ypos);
}

void GameOver::draw(sf::RenderWindow &win) //draws the game over screen from loaded file
{
	//set texture
	sprite.setTexture(texture);
	win.draw(sprite);
}