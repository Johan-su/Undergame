#include <SDL.h>
#include "ECS.h"

#include "StaticRenderSystem.h"


void StaticRenderSystem::init(TileMap* tilemap)
{
	StaticRenderSystem::active_background_tiles_id = std::unique_ptr<std::vector<unsigned int>>(new std::vector<unsigned int>);
	m_tilemap = tilemap;
	if (m_tilemap == nullptr)
	{
		throw "tilemap not initalized";
	}
	for (unsigned int i = 0; i < m_tilemap->grid.size(); ++i)
	{
		if (m_tilemap->grid[i] == 0)
		{
			active_background_tiles_id->push_back(i);
		}
	}

	func_pointers.push_back([](const float& x, const float& y)
	{
		//SDL_RenderCopy(Game::renderer, tile_textures[0]); //TODO: fix srcdest and textures
	});
	func_pointers.push_back([](const float& x, const float& y)
	{
		//SDL_RenderCopy(Game::renderer, tile_textures[0]); //TODO: fix srcdest and textures
	});
	background_func_pointers.push_back([](const float& x, const float& y)
	{
			adasd..
		//SDL_RenderCopy(Game::renderer, tile_textures[0]); //TODO: fix srcdest and textures
	});


}


void StaticRenderSystem::render_tile()
{
	for (const auto& e : m_entities)
	{
		std::cout << "entity in static rendersystem " << e << std::endl;
		auto& tc = Game::coordinator->get_component<TileComponent>(e);

		const auto& func = func_pointers[tc.type];
		func(tc.pos.x, tc.pos.y);
	}
}
void StaticRenderSystem::render_background_tile()
{
	for (const auto& i : *active_background_tiles_id)
	{

		const auto& x = i % 4096;
		const auto& y = i / 4096;
		const auto& type = m_tilemap->grid[i];
		const auto& func = background_func_pointers[type];
		func(x, y);
	}
}