#pragma once
#include <memory>
#include "HealthSystem.h"
#include "ECS.h"

class CollisionSystem : public System
{
public:
	
	void init(std::shared_ptr<HealthSystem> healthSystem);

	void update();

private:
	std::shared_ptr<HealthSystem> m_healthSystem;
};