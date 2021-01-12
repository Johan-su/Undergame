#include <cmath>
#include "EntityCreator.h"
#include "SpawnerSystem.h"
#include "Game.h"

void SpawnerSystem::init()
{
	spawntimer = 0;
	spawnrate = 3600;
}

void SpawnerSystem::clean()
{

}

void SpawnerSystem::update() //TODO: add random generators
{
	if (spawntimer >= spawnrate)
	{
		for (auto e : m_entities)
		{
			float angle, x, y;

			auto& pos = Game::coordinator->get_component<PositionComponent>(e);
			auto& size = Game::coordinator->get_component<SizeComponent>(e);


			x = cos(angle) * TILE_SIZE * 10;
			y = sin(angle) * TILE_SIZE * 10;

			EntityCreator::create_entity(ENTITY_TYPE_MOLE, x, y, 0);
		}
		spawntimer = 0;
	}
	++spawntimer;
}