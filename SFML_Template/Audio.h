#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>


using namespace std;

class Audio //class for the audio in the game
{
public:

	Audio();   //audio function
	void PlayMusic();
	void PauseMusic();
	void ShipBullet();
	void InvaderBullet();
	void InvaderHit();
	void ShipHit();

private:

	sf::SoundBuffer ShipBulletBuffer;  //soundbuffer stores the sound for later
	sf::SoundBuffer InvaderBulletBuffer;
	sf::SoundBuffer ShipHitBuffer;
	sf::SoundBuffer InvaderHitBuffer;
	sf::Music music;   //streamed music from a locally stored audio file
	sf::Sound ShipBulletSound;
	sf::Sound InvaderBulletSound;   //sound that can be referenced in the .cpp file
	sf::Sound ShipHitSound;
	sf::Sound InvaderHitSound;

};

