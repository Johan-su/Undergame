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

		unsigned short id[9];

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

			int x1 = TILE_SIZE * (id[i] % MAP_SIZE); // lx
			int x2 = TILE_SIZE * (id[i] % MAP_SIZE) + TILE_SIZE; //rx 
			int y1 = TILE_SIZE * (id[i] / MAP_SIZE); // ly
			int y2 = TILE_SIZE * (id[i] / MAP_SIZE) + TILE_SIZE; // ry


			bool b1 = pos.pos.x < x2;

			bool b2 = pos.pos.x + size.size.x > x1;

			bool b3 = pos.pos.y < y2;

			bool b4 = pos.pos.y + size.size.y > y1;


			if (b1 && b2 && b3 && b4)
			{
				std::cout << "intersection ID: " << id[i] << "\n";

			}
		}
	}
}