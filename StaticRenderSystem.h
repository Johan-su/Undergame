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

	void render_tile(const int& x, const int& y);

private:
	std::vector<std::function<void(PositionComponent & pc, SizeComponent & sc, const int& x, const int& y)>> func_pointers;
	std::vector<SDL_Texture*> tile_textures;
};
