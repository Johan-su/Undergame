#include <iostream>
#include "Game.h"
#include "Texture.h"
#include "ECS.h"


bool Game::Running;
SDL_Window* Game::window;
SDL_Renderer* Game::renderer;
SDL_Event Game::event;
Coordinator* Game::coordinator;

std::vector<Entity>* Game::entities;

static std::shared_ptr<InputSystem> inputSystem;
static std::shared_ptr<PhysicsSystem> physicsSystem;
static std::shared_ptr<PlayerSystem> playerSystem;
static std::shared_ptr<RenderSystem> renderSystem;
static std::shared_ptr<StaticRenderSystem> staticRenderSystem;



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
				Texture::init();
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
	SDL_RenderClear(renderer);

	//SDL_RenderCopy(renderer, Texture::get_texture(1), NULL, NULL);

	staticRenderSystem->render_tile();


	SDL_RenderPresent(renderer);
}

void Game::ECS_init()
{
	Game::coordinator = new Coordinator();
	Game::coordinator->init();
	Game::coordinator->test();
	components_init();
	systems_init();
	Game::entities = new std::vector<Entity>(MAX_ENTITIES);
}

void Game::components_init()
{
	Game::coordinator->register_component<TileComponent>();
	Game::coordinator->register_component<SizeComponent>();
	Game::coordinator->register_component<RenderComponent>();
	Game::coordinator->register_component<PositionComponent>();
	Game::coordinator->register_component<PlayerComponent>();
	Game::coordinator->register_component<MovementComponent>();
	Game::coordinator->register_component<InputComponent>();
	Game::coordinator->register_component<HealthComponent>();
	Game::coordinator->register_component<ColliderComponent>();
}

void Game::systems_init()
{
	std::bitset<MAX_COMPONENTS> sig;

	inputSystem = Game::coordinator->register_system<InputSystem>();
	sig.set(Game::coordinator->get_signature_pos<InputComponent>());
	Game::coordinator->set_signature(inputSystem, sig);
	sig.reset();


	renderSystem = Game::coordinator->register_system<RenderSystem>();
	sig.set(Game::coordinator->get_signature_pos<RenderComponent>());
	sig.set(Game::coordinator->get_signature_pos<PositionComponent>());
	sig.set(Game::coordinator->get_signature_pos<SizeComponent>());
	sig.set(Game::coordinator->get_signature_pos<MovementComponent>());
	Game::coordinator->set_signature(renderSystem, sig);
	sig.reset();

	staticRenderSystem = Game::coordinator->register_system<StaticRenderSystem>();
	sig.set(Game::coordinator->get_signature_pos<TileComponent>());
	sig.set(Game::coordinator->get_signature_pos<SizeComponent>());
	sig.set(Game::coordinator->get_signature_pos<PositionComponent>());
	sig.set(Game::coordinator->get_signature_pos<HealthComponent>());
	Game::coordinator->set_signature(staticRenderSystem, sig);
	staticRenderSystem->init();
	sig.reset();



}
