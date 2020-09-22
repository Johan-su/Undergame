#pragma once
#include <functional>
#include <array>
#include <SDL.h>
#include "ECS.h"
#include "Tilemap.h"

class StaticRenderSystem : System
{
public:

	void init(TileMap* tilemap);

	void render_tile();

	void render_background_tile();

	std::unique_ptr<std::vector<unsigned int>> active_background_tiles_id;
private:
	std::vector<std::function<void()>> func_pointers;
	std::vector<std::function<void()>> background_func_pointers;
	std::vector<SDL_Texture*> tile_textures;
	std::vector<SDL_Texture*> background_tiles_textures;
	TileMap* m_tilemap;
};
