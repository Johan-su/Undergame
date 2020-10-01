#include "ProjectileSystem.h"
#include "ECS.h"


void ProjectileSystem::update()
{
	for (const auto e : m_entities)
	{
		auto& collider = Game::coordinator->get_component<ColliderComponent>(e);
		auto& proj = Game::coordinator->get_component<ProjectileComponent>(e);
		auto& health = Game::coordinator->get_component<HealthComponent>(e);

		if (collider.Entity != 0xFFFFFFFF)
		{
			auto& otherhealth = Game::coordinator->get_component<HealthComponent>(collider.Entity);

			deal_damage(collider.Entity, otherhealth, proj.damage);
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