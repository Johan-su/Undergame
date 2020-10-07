#include <SDL.h>
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
		auto& tc = Game::coordinator->get_component<TileComponent>(e);


		if (pc.pos.x >= -100 + x && pc.pos.y >= -100 + y && pc.pos.x <= SCREEN_WIDTH + 100 + x && pc.pos.y <= SCREEN_HEIGHT + 100 + y)
		{
		const auto& func = func_pointers[tc.type];
		func(pc, sc, x, y);
		}


	}
}