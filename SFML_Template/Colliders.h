#pragma once
#include "Player.h"
#include "Projectile.h"
#include "Aliens.h"
#include <iostream>

class Colliders
{
public:   //public class that can be edited by other header and .cpp files
	static bool collidesWith(Player &, Aliens &);
	static bool collidesWith(Projectile &, Aliens &);
private:

};