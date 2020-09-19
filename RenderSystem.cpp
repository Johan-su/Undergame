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
		auto& transform = Game::coordinator->get_component<TransformComponent>(e);

		SDL_RenderCopyExF(Game::renderer, render.texture, &render.src_rect, &SDL_FRect({ transform.position.x, transform.position.y, transform.size.x, transform.size.y }), transform.rotation, NULL, SDL_FLIP_NONE);
	}
}


