#include "CollisionSystem.h"
#include "ECS.h"

constexpr int maxID = MAP_SIZE * MAP_SIZE - 1;
void CollisionSystem::update()
{
	for (const auto& e : m_entities)
	{
		auto& pos = Game::coordinator->get_component<PositionComponent>(e);
		auto& size = Game::coordinator->get_component<SizeComponent>(e);
		auto& collider = Game::coordinator->get_component<ColliderComponent>(e);

		int middlex = static_cast<int>(pos.pos.x + size.size.x);
		int middley = static_cast<int>(pos.pos.y + size.size.y);

		int id[9];

		id[4] = (middlex / TILE_SIZE) + MAP_SIZE * (middley / TILE_SIZE);

		id[0] = id[4] - MAP_SIZE - 1;
		id[1] = id[4] - MAP_SIZE;
		id[2] = id[4] - MAP_SIZE + 1;
		id[3] = id[4] - 1;
		id[5] = id[4] + 1;
		id[6] = id[4] + MAP_SIZE - 1;
		id[7] = id[4] + MAP_SIZE;
		id[8] = id[4] + MAP_SIZE + 1;

		for (unsigned int i = 0; i < 9; ++i) //TODO: add collision checks
		{

		}

	}
}