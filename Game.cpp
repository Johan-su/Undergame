#include <iostream>
#include "Game.h"


bool Game::Running;
SDL_Window* Game::window;
SDL_Renderer* Game::renderer;



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
				return 0;
			}
		}
	}

	Running = false;
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
