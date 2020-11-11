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
#ifdef PRINT_DEBUG
	static int count = 0;
#endif
	for (auto e : m_entities)
	{
		auto& ai = Game::coordinator->get_component<AiComponent>(e);
		auto& pos = Game::coordinator->get_component<PositionComponent>(e);
		auto& size = Game::coordinator->get_component<SizeComponent>(e);
		auto& digger = Game::coordinator->get_component<DiggerComponent>(e);
		auto& move = Game::coordinator->get_component<MovementComponent>(e);
		auto& collider = Game::coordinator->get_component<ColliderComponent>(e);

#ifdef ECS_DEBUG
		SDL_assert(ai.entity == e);
		SDL_assert(pos.entity == e);
		SDL_assert(size.entity == e);
		SDL_assert(digger.entity == e);
		SDL_assert(move.entity == e);
		SDL_assert(collider.entity == e);
#endif

		Entity e = ts->nearest_player(pos.pos.x, pos.pos.y);
		float pdistance = ts->nearest_player_distance(pos.pos.x, pos.pos.y);
		Vec2f ppos = ts->nearest_player_pos(pos.pos.x, pos.pos.y);
		Vec2f psize = ts->nearest_player_size(pos.pos.x, pos.pos.y);


		if (collider.tile_id != 0xFFFFFFFF)
		{
			 ai.state = AI_STATE_DIG;
		}
		else
		{
			if (pdistance < ai.detectionRadius / 4)
			{
				ai.state = AI_STATE_TRACKING;
			}
			else if (pdistance < ai.detectionRadius)
			{
				ai.state = AI_STATE_TRACK_LAST_KNOWN;
				ai.lastX = ppos.x;
				ai.lastY = ppos.y;
			}
			else
			{
				ai.state = AI_STATE_RANDOM_WALKING;
			}
		}
		switch (ai.state)
		{
		case AI_STATE_RANDOM_WALKING:

#ifdef PRINT_DEBUG
			if (count == 60)
			{
				DP("random walk"); 
				count = 0;
			}
#endif

			break;

		case AI_STATE_TRACK_LAST_KNOWN:

#ifdef PRINT_DEBUG
			if (count == 60)
			{
				DP("last known"); 
				count = 0;
			}
#endif


			if (ai.path_list.size() > 0)
			{
				if (move_to(ai.path_list.back(), pos, size, move, collider))
				{
					ai.path_list.pop_back();
				}
			}
			else
			{
				//Astar(epos.x, epos.y, ai.path_list);
				//dijkstra(epos.x, epos.y, ai.path_list);
				dstar(ai.lastX, ai.lastY, move, digger, ai.path_list);
			}
			break;

		case AI_STATE_TRACKING:

#ifdef PRINT_DEBUG
			if (count == 60)
			{
				DP("tracking"); //TODO: remove or rework, generally bad and digs forever at boundary tiles
				count = 0;
			}
#endif


			ai_track(ppos, psize, pos, size, move);



			break;

		case AI_STATE_DIG:

#ifdef PRINT_DEBUG
			if (count == 60)
			{
				DP("dig"); //TODO: remove or rework, generally bad and digs forever at boundary tiles
				count = 0;
			}
#endif

			digger.drillState = 1;

			move_to(collider.tile_id, pos, size, move, collider);
			
			break;

		default:
				break;
		}
	}
#ifdef PRINT_DEBUG
	++count;
#endif
}

bool AiSystem::move_to(uint32_t gridID, PositionComponent& pos, SizeComponent& size, MovementComponent& move, ColliderComponent& collider) //TODO: find out how to control the ai in a good way.
{

	auto type = Game::tileEntities[gridID];


	float gcx = (float)(TILE_SIZE * (gridID % MAP_SIZE) + TILE_SIZE / 2);
	float gcy = (float)(TILE_SIZE * (gridID / MAP_SIZE) + TILE_SIZE / 2);


	float ecx = pos.pos.x + size.size.x / 2;
	float ecy = pos.pos.y + size.size.y / 2;

	
	float targetangle = atanf((ecy - gcy) / (ecx - gcx));

	if (ecx - gcx >= 0)
	{
		targetangle -= 3.14159265359f; // pi
	}
	move.angle = fmod(targetangle + 6.28318530718f, 6.28318530718f); // 6.28318530718 == 2pi

	if (type == 16)
	{

		if (is_right(gcx, ecx)) // right
		{
			pos.pos.x += size.size.x / 8;
		}
		else
		{
			pos.pos.x -= size.size.x / 8;
		}
		if (is_down(gcy, ecy))
		{
			pos.pos.y += size.size.y / 8;

		}
		else
		{
			pos.pos.y -= size.size.y / 8;
		}
		return 0;
	}

	move.velocity.x = cos(-targetangle);
	move.velocity.y = sin(targetangle);




	if (abs(ecx - gcx) < 16.0f && abs(ecy - gcy) < 16.0f)
	{
		move.velocity.x = 0.0f;
		move.velocity.y = 0.0f;
		return 1;
	}
	return 0;
}

void AiSystem::Astar(float x, float y, MovementComponent& move, DiggerComponent& digger, std::vector<uint32_t>& path) //TODO: finish
{
	uint16_t targetid = ((int)x / TILE_SIZE) + ((int)y / TILE_SIZE) * MAP_SIZE;

}

void AiSystem::dijkstra(float x, float y, MovementComponent& move, DiggerComponent& digger, std::vector<uint32_t>& path) //TODO: finish, find out about priority queue and such
{
	uint16_t targetid = ((int)x / TILE_SIZE) + ((int)y / TILE_SIZE) * MAP_SIZE;



}

void AiSystem::dstar(float x, float y, MovementComponent& move, DiggerComponent& digger, std::vector<uint32_t>& path) //TODO: finish this 
{
	uint16_t targetid = ((int)x / TILE_SIZE) + ((int)y / TILE_SIZE) * MAP_SIZE;


}
void AiSystem::straight_line(AiComponent& ai, PositionComponent& pos)
{
	float length = hypotf(ai.lastX - pos.pos.x, ai.lastY - pos.pos.y);

}

float AiSystem::dig_time(uint32_t gridID, MovementComponent& move, DiggerComponent& digger)
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

void AiSystem::ai_track(const Vec2f& ppos, const Vec2f& psize, PositionComponent& pos, SizeComponent& size, MovementComponent& move)
{
	float px = ppos.x + psize.x / 2;
	float py = ppos.y + psize.y / 2;


	float ex = pos.pos.x + size.size.x / 2;
	float ey = pos.pos.y + size.size.y / 2;

	float targetangle = atanf((ey - py) / (ex - px));

	if (ex - px >= 0)
	{
		targetangle -= 3.14159265359f; // pi
	}

	move.angle = targetangle;

	move.velocity.x = cos(-targetangle);
	move.velocity.y = sin(targetangle);
}


bool AiSystem::is_right(float gcx, float ecx)
{
	return ecx > gcx;
}

bool AiSystem::is_down(float gcy, float ecy)
{
	return ecy > gcy;
}

