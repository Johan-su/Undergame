#pragma once
#include "DiggerComponent.h"
#include "ECS.h"

class DiggerSystem : public System
{
public:

	void update();


private:

	void deal_damage_tile(Entity e, HealthComponent& health, const float& damage);

	bool is_facing_tile(Entity tile, PositionComponent& facersPos, SizeComponent& facersSize, MovementComponent& facersMove);

};