#include "Colliders.h"

bool Colliders::collidesWith(Player & box1, Aliens & box2)
{
	sf::FloatRect Player; //ease of use placing a rectangle on the player
	Player.left = box1.getSprite().getPosition().x+10; //sets "box1" to the appropriate areas of the player sprites location
	Player.top = box1.getSprite().getPosition().y+10;
	Player.width = box1.getSprite().getGlobalBounds().width-10;
	Player.height = box1.getSprite().getGlobalBounds().height-10;

	sf::FloatRect Aliens;  //ease of use placing a rectangle on the aliens
	Aliens.left = box2.getSprite().getPosition().x;   //sets "box2" to the appropriate areas of the player sprites location
	Player.top = box1.getSprite().getPosition().y + 10;
	Aliens.top = box2.getSprite().getPosition().y;
	Aliens.width = box2.getSprite().getGlobalBounds().width;
	Aliens.height = box2.getSprite().getGlobalBounds().height;

	return Player.intersects(Aliens); //player can intersect/touch the aliens

}

bool Colliders::collidesWith(Projectile &box1, Aliens &box2) //boolean variable of the projectile and player/"box1" touching the aliens/"box2"
{
	
	sf::FloatRect Projectile; //ease of use placing a rectangle on the bullet
	
	Projectile.left = box1.getSprite().getPosition().x + 10;
	Projectile.top = box1.getSprite().getPosition().y + 10;
	//bottom right
	Projectile.width = box1.getSprite().getGlobalBounds().width - 10;
	Projectile.height = box1.getSprite().getGlobalBounds().height - 10;

	//get the bounding box of the alien
	sf::FloatRect Aliens;
	//top left
	Aliens.left = box2.getSprite().getPosition().x;
	Aliens.top = box2.getSprite().getPosition().y;
	//bottom right
	Aliens.width = box2.getSprite().getGlobalBounds().width;
	Aliens.height = box2.getSprite().getGlobalBounds().height;

	//std::cout << "Ship left: " << ship.left << " " << "Ship top: " << ship.top << std::endl;
	//std::cout << "Alien left: " << alien.left << " " << "Alien top: " << alien.top << std::endl;

	return Projectile.intersects(Aliens); //bullet can intersect/touch the aliens
}