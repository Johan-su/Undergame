#pragma once
#include "ECS.h"

class ProjecttileSystem : public System
{
public:

	void update();

private:

	void dealDamage(Entity e, HealthComponent& health, const float& damage);
};