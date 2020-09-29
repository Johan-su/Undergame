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

			int x1 = TILE_SIZE * (id[i] % MAP_SIZE);
			int x2 = TILE_SIZE * (id[i] % MAP_SIZE) + TILE_SIZE;
			int y1 = TILE_SIZE * (id[i] / MAP_SIZE);
			int y2 = TILE_SIZE * (id[i] / MAP_SIZE) + TILE_SIZE;


			bool b1 = pos.pos.x > x2;

			bool b2 = x1 > pos.pos.x + size.size.x;

			bool b3 = true;

			if (b1 || b2)
			{
				b3 = false;
			}
			//bool b2 = pos.pos.x + size.size.x >= TILE_SIZE * (id[i] % MAP_SIZE) + TILE_SIZE;

			bool b4 = pos.pos.y > y2;

			bool b5 = y1 < pos.pos.y + size.size.y;

			if (b4 || b5)
			{
				b3 = false;
			}

			if (b3)
			{
				std::cout << "intersection ID: " << id[i] << "\n";

			}
			//bool b7 = pos.pos.y + size.size.y >= TILE_SIZE * (id[i] / MAP_SIZE);

			//bool b3 = pos.pos.y >= TILE_SIZE * (id[i] / MAP_SIZE);
			
			//bool b5 = pos.pos.x + size.size.x >= TILE_SIZE * (id[i] % MAP_SIZE);

			//bool b6 = pos.pos.x + size.size.x <= TILE_SIZE * (id[i] % MAP_SIZE) + TILE_SIZE;
			//bool b8 = pos.pos.y + size.size.y <= TILE_SIZE * (id[i] / MAP_SIZE) + TILE_SIZE;







		}

	}
}