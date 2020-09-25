#include "MovementSystem.h"

void MovementSystem::update()
{
	static float normalizer;
	for (const auto& e : m_entities)
	{
		auto& positionc = Game::coordinator->get_component<PositionComponent>(e);
		auto& movec = Game::coordinator->get_component<MovementComponent>(e);


		if (movec.velocity.x && movec.velocity.y)
		{
			normalizer = 0.707106781187f; // 1 / sqrt(2)
		}
		else
		{
			normalizer = 1.0f;
		}

		positionc.pos.x += movec.velocity.x * movec.speed * normalizer;
		positionc.pos.y += movec.velocity.y * movec.speed * normalizer;
	}
}