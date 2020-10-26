#pragma once
#include "DebugMacros.h"
#include "ECS.h"
class AiSystem : public System
{
public:

	void clean();

	void update();





private:

	void move_to_diagonally();

	void move_to();

	void Astar(float x, float y, AiComponent& ai);

	void dijkstra(float x, float y, AiComponent& ai);

	void greedy(float x, float y, AiComponent& ai);

	void straight_line(AiComponent& ai, PositionComponent& pos);

	std::vector<uint32_t>* path_list;
};