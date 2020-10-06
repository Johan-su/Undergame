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
			EntityCreator::create_entity(ENTITY_TYPE_BULLET, pos.pos.x + size.size.x / 2 + shoot.gunlength * cosf(move.rotation), pos.pos.y + size.size.y / 2 + shoot.gunlength * sinf(move.rotation), &move.rotation);

		}
	}
}