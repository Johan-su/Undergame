#include "DiggerSystem.h"


void DiggerSystem::update()
{
	for (auto e : m_entities)
	{
		auto& move = Game::coordinator->get_component<MovementComponent>(e);
		auto& digger = Game::coordinator->get_component<DiggerComponent>(e);
		auto& collider = Game::coordinator->get_component<ColliderComponent>(e);
		auto& input = Game::coordinator->get_component<InputComponent>(e);



		if (input.buttonStates[6] && collider.tile_id != 0xFFFFFFFF) //TODO: add (looking at the tlle condition)
		{
			auto& tilehealth = Game::coordinator->get_component<HealthComponent>(collider.tile_id);
			deal_damage_tile(collider.tile_id, tilehealth, 2.0f * powf(1.1f, digger.drillLVL));
		}

	}
}

void DiggerSystem::deal_damage_tile(Entity e, HealthComponent& health, const float& damage)
{
	health.health -= damage;
	if (health.health < 0)
	{
		Game::coordinator->destroy_entity(e);
		Game::tileEntities[e] = 0;
		return;
	}
	if (health.health > health.max_health)
	{
		health.health = health.max_health;
		return;
	}
}