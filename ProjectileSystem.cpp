#include "ProjectileSystem.h"
#include "ECS.h"


void ProjectileSystem::update()
{
	for (const auto e : m_entities)
	{
		auto& collider = Game::coordinator->get_component<ColliderComponent>(e);
		auto& proj = Game::coordinator->get_component<ProjectileComponent>(e);

		if (collider.id != 0xFFFFFFFF)
		{
			Game::coordinator->destroy_entity(e);
			return;
		}

		if (collider.Entity != 0xFFFFFFFF)
		{
			auto& otherhealth = Game::coordinator->get_component<HealthComponent>(collider.Entity);

			dealDamage(collider.Entity, otherhealth, proj.damage);
			Game::coordinator->destroy_entity(e);
			return;
		}

	}
}
void ProjectileSystem::dealDamage(Entity e, HealthComponent& health, const float& damage)
{
	health.health -= damage;

	if (health.health < 0)
	{
		Game::coordinator->destroy_entity(e);
	}
}