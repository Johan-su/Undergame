#pragma once
#include <memory>
#include <vector>
#include "Entity.h"
#include "System.h"

class HealthSystem : public System
{
public:

	void init();

	void clean();

	void update();

private:

	std::vector<Entity>* dead_entities;
};