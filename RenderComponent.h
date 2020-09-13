#pragma once
#include <SDL.h>

struct RenderComponent
{
	SDL_Rect src_rect;
	SDL_Texture* texture;
};