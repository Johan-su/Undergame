#include <SDL.h>
#include "Texture.h"
#include "ECS.h"
#include "StaticRenderSystem.h"


void StaticRenderSystem::init()
{
	tile_textures.push_back(Texture::get_texture(0));

	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 0, 0, TILE_SIZE, TILE_SIZE }), &SDL_FRect({pc.pos.x, pc.pos.y, sc.size.x, sc.size.y}));
	});



	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 64, 0, TILE_SIZE, TILE_SIZE }), &SDL_FRect({pc.pos.x, pc.pos.y, sc.size.x, sc.size.y}));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 128, 0, TILE_SIZE, TILE_SIZE }), &SDL_FRect({pc.pos.x, pc.pos.y, sc.size.x, sc.size.y}));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 192, 0, TILE_SIZE, TILE_SIZE }), &SDL_FRect({pc.pos.x, pc.pos.y, sc.size.x, sc.size.y}));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 256, 0, TILE_SIZE, TILE_SIZE }), &SDL_FRect({pc.pos.x, pc.pos.y, sc.size.x, sc.size.y}));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 0, 1, TILE_SIZE, TILE_SIZE }), &SDL_FRect({pc.pos.x, pc.pos.y, sc.size.x, sc.size.y}));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 64, 1, TILE_SIZE, TILE_SIZE }), &SDL_FRect({pc.pos.x, pc.pos.y, sc.size.x, sc.size.y}));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 128, 1, TILE_SIZE, TILE_SIZE }), &SDL_FRect({pc.pos.x, pc.pos.y, sc.size.x, sc.size.y}));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 192, 1, TILE_SIZE, TILE_SIZE }), &SDL_FRect({pc.pos.x, pc.pos.y, sc.size.x, sc.size.y}));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 256, 1, TILE_SIZE, TILE_SIZE }), &SDL_FRect({pc.pos.x, pc.pos.y, sc.size.x, sc.size.y}));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 0, 2, TILE_SIZE, TILE_SIZE }), &SDL_FRect({pc.pos.x, pc.pos.y, sc.size.x, sc.size.y}));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 64, 2, TILE_SIZE, TILE_SIZE }), &SDL_FRect({pc.pos.x, pc.pos.y, sc.size.x, sc.size.y}));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 128, 2, TILE_SIZE, TILE_SIZE }), &SDL_FRect({pc.pos.x, pc.pos.y, sc.size.x, sc.size.y}));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 192, 2, TILE_SIZE, TILE_SIZE }), &SDL_FRect({pc.pos.x, pc.pos.y, sc.size.x, sc.size.y}));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 256, 2, TILE_SIZE, TILE_SIZE }), &SDL_FRect({pc.pos.x, pc.pos.y, sc.size.x, sc.size.y}));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 0, 3, TILE_SIZE, TILE_SIZE }), &SDL_FRect({pc.pos.x, pc.pos.y, sc.size.x, sc.size.y}));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 64, 3, TILE_SIZE, TILE_SIZE }), &SDL_FRect({pc.pos.x, pc.pos.y, sc.size.x, sc.size.y}));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 128, 3, TILE_SIZE, TILE_SIZE }), &SDL_FRect({pc.pos.x, pc.pos.y, sc.size.x, sc.size.y}));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 192, 3, TILE_SIZE, TILE_SIZE }), &SDL_FRect({pc.pos.x, pc.pos.y, sc.size.x, sc.size.y}));
	});


	func_pointers.push_back([&](PositionComponent& pc, SizeComponent& sc)
	{
		SDL_RenderCopyF(Game::renderer, tile_textures[0], &SDL_Rect({ 256, 3, TILE_SIZE, TILE_SIZE }), &SDL_FRect({pc.pos.x, pc.pos.y, sc.size.x, sc.size.y}));
	});


}


void StaticRenderSystem::render_tile()
{
	for (const auto& e : m_entities)
	{
		auto& pc = Game::coordinator->get_component<PositionComponent>(e);
		auto& sc = Game::coordinator->get_component<SizeComponent>(e);
		auto& tc = Game::coordinator->get_component<TileComponent>(e);

		const auto& func = func_pointers[tc.type];
		func(pc, sc);
	}
}