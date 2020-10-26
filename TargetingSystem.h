#pragma once
#include "ECS.h"

class TargetingSystem : public System
{
public:

	static Entity nearest_player(float x, float y);

	static float nearest_player_distance(float x, float y);

};