#pragma once
#include "ECS.h"
class AiSystem : public System
{
public:

	void update();





private:

	void move_to_diagonally();

	void move_to();

	float Astar(float x, float y, AiComponent& ai);

	float dijkstra(float x, float y, AiComponent& ai);

	float greedy(float x, float y, AiComponent& ai);

	float straight_line(AiComponent& ai, PositionComponent& pos);


};