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


void StaticRenderSystem::render_tile(int x, int y)
{
	for (auto e : m_entities)
	{
		auto& pc = Game::coordinator->get_component<PositionComponent>(e);
		auto& sc = Game::coordinator->get_component<SizeComponent>(e);

		bool b1 = pc.pos.x < 0 + x + SCREEN_WIDTH;

		bool b2 = pc.pos.x + sc.size.x > 0 + x;

		bool b3 = pc.pos.y < 0 + y + SCREEN_HEIGHT;

		bool b4 = pc.pos.y + sc.size.y > 0 + y;


		if (b1 && b2 && b3 && b4)
		{
		auto& tc = Game::coordinator->get_component<TileComponent>(e);

#ifdef ECS_DEBUG
		SDL_assert(pc.entity == e);
		SDL_assert(sc.entity == e);
		SDL_assert(tc.entity == e);
#endif

		const auto& func = func_pointers[tc.type];
		func(pc, sc, x, y);
		}


	}
}