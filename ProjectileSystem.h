#pragma once
#include "DebugMacros.h"
#include "ECS.h"

class ProjectileSystem : public System
{
public:

	void init();

	void clean();

	void update();

private:

	void deal_damage(Entity e, HealthComponent& health, const float& damage);

	void deal_damage_tile(Entity e, HealthComponent& health, const float& damage);
};