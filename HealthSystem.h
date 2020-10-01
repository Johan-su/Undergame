#pragma once
#include "ECS.h"

class HealthSystem : public System
{
public:

	void init();

	void clean();

	void update();

private:

	std::vector<Entity>* dead_entities;
};