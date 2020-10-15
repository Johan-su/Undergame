#pragma once
#include "DebugMacros.h"
struct ShooterComponent
{
	float gunlength;
	bool states[4];

#ifdef ECS_DEBUG
	Uint32 entity;
#endif
};