#include "DebugMacros.h"
#include "ProjectileSystem.h"
#include "ECS.h"

static std::vector<Entity>* del_list;

void ProjectileSystem::init()
{
	del_list = new std::vector<Entity>;
}

void ProjectileSystem::clean()
{
	delete del_list;
}

void ProjectileSystem::update()
{
	for (auto e : m_entities)
	{
		auto& collider = Game::coordinator->get_component<ColliderComponent>(e);
		auto& proj = Game::coordinator->get_component<ProjectileComponent>(e);
		auto& health = Game::coordinator->get_component<HealthComponent>(e);

		bool collision = false;

#ifdef ECS_DEBUG
		SDL_assert(collider.entity == e);
		SDL_assert(proj.entity == e);
		SDL_assert(health.entity == e);
#endif
		if (collider.other_entity != 0xFFFFFFFF)
		{
			collision = true;
			auto& other_entity_health = Game::coordinator->get_component<HealthComponent>(collider.other_entity);

#ifdef ECS_DEBUG
			SDL_assert(other_entity_health.entity == collider.other_entity);
#endif
			deal_damage(collider.other_entity, other_entity_health, proj.damage);
		}




		if (collider.tile_id != 0xFFFFFFFF)
		{
			collision = true;
			auto& tile_health = Game::coordinator->get_component<HealthComponent>(collider.tile_id);
#ifdef ECS_DEBUG
			SDL_assert(collider.tile_id == tile_health.entity);
#endif
			deal_damage_tile(collider.tile_id, tile_health, proj.damage);
		}


		if (collision)
		{
			deal_damage(e, health, proj.damage);
		}
	}
	for (uint32_t i = 0; i < del_list->size(); ++i)
	{
		Game::coordinator->destroy_entity(del_list->back());
		del_list->pop_back();
	}
}
void ProjectileSystem::deal_damage(Entity e, HealthComponent& health, const float& damage)
{
#ifdef ECS_DEBUG
	std::cout << "deal_damage" << std::endl;
#endif
	health.health -= damage;
	if (health.health < 0)
	{
		del_list->push_back(e);
		++Game::entityDeaths[health.entity_type];
		return;
	}
	if (health.health > health.max_health)
	{
		health.health = health.max_health;
		return;
	}
}
void ProjectileSystem::deal_damage_tile(Entity e, HealthComponent& health, const float& damage)
{
	health.health -= damage;
	if (health.health < 0)
	{
		del_list->push_back(e);
		Game::tileEntities[e] = 0;
		return;
	}
	if (health.health > health.max_health)
	{
		health.health = health.max_health;
		return;
	}
}