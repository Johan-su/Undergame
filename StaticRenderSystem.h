#pragma once
#include <functional>
#include <array>
#include <SDL.h>
#include "DebugMacros.h"
#include "ECS.h"
#include "Tilemap.h"

class StaticRenderSystem : public System
{
public:

	void init();

	void render_tiles(int offx, int offy);

	void render_tile(Uint16 e, int offx, int offy);

private:
	std::vector<std::function<void(float x, float y, int offx, int offy)>> func_pointers;
	std::vector<SDL_Texture*> tile_textures;
};
