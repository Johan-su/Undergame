#include <SDL.h>
#include "DebugMacros.h"
#include "RenderSystem.h"
#include "ECS.h"
#include "Game.h"


void RenderSystem::render(int offx, int offy)
{
	for (auto e : m_entities)
	{
		auto& render = Game::coordinator->get_component<RenderComponent>(e);
		auto& position = Game::coordinator->get_component<PositionComponent>(e);
		auto& size = Game::coordinator->get_component<SizeComponent>(e);
		auto& move = Game::coordinator->get_component<MovementComponent>(e);

#ifdef ECS_DEBUG
		SDL_assert(render.entity == e);
		SDL_assert(position.entity == e);
		SDL_assert(size.entity == e);
		SDL_assert(move.entity == e);
#endif

		SDL_FRect dst_rect = { position.pos.x - (float)offx, position.pos.y - (float)offy, size.size.x, size.size.y };



		SDL_RenderCopyExF(Game::renderer, render.texture, &render.src_rect, &dst_rect, static_cast<double>((1.57079632679 + static_cast<double>(move.rotation)) * 57.29577951310), NULL, SDL_FLIP_NONE); // 57.2957795131 == 180 / PI //TODO: there may be a bug with rotation in render.
	}
}
