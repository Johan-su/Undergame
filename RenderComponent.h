#pragma once
#include <SDL.h>
#include "DebugMacros.h"

struct RenderComponent
{
	SDL_Rect src_rect;
	SDL_Texture* texture;

#ifdef ECS_DEBUG
	Uint32 entity;
#endif
};