#pragma once
#include <functional>
#include <array>
#include <SDL.h>
#include "ECS.h"
#include "Tilemap.h"

class StaticRenderSystem : public System
{
public:

	void init();

	void render_tile(int x, int y);

private:
	std::vector<std::function<void(PositionComponent & pc, SizeComponent & sc, int x, int y)>> func_pointers;
	std::vector<SDL_Texture*> tile_textures;
};
