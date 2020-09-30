#pragma once
#include <SDL.h>
#include "ECS.h"
struct InputComponent
{
	bool buttonStates[7];
	int x;
	int y;
};