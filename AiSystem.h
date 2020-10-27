#pragma once
#include <memory>
#include "DebugMacros.h"
#include "PositionComponent.h"
#include "AiComponent.h"
#include "System.h"
#include "TargetingSystem.h"
class AiSystem : public System
{
public:

	void init(std::shared_ptr<TargetingSystem> sys);

	void clean();

	void update();





private:

	void move_to(uint32_t gridID);

	void Astar(float x, float y, std::vector<uint32_t>& path);

	void dijkstra(float x, float y, std::vector<uint32_t>& path); //TODO: if needed for performance changed float x, float y to vec2f

	void greedy(float x, float y, std::vector<uint32_t>& path);

	void straight_line(AiComponent& ai, PositionComponent& pos);

	std::shared_ptr<TargetingSystem> ts;
};