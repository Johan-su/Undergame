#include "ShooterSystem.h"
#include "EntityCreator.h"
#include "ECS.h"


void ShooterSystem::update()
{
	for (const auto e : m_entities)
	{
		auto& pos = Game::coordinator->get_component<PositionComponent>(e);
		auto& size = Game::coordinator->get_component<SizeComponent>(e);
		auto& move = Game::coordinator->get_component<MovementComponent>(e);
		auto& shoot = Game::coordinator->get_component<ShooterComponent>(e);

		if (shoot.states[0])
		{
			Game::entities->push_back(EntityCreator::create_entity(ENTITY_TYPE_BULLET, pos.pos.x + 4 * cosf(move.rotation), pos.pos.y + 4 * sinf(move.rotation), *(unsigned long long*)(&move.rotation)));

		}
	}
}