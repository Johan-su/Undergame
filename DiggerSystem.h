#pragma once
#include "System.h"
#include "Entity.h"
#include "PositionComponent.h"
#include "MovementComponent.h"
#include "HealthComponent.h"
#include "SizeComponent.h"
class DiggerSystem : public System
{
public:

	void update();


private:

	void deal_damage_tile(Entity e, HealthComponent& health, const float& damage);

	bool is_facing_tile(Entity tile, PositionComponent& facersPos, SizeComponent& facersSize, MovementComponent& facersMove);

};