#pragma once
#include <SDL.h>
#include "vecf.h"

struct RenderComponent
{
	SDL_Rect srcrect;
	SDL_Texture* texture;
};