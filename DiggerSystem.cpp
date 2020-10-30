#include <cmath>
#include "ECS.h"


void DiggerSystem::update()
{
	for (auto e : m_entities)
	{
		auto& render = Game::coordinator->get_component<RenderComponent>(e);
		auto& pos = Game::coordinator->get_component<PositionComponent>(e);
		auto& size = Game::coordinator->get_component<SizeComponent>(e);
		auto& move = Game::coordinator->get_component<MovementComponent>(e);
		auto& digger = Game::coordinator->get_component<DiggerComponent>(e);
		auto& collider = Game::coordinator->get_component<ColliderComponent>(e);



		if (digger.drillState == 1 && collider.tile_id != 0xFFFFFFFF) //TODO: add (looking at the tlle condition)
		{
			if (is_facing_tile(collider.tile_id, pos, size, move))
			{
				//render.src_rect = { 0, 0, 0, 0 }; //TODO: determine texture when digging
				auto& tilehealth = Game::coordinator->get_component<HealthComponent>(collider.tile_id);
				deal_damage_tile(collider.tile_id, tilehealth, 2.0f * (1.0f + 0.4f * digger.drillLVL));
			}
			else
			{
				//render.src_rect = { 0, 0, 0, 0 }; //TODO: determine texture when not digging
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

	float fx = facersPos.pos.x + facersSize.size.x / 2;
	float fy = facersPos.pos.y + facersSize.size.y / 2;
	float tx = tilePos.pos.x + TILE_SIZE / 2;
	float ty = tilePos.pos.y + TILE_SIZE / 2;

	float offset = 1.0471975512f; // pi / 3

	float angleToCenter = atanf((fy - ty) / (fx - tx));

	if (fx - tx >= 0)
	{
		angleToCenter -= 3.14159265359f; // pi
	}

	angleToCenter = fmod(angleToCenter + 6.28318530718f, 6.28318530718f); // 6.28318530718 == 2pi

	float oxp = fmod(angleToCenter + offset + 6.28318530718f, 6.28318530718f);
	float oxm = fmod(angleToCenter - offset + 6.28318530718f, 6.28318530718f);

	//std::cout << fx << " fx fy " << fy << " " << tx << " tx ty " << ty << " angle " << angleToCenter << std::endl;

	//std::cout << "angle " << angleToCenter << std::endl;
	if (oxp > facersMove.angle && oxm < facersMove.angle)
	{
	//	std::cout << "is facing " << angleToCenter << std::endl;
		return 1;
	}

	if (oxm > oxp)
	{
		if (oxp > facersMove.angle || oxm < facersMove.angle)
		{
		//	std::cout << "is facing " << angleToCenter << std::endl;
			return 1;
		}
	}
	//std::cout << "is not facing " << angleToCenter <<std::endl;
	return 0;
}