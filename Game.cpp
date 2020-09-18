#include <iostream>
#include "Game.h"
#include "ECS.h"


bool Game::Running;
SDL_Window* Game::window;
SDL_Renderer* Game::renderer;
std::shared_ptr<System> Game::renderSystem;



bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Systems initialized" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			std::cout << "window created" << std::endl;

			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer) {
				std::cout << "renderer created" << std::endl;
				if (ECS_init())
				{
				Running = true;
				return 0;
				}
			}
		}
	}

	Running = false;
	return 1;

}
bool Game::ECS_init()
{
	g_coordinator = new Coordinator();
	g_coordinator->init();
	std::cout << "coordinator" << g_coordinator << std::endl;
	std::cout << "Coordinator initalized" << std::endl;
	if (components_init())
	{
		std::cout << "Components initalized" << std::endl;
		if (systems_init())
		{
			return 1;
		}
	}

	return 0;
}
bool Game::components_init()
{
	g_coordinator->register_component<TransformComponent>();
	g_coordinator->register_component<RenderComponent>();
	g_coordinator->register_component<PlayerComponent>();
	g_coordinator->register_component<HealthComponent>();
	return 1;
}
bool Game::systems_init()
{
	renderSystem = g_coordinator->register_system<RenderSystem>();
	std::bitset<MAX_COMPONENTS> sig;

	sig.set(g_coordinator->get_signature_pos<TransformComponent>());
	sig.set(g_coordinator->get_signature_pos<RenderComponent>());
	std::cout << typeid(RenderSystem).name() << sig << std::endl;

	g_coordinator->set_signature(renderSystem, sig);
	return 1;
}
void Game::clean()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
void Game::update()
{

}
void Game::events()
{

}
void Game::render()
{

}
