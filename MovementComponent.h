#pragma once
#include "DebugMacros.h"
#include "vecf.h"
struct MovementComponent
{
	Vec2f velocity;
	float speed;
	float rotation;

#ifdef ECS_DEBUG
	Uint32 entity;
#endif
};