#include <SDL.h>
#include "RenderSystem.h"
#include "ECS.h"
#include "Game.h"


void RenderSystem::render(const int& x, const int& y)
{
	for (const auto& e : m_entities)
	{
		auto& render = Game::coordinator->get_component<RenderComponent>(e);
		auto& position = Game::coordinator->get_component<PositionComponent>(e);
		auto& size = Game::coordinator->get_component<SizeComponent>(e);
		auto& move = Game::coordinator->get_component<MovementComponent>(e);

		SDL_RenderCopyExF(Game::renderer, render.texture, &render.src_rect, &SDL_FRect({ position.pos.x - x, position.pos.y - y, size.size.x, size.size.y }), move.rotation * 57.2957795131f, NULL, SDL_FLIP_NONE); // 57.2957795131 == 180 / PI
	}
}


