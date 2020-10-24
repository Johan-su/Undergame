#include <cmath>
#include "DiggerSystem.h"


void DiggerSystem::update()
{
	for (auto e : m_entities)
	{
		auto& pos = Game::coordinator->get_component<PositionComponent>(e);
		auto& size = Game::coordinator->get_component<SizeComponent>(e);
		auto& move = Game::coordinator->get_component<MovementComponent>(e);
		auto& digger = Game::coordinator->get_component<DiggerComponent>(e);
		auto& collider = Game::coordinator->get_component<ColliderComponent>(e);



		if (digger.drillState == 1 && collider.tile_id != 0xFFFFFFFF) //TODO: add (looking at the tlle condition)
		{
			if (is_facing_tile(collider.tile_id, pos, size, move))
			{
				auto& tilehealth = Game::coordinator->get_component<HealthComponent>(collider.tile_id);
				deal_damage_tile(collider.tile_id, tilehealth, 2.0f * powf(1.1f, digger.drillLVL));
			}
		}
	}
}

void DiggerSystem::deal_damage_tile(Entity e, HealthComponent& health, const float& damage)
{
	health.health -= damage;
	if (health.health <= 0)
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

bool DiggerSystem::is_facing_tile(Entity tile, PositionComponent& facersPos, SizeComponent& facersSize, MovementComponent& facersMove)
{
	auto& tilePos = Game::coordinator->get_component<PositionComponent>(tile);

	auto fx = facersPos.pos.x + facersSize.size.x / 2;
	auto fy = facersPos.pos.y + facersSize.size.y / 2;
	auto tx = tilePos.pos.x + TILE_SIZE / 2;
	auto ty = tilePos.pos.y + TILE_SIZE / 2;

	float offset = 1.04719755f; // pi / 6

	float angleToCenter = atanf((fy - ty) / (fx - tx));

	if (fx - tx >= 0)
	{
		angleToCenter += 3.14159265359f; // pi
	}
	angleToCenter = fmod(angleToCenter + 6.28318530718f, 6.28318530718f); // 6.28318530718 == 2pi
	//std::cout << fx << " fx fy " << fy << " " << tx << " tx ty " << ty << " angle " << angleToCenter << std::endl;

	//std::cout << "angle " << angleToCenter << std::endl;
	if (angleToCenter + offset > facersMove.rotation && angleToCenter - offset < facersMove.rotation)
	{
		return 1;
	}
	return 0;
}