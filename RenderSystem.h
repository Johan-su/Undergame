#pragma once
#include "DebugMacros.h"
#include "ECS.h"


class RenderSystem : public System
{
public:
	void render(const int& x, const int& y);
};