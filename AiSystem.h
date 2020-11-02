#pragma once
#include <memory>
#include "DebugMacros.h"
#include "System.h"
#include "TargetingSystem.h"
#include "PositionComponent.h"
#include "MovementComponent.h"
#include "AiComponent.h"
#include "DiggerComponent.h"

class AiSystem : public System
{
public:

	void init(std::shared_ptr<TargetingSystem> sys);

	void clean();

	void update();





private:

	bool move_to(uint32_t gridID, PositionComponent& pos, SizeComponent& size, MovementComponent& move);

	void Astar(float x, float y, MovementComponent& move, DiggerComponent& digger, std::vector<uint32_t>& path);

	void dijkstra(float x, float y, MovementComponent& move, DiggerComponent& digger, std::vector<uint32_t>& path); //TODO: if needed for performance changed float x, float y to vec2f

	void greedy(float x, float y, MovementComponent& move, DiggerComponent& digger, std::vector<uint32_t>& path);

	void straight_line(AiComponent& ai, PositionComponent& pos);

	float dig_time(uint16_t gridID, MovementComponent& move, DiggerComponent& digger);

	void ai_track(Vec2f ppos, Vec2f psize, PositionComponent& pos, SizeComponent& size, MovementComponent& move);

	std::shared_ptr<TargetingSystem> ts;
};