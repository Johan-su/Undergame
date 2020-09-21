#include <iostream>
#include "Game.h"
#include "ECS.h"


bool Game::Running;
SDL_Window* Game::window;
SDL_Renderer* Game::renderer;
SDL_Event Game::event;
Coordinator* Game::coordinator;

static std::shared_ptr<RenderSystem> renderSystem;
static std::shared_ptr<InputSystem> inputSystem;



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
				Running = true;
				ECS_init();
				return 0;
			}
		}
	}

	Running = false;
	return 1;

}
void Game::clean()
{
	coordinator->clean();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
void Game::update()
{

}
void Game::events()
{
	while (SDL_PollEvent(&event))
	{
		inputSystem->update();
	}
}
void Game::render()
{

}

void Game::ECS_init()
{
	Game::coordinator = new Coordinator();
	Game::coordinator->init();
	Game::coordinator->test();
	components_init();
	systems_init();
}

void Game::components_init()
{
	Game::coordinator->register_component<TransformComponent>();
	Game::coordinator->register_component<RenderComponent>();
	Game::coordinator->register_component<PlayerComponent>();
	Game::coordinator->register_component<InputComponent>();
	Game::coordinator->register_component<HealthComponent>();
}

void Game::systems_init()
{
	renderSystem = Game::coordinator->register_system<RenderSystem>();
	std::bitset<MAX_COMPONENTS> sig;
	sig.set(Game::coordinator->get_signature_pos<TransformComponent>());
	sig.set(Game::coordinator->get_signature_pos<RenderComponent>());
	Game::coordinator->set_signature(renderSystem, sig);

	inputSystem = Game::coordinator->register_system<InputSystem>();
	sig.set(Game::coordinator->get_signature_pos<InputComponent>());
	Game::coordinator->set_signature(inputSystem, sig);
}
