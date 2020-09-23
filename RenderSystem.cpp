#include <SDL.h>
#include "RenderSystem.h"
#include "ECS.h"
#include "Game.h"


void RenderSystem::render()
{
	for (const auto& e : m_entities)
	{
		std::cout << "entity in rendersystem " << e << std::endl;
		auto& render = Game::coordinator->get_component<RenderComponent>(e);
		auto& position = Game::coordinator->get_component<PositionComponent>(e);
		auto& size = Game::coordinator->get_component<SizeComponent>(e);
		auto& move = Game::coordinator->get_component<MovementComponent>(e);

		SDL_RenderCopyExF(Game::renderer, render.texture, &render.src_rect, &SDL_FRect({ position.pos.x, position.pos.y, size.size.x, size.size.y }), move.rotation, NULL, SDL_FLIP_NONE);
	}
}


