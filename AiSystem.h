#pragma once
#include <memory>
#include <vector>
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

	bool move_to(uint32_t gridID, PositionComponent& pos, const SizeComponent& size, MovementComponent& move, const ColliderComponent& collider);

	void Astar(float x, float y, const PositionComponent& pos, const MovementComponent& move, const DiggerComponent& digger, std::vector<uint32_t>& path);

	void dijkstra(float x, float y, const PositionComponent& pos, const MovementComponent& move, const DiggerComponent& digger, std::vector<uint32_t>& path); //TODO: if needed for performance changed float x, float y to vec2f

	void dstar(float x, float y, const PositionComponent& pos, const MovementComponent& move, const DiggerComponent& digger, std::vector<uint32_t>& path);

	uint16_t random_walk(const PositionComponent& pos, const MovementComponent& move, const DiggerComponent& digger);

	void straight_line(AiComponent& ai, PositionComponent& pos);

	float dig_time(uint32_t gridID, const MovementComponent& move, const DiggerComponent& digger);

	void ai_track(const Vec2f& ppos, const Vec2f& psize, const PositionComponent& pos, const SizeComponent& size, MovementComponent& move);

	bool is_right(float gcx, float ecx);

	bool is_down(float gcy, float ecy);

	std::shared_ptr<TargetingSystem> ts;

	std::array<float, MAP_SIZE* MAP_SIZE> distance_to_grid;

	std::array<uint32_t, MAP_SIZE* MAP_SIZE> before_grid;

	std::array<bool, MAP_SIZE* MAP_SIZE> searched_grid;

	uint32_t nodesSearched;
};