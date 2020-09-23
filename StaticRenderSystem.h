#pragma once
#include <functional>
#include <array>
#include <SDL.h>
#include "ECS.h"
#include "Tilemap.h"

class StaticRenderSystem : System
{
public:

	void init();

	void render_tile();

private:
	std::vector<std::function<void(PositionComponent& pc, SizeComponent& sc)>> func_pointers;
	//std::vector<std::function<void()>> func_pointers;
	std::vector<SDL_Texture*> tile_textures;
};
