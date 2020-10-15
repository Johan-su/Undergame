#include "DebugMacros.h"
#include "ProjectileSystem.h"
#include "ECS.h"


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
			auto& otherhealth = Game::coordinator->get_component<HealthComponent>(collider.other_entity); //TODO: fix problem with entity component "linkage"

#ifdef ECS_DEBUG
			SDL_assert(otherhealth.entity == collider.other_entity);
#endif
			deal_damage(collider.other_entity, otherhealth, proj.damage);
		}

		if (collider.id != 0xFFFFFFFF)
		{
			health.health = -1;
		}
	}
}
void ProjectileSystem::deal_damage(Entity e, HealthComponent& health, const float& damage)
{
	health.health -= damage;
}