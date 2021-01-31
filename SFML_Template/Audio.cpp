#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <list>
#include <iostream>
#include "Player.h"
#include "Aliens.h"
#include "Projectile.h"
#include "Colliders.h"
#include "Audio.h"
#include "GameOver.h"

Audio::Audio()
{
	
	if (!ShipBulletBuffer.loadFromFile("include/sounds/ShipBullet.wav"));  //load bullet sound effect
		
	if (!InvaderBulletBuffer.loadFromFile("include/sounds/InvaderBullet.wav")); //load invader bullet sound effect
			
	if (!ShipHitBuffer.loadFromFile("include/sounds/ShipHit.wav")); //load ship being hit sound effect
				
	if (!InvaderHitBuffer.loadFromFile("include/sounds/InvaderHit.wav"));  //load invader being hit sound effect

	if (!music.openFromFile("include/sounds/12_Invader Homeworld.wav")); //loads background music

}

void Audio::PlayMusic()
{
	music.setLoop(true); //loops the background music
	music.play();
}

void Audio::PauseMusic()
{
	music.pause();
}


void Audio::ShipBullet()
{
	ShipBulletSound.setBuffer(ShipBulletBuffer);  
	ShipBulletSound.play(); //plays the audio when the class is called
}

void Audio::InvaderBullet()
{
	InvaderBulletSound.setBuffer(InvaderBulletBuffer);
	InvaderBulletSound.play();//plays the audio when the class is called
}

void Audio::InvaderHit()
{
	InvaderHitSound.setBuffer(InvaderHitBuffer);
	InvaderHitSound.play();//plays the audio when the class is called
}

void Audio::ShipHit()
{
	ShipHitSound.setBuffer(ShipHitBuffer);
	ShipHitSound.play();//plays the audio when the class is called
}