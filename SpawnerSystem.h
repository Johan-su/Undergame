#pragma once
#include "ECS.h"

class SpawnerSystem : public System
{
public:

	void update();

	void init();

	void clean();

private:

	uint32_t spawntimer, spawnrate;
};