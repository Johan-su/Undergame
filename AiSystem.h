#pragma once
#include "ECS.h"
class AiSystem : public System
{
public:

	void update();





private:

	void move_to_diagonally();

	void move_to();

	void Astar();

	void dijkstra();

	void greedy();

	void straight_line();



};