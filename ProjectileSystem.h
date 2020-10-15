#pragma once
#include "DebugMacros.h"
#include "ECS.h"

class ProjectileSystem : public System
{
public:

	void update();

private:

	void deal_damage(Entity e, HealthComponent& health, const float& damage);
};