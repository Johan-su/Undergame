#pragma once
#include <SDL.h>
#include "DebugMacros.h"
#include "ECS.h"
struct InputComponent
{
	bool buttonStates[7];
	int x;
	int y;

#ifdef ECS_DEBUG
	Uint32 entity;
#endif
};