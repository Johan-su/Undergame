#include <cmath>
#include "DebugMacros.h"
#include "AiSystem.h"
#include "TargetingSystem.h"
#include "ECS.h"




void AiSystem::update()
{
	for (auto e : m_entities)
	{
		auto& ai = Game::coordinator->get_component<AiComponent>(e);
		auto& pos = Game::coordinator->get_component<PositionComponent>(e);

		Entity e = TargetingSystem::nearest_player(pos.pos.x, pos.pos.y);

#ifdef ECS_DEBUG
		SDL_assert(ai.entity == e);
		SDL_assert(pos.entity == e);
#endif
	}
}

void AiSystem::Astar(float x, float y, AiComponent& ai)
{
}

void AiSystem::dijkstra(float x, float y, AiComponent& ai)
{
}

void AiSystem::greedy(float x, float y, AiComponent& ai)
{
}
void AiSystem::straight_line(AiComponent& ai, PositionComponent& pos)
{
	float length = hypotf(ai.lastX - pos.pos.x, ai.lastY - pos.pos.y);

}
