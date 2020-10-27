#include <cmath>
#include "DebugMacros.h"
#include "AiSystem.h"
#include "TargetingSystem.h"
#include "ECS.h"

void AiSystem::init(std::shared_ptr<TargetingSystem> sys)
{
	ts = sys;
}

void AiSystem::clean()
{
}

void AiSystem::update()
{
	for (auto e : m_entities)
	{
		auto& ai = Game::coordinator->get_component<AiComponent>(e);
		auto& pos = Game::coordinator->get_component<PositionComponent>(e);
		auto& digger = Game::coordinator->get_component<DiggerComponent>(e);

#ifdef ECS_DEBUG
		SDL_assert(ai.entity == e);
		SDL_assert(pos.entity == e);
		SDL_assert(digger.entity == e);
#endif

		Entity e = ts->nearest_player(pos.pos.x, pos.pos.y);
		float edistance = ts->nearest_player_distance(pos.pos.x, pos.pos.y);
		Vec2f epos = ts->nearest_player_pos(pos.pos.x, pos.pos.y);

		switch (ai.state)
		{
		case AI_STATE_RANDOM_WALKING:
			if (edistance < ai.detectionRadius / 4)
			{
				ai.state = AI_STATE_TRACKING;
			}
			else if(edistance < ai.detectionRadius)
			{
				ai.state = AI_STATE_TRACK_LAST_KNOWN;
				ai.lastX = epos.x;
				ai.lastY = epos.y;
			}
			else// TODO: add random walking algorithm
			{

			}
			break;

		case AI_STATE_TRACK_LAST_KNOWN:
			if (edistance < ai.detectionRadius / 4)
			{
				ai.state = AI_STATE_TRACKING;
			}
			else if (ai.path_list.size() > 0)
			{

			}
			else
			{
				//Astar(epos.x, epos.y, ai.path_list);
				//dijkstra(epos.x, epos.y, ai.path_list);
				greedy(ai.lastX, ai.lastY, ai.path_list);
			}
			break;

		case AI_STATE_TRACKING:

			break;

		default:
			break;
		}




	}
}

void AiSystem::move_to(uint32_t gridID) //TODO: finish
{
	float gcx = (float)(TILE_SIZE * (gridID % MAP_SIZE) - TILE_SIZE / 2);
	float gcy = (float)(TILE_SIZE * (gridID / MAP_SIZE) - TILE_SIZE / 2);


}

void AiSystem::Astar(float x, float y, std::vector<uint32_t>& path) //TODO: finish
{
}

void AiSystem::dijkstra(float x, float y, std::vector<uint32_t>& path) //TODO: finish, find out about priority queue and such
{
}

void AiSystem::greedy(float x, float y, std::vector<uint32_t>& path) //TODO: finish
{

}
void AiSystem::straight_line(AiComponent& ai, PositionComponent& pos)
{
	float length = hypotf(ai.lastX - pos.pos.x, ai.lastY - pos.pos.y);

}
