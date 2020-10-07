#pragma once
#include "HealthSystem.h"
#include "ECS.h"

class StaticCollisionSystem : public System
{
public:

	void init(std::shared_ptr<HealthSystem> healthsystem);

	void update();

private:

	std::shared_ptr<HealthSystem> m_healthSystem;
};