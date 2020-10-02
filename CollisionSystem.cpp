#include "CollisionSystem.h"
#include "ECS.h"

void CollisionSystem::update()
{
	for (const auto& e : m_entities)
	{
		auto& collider = Game::coordinator->get_component<ColliderComponent>(e);
		auto& position = Game::coordinator->get_component<PositionComponent>(e);
		auto& size = Game::coordinator->get_component<SizeComponent>(e);
		auto& movement = Game::coordinator->get_component<MovementComponent>(e);


		for (const auto& e2 : m_entities)
		{
			if (e == e2)
			{
				continue;
			}

			auto& collider2 = Game::coordinator->get_component<ColliderComponent>(e2);
			auto& position2 = Game::coordinator->get_component<PositionComponent>(e2);
			auto& size2 = Game::coordinator->get_component<SizeComponent>(e2);
			auto& movement2 = Game::coordinator->get_component<MovementComponent>(e2);

			bool b1 = position.pos.x < position2.pos.x + size2.size.x;

			bool b2 = position.pos.x + size.size.x > position2.pos.x;

			bool b3 = position.pos.y < position2.pos.y + size2.size.y;

			bool b4 = position.pos.y + size.size.y > position2.pos.y;


			if (b1 && b2 && b3 && b4)
			{
				collider.Entity = e2;
#ifdef _DEBUG
				std::cout << "intersection between " << e << " and " << e2 << std::endl;
#endif
			}
		}
	}
}