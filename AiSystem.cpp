#include <cmath>
#include "DebugMacros.h"
#include "AiSystem.h"
#include "ECS.h"


void AiSystem::update()
{
	for (auto e : m_entities)
	{
		auto& ai = Game::coordinator->get_component<AiComponent>(e);
		auto& pos = Game::coordinator->get_component<PositionComponent>(e);


#ifdef ECS_DEBUG
		SDL_assert(ai.entity == e);
		SDL_assert(pos.entity == e);
#endif
	}
}

float AiSystem::Astar(float x, float y, AiComponent& ai)
{
	return NULL;
}

float AiSystem::dijkstra(float x, float y, AiComponent& ai)
{
	return NULL;
}

float AiSystem::greedy(float x, float y, AiComponent& ai)
{
	return NULL;
}
float AiSystem::straight_line(AiComponent& ai, PositionComponent& pos) //TODO: find a way to detect intersections between 2 points.
{
	float length = hypotf(ai.lastX - pos.pos.x, ai.lastY - pos.pos.y);

	return NULL;
}
