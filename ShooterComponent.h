#pragma once
#include "DebugMacros.h"
struct ShooterComponent
{
	float gunlength;
	bool states[4];

#ifdef ECS_DEBUG
	 uint32_t entity;
#endif
};