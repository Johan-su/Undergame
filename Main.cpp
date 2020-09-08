#include <chrono>
#include <iostream>
#include <SDL.h>
#include "Game.h"

int main(int argc, char* argv[])
{
	if (Game::init("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 576, 0))
	{
		std::cout << "SDL_initalization failed" << std::endl;
		std::cin;
		return 1;
	}

	auto MS_PER_UPDATE = std::chrono::nanoseconds(16666666);


	auto previous = std::chrono::high_resolution_clock::now();
	std::chrono::nanoseconds lag(0);
	while (Game::Running) {
		auto current = std::chrono::high_resolution_clock::now();
		auto elapsed = current - previous;
		previous = current;
		lag += elapsed;

		Game::events();

		while (lag >= MS_PER_UPDATE)
		{
			Game::update();
			lag -= MS_PER_UPDATE;
		}
		Game::render();
	}
	Game::clean();
	return 0;
}

