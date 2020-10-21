#include "DebugMacros.h"
#include "ProjectileSystem.h"
#include "ECS.h"

static std::vector<uint32_t>* del_list;


void ProjectileSystem::init()
{
	del_list = new std::vector<uint32_t>;
}



void ProjectileSystem::update()
{
	for (auto e : m_entities)
	{
		auto& collider = Game::coordinator->get_component<ColliderComponent>(e);
		auto& proj = Game::coordinator->get_component<ProjectileComponent>(e);
		auto& health = Game::coordinator->get_component<HealthComponent>(e);


#ifdef ECS_DEBUG
		SDL_assert(collider.entity == e);
		SDL_assert(proj.entity == e);
		SDL_assert(health.entity == e);
#endif
		if (collider.other_entity != 0xFFFFFFFF)
		{
			auto& other_entity_health = Game::coordinator->get_component<HealthComponent>(collider.other_entity);

#ifdef ECS_DEBUG
			SDL_assert(other_entity_health.entity == collider.other_entity);
#endif
			deal_damage(collider.other_entity, other_entity_health, proj.damage);
		}

		if (collider.tile_id != 0xFFFFFFFF)
		{
			auto& tile_health = Game::coordinator->get_component<HealthComponent>(collider.tile_id);
			del_list->push_back(e);
			//health.health = -1;
		}
	}
	for ( uint32_t i = 0; i < del_list->size(); ++i)
	{
		Game::coordinator->destroy_entity(del_list->back());
		del_list->pop_back();
	}
}
void ProjectileSystem::deal_damage(Entity e, HealthComponent& health, const float& damage)
{
	health.health -= damage;
	if (health.health < 0)
	{
		Game::coordinator->destroy_entity(e);
	}
}