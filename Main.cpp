//#include <chrono>
#include <iostream>
#include <SDL.h>
#include "ECS.h"
#include "Game.h"


#define arrSize 10
int main(int argc, char* argv[])
{
	EntityManager *em = new EntityManager();
	Entity eArr[arrSize];
	for (int i = 0; i < arrSize; ++i)
	{
		eArr[i] = em->Create_entity();
	}
	for (int i = 0; i < arrSize; ++i)
	{
		std::cout << "ID " << i << " = " << eArr[i].id << std::endl;
	}
	ComponentArray<int> *ca = new ComponentArray<int>();



	for (int i = 0; i < arrSize; ++i)
	{
		ca->add_component(eArr[i], i);
	}


	Entity e = em->Create_entity();

	ca->add_component(e,9999);
	em->Destroy_entity(eArr[2]);
	ca->destroy_component(eArr[2]);

	std::cout << ca->get_component(eArr[2]) << std::endl;

	for (unsigned int i = 0; i < ca->get_size(); ++i)
	{
		std::cout << "ca" << "ID " << i << " = " << ca->get_component(eArr[i]) << std::endl;
	}
	std::cout << "ca" << "ID " << e.id << " = " << ca->get_component(e) << std::endl;

	std::cin.ignore();
	delete ca;
	delete em;

	/*if (Game::init("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 576, 0))
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
	Game::clean();*/
	return 0;
}

