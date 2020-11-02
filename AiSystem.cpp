#include <cmath>
#include "DebugMacros.h"
#include "AiSystem.h"
#include "TargetingSystem.h"
#include "MovementComponent.h"
#include "DiggerComponent.h"
#include "PositionComponent.h"
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
		auto& move = Game::coordinator->get_component<MovementComponent>(e);

#ifdef ECS_DEBUG
		SDL_assert(ai.entity == e);
		SDL_assert(pos.entity == e);
		SDL_assert(digger.entity == e);
		SDL_assert(move.entity == e);
#endif

		Entity e = ts->nearest_player(pos.pos.x, pos.pos.y);
		float pdistance = ts->nearest_player_distance(pos.pos.x, pos.pos.y);
		Vec2f ppos = ts->nearest_player_pos(pos.pos.x, pos.pos.y);



		if (pdistance < ai.detectionRadius / 4)
		{
			ai.state = AI_STATE_TRACKING;
		}

		switch (ai.state)
		{
		case AI_STATE_RANDOM_WALKING:

			if(pdistance < ai.detectionRadius)
			{
				ai.state = AI_STATE_TRACK_LAST_KNOWN;
				ai.lastX = ppos.x;
				ai.lastY = ppos.y;
			}
			else// TODO: add random walking algorithm
			{

			}
			break;

		case AI_STATE_TRACK_LAST_KNOWN:

			if (ai.path_list.size() > 0)
			{

			}
			else
			{
				//Astar(epos.x, epos.y, ai.path_list);
				//dijkstra(epos.x, epos.y, ai.path_list);
				greedy(ai.lastX, ai.lastY, move, digger, ai.path_list);
			}
			break;

		case AI_STATE_TRACKING:

			break;

		default:
			break;
		}




	}
}

bool AiSystem::move_to(uint32_t gridID, PositionComponent& pos, SizeComponent& size) //TODO: finish
{
	float gcx = (float)(TILE_SIZE * (gridID % MAP_SIZE) - TILE_SIZE / 2);
	float gcy = (float)(TILE_SIZE * (gridID / MAP_SIZE) - TILE_SIZE / 2);


	auto ecx = pos.pos.x + size.size.x;
	auto ecy = pos.pos.y + size.size.y;

	




	if (abs(ecx - gcx) < 16.0f && abs(ecy - gcy) < 16.0f)
	{
		return 1;
	}
	return 0;
}

void AiSystem::Astar(float x, float y, MovementComponent& move, DiggerComponent& digger, std::vector<uint32_t>& path) //TODO: finish
{
}

void AiSystem::dijkstra(float x, float y, MovementComponent& move, DiggerComponent& digger, std::vector<uint32_t>& path) //TODO: finish, find out about priority queue and such
{
}

void AiSystem::greedy(float x, float y, MovementComponent& move, DiggerComponent& digger, std::vector<uint32_t>& path) //TODO: finish this 
{
	uint16_t id = (uint16_t)((fmod(y, TILE_SIZE)) * x / TILE_SIZE); // find way to get grid id from coords
}
void AiSystem::straight_line(AiComponent& ai, PositionComponent& pos)
{
	float length = hypotf(ai.lastX - pos.pos.x, ai.lastY - pos.pos.y);

}

float AiSystem::dig_time(uint16_t gridID, MovementComponent& move, DiggerComponent& digger)
{
	float time = 0.0f;
	if (Game::tileEntities[gridID] != 0)
	{
		auto health = Game::coordinator->get_component<HealthComponent>(gridID);
		float digspeed =  2.0f * (1.0f + 0.4f * digger.drillLVL);

		time += health.health / digspeed;
	}
	return time + ((float)(TILE_SIZE) / move.speed);
}
