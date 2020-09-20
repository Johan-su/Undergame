#pragma once
#include <cstdint>
struct PlayerComponent
{
	unsigned int id;
	unsigned int drillLVL;
	unsigned int bulletWeaponsType; // bullet weapons
	unsigned int explosiveWeaponsType; // explosive weapons
	unsigned int bullets;
	unsigned int bombs;

};