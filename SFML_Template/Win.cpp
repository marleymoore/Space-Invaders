#include "Win.h"

Win::Win()
{
    // Load gameOver to display
    if (!texture.loadFromFile("include/images/GameOver.png"))
        throw invalid_argument("Game over screen not loaded!");

    //create sprite and scale
    sprite.scale(sf::Vector2f(1, 1));
    sprite.setPosition(1, 1);
}

sf::Sprite& Win::getSprite()
{
    return sprite;
}

void Win::setLocation(float xpos, float ypos)
{
    sprite.setPosition(xpos, ypos);
}

void Win::draw(sf::RenderWindow& win)
{
    //set texture
    sprite.setTexture(texture);
    win.draw(sprite);
}