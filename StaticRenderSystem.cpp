#include <iostream>
#include <SDL.h>
#include "DebugMacros.h"
#include "Texture.h"
#include "ECS.h"
#include "StaticRenderSystem.h"

void StaticRenderSystem::init()
{
	tile_textures.push_back(Texture::get_texture(0));

	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc, int x, int y)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 0, 0, TILE_SIZE, TILE_SIZE }), &SDL_FRect({ pc.pos.x - x, pc.pos.y - y, sc.size.x, sc.size.y })); // 0
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc, int x, int y)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 64, 0, TILE_SIZE, TILE_SIZE }), &SDL_FRect({ pc.pos.x - x, pc.pos.y - y, sc.size.x, sc.size.y }));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc, int x, int y)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 128, 0, TILE_SIZE, TILE_SIZE }), &SDL_FRect({ pc.pos.x - x, pc.pos.y - y, sc.size.x, sc.size.y }));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc, int x, int y)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 192, 0, TILE_SIZE, TILE_SIZE }), &SDL_FRect({ pc.pos.x - x, pc.pos.y - y, sc.size.x, sc.size.y }));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc, int x, int y)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 256, 0, TILE_SIZE, TILE_SIZE }), &SDL_FRect({ pc.pos.x - x, pc.pos.y - y, sc.size.x, sc.size.y }));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc, int x, int y)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 0, 64, TILE_SIZE, TILE_SIZE }), &SDL_FRect({ pc.pos.x - x, pc.pos.y - y, sc.size.x, sc.size.y }));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc, int x, int y)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 64, 64, TILE_SIZE, TILE_SIZE }), &SDL_FRect({ pc.pos.x - x, pc.pos.y - y, sc.size.x, sc.size.y }));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc, int x, int y)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 128, 64, TILE_SIZE, TILE_SIZE }), &SDL_FRect({ pc.pos.x - x, pc.pos.y - y, sc.size.x, sc.size.y }));
	});

	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc, int x, int y)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 192, 64, TILE_SIZE, TILE_SIZE }), &SDL_FRect({ pc.pos.x - x, pc.pos.y - y, sc.size.x, sc.size.y }));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc, int x, int y)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 256, 64, TILE_SIZE, TILE_SIZE }), &SDL_FRect({ pc.pos.x - x, pc.pos.y - y, sc.size.x, sc.size.y }));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc, int x, int y)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 0, 128, TILE_SIZE, TILE_SIZE }), &SDL_FRect({ pc.pos.x - x, pc.pos.y - y, sc.size.x, sc.size.y }));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc, int x, int y)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 64, 128, TILE_SIZE, TILE_SIZE }), &SDL_FRect({ pc.pos.x - x, pc.pos.y - y, sc.size.x, sc.size.y }));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc, int x, int y)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 128, 128, TILE_SIZE, TILE_SIZE }), &SDL_FRect({ pc.pos.x - x, pc.pos.y - y, sc.size.x, sc.size.y }));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc, int x, int y)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 192, 128, TILE_SIZE, TILE_SIZE }), &SDL_FRect({ pc.pos.x - x, pc.pos.y - y, sc.size.x, sc.size.y })); // 13
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc, int x, int y)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 256, 128, TILE_SIZE, TILE_SIZE }), &SDL_FRect({ pc.pos.x - x, pc.pos.y - y, sc.size.x, sc.size.y }));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc, int x, int y)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 0, 192, TILE_SIZE, TILE_SIZE }), &SDL_FRect({ pc.pos.x - x, pc.pos.y - y, sc.size.x, sc.size.y }));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc, int x, int y)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 64, 192, TILE_SIZE, TILE_SIZE }), &SDL_FRect({ pc.pos.x - x, pc.pos.y - y, sc.size.x, sc.size.y}));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc, int x, int y)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 128, 192, TILE_SIZE, TILE_SIZE }), &SDL_FRect({ pc.pos.x - x, pc.pos.y - y, sc.size.x, sc.size.y}));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc, int x, int y)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 192, 192, TILE_SIZE, TILE_SIZE }), &SDL_FRect({ pc.pos.x - x, pc.pos.y - y, sc.size.x, sc.size.y}));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc, int x, int y)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 256, 192, TILE_SIZE, TILE_SIZE }), &SDL_FRect({ pc.pos.x - x, pc.pos.y - y, sc.size.x, sc.size.y}));
	});
}


void StaticRenderSystem::render_tiles(int offx, int offy) //TODO: optimize using tilegrid
{
	int x0 = offx - TILE_SIZE;
	int y0 = offy - TILE_SIZE;
	int x1 = offx + SCREEN_WIDTH + TILE_SIZE;
	int y1 = offy + SCREEN_HEIGHT + TILE_SIZE;

	int gridamountx = (x1 - x0) / 64;
	int gridamounty = (y1 - y0) / 64;

	//Uint16 gid[((SCREEN_WIDTH + 2 * TILE_SIZE) / TILE_SIZE) * ((SCREEN_HEIGHT + 2 * TILE_SIZE) / TILE_SIZE)];

	Uint16 gidtl = MAP_SIZE * (y0 / TILE_SIZE) + x0 / TILE_SIZE; // id of top left tile

	for (Uint32 y = 0; y < (SCREEN_HEIGHT + 2 * TILE_SIZE) / TILE_SIZE; ++y)
	{
		for (Uint32 x = 0; x < (SCREEN_WIDTH + 2 * TILE_SIZE) / TILE_SIZE; ++x)
		{
			auto id = gidtl + x + y * MAP_SIZE; 
			render_tile(id, offx, offy);
		} 
	}
}
void StaticRenderSystem::render_tile(Uint16 e, int offx, int offy)
{
	auto type = Game::tileEntities[e];
	//std::cout << "type " << type << std::endl;
	if (type == 0)
	{
		return;
	}


	//auto& pc = Game::coordinator->get_component<PositionComponent>(e);
	//auto& sc = Game::coordinator->get_component<SizeComponent>(e);
	//auto& tc = Game::coordinator->get_component<TileComponent>(e);
	auto pc = PositionComponent();
	auto sc = SizeComponent();

	pc.entity = e;
	sc.entity = e;

	pc.pos.x = TILE_SIZE * (e % MAP_SIZE);
	pc.pos.y = TILE_SIZE * (e / MAP_SIZE);

	sc.size.x = TILE_SIZE;
	sc.size.y = TILE_SIZE;


#ifdef ECS_DEBUG
	SDL_assert(pc.entity == e);
	SDL_assert(sc.entity == e);
	//SDL_assert(tc.entity == e);
#endif


	const auto& func = func_pointers[type];
	func(pc, sc, offx, offy);
}