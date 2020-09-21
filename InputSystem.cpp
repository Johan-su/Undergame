#include <SDL.h>
#include "Game.h"
#include "InputSystem.h"

void InputSystem::update()
{
	switch (Game::event.type)
	{
	case SDL_QUIT:
		Game::Running = false;
		break;
	case SDL_KEYDOWN:
		key_event_down(Game::event.key.keysym.sym);
		break;
	case SDL_KEYUP:
		key_event_up(Game::event.key.keysym.sym);
		break;

	default:
		break;
	}


}
void InputSystem::key_event_down(const int& keycode) const
{
	switch (keycode)
	{
	case SDLK_w:
		for (const auto& e : m_entities)
		{
			auto& ic = Game::coordinator->get_component<InputComponent>(e);

			ic.buttonStates[0] = true;
		}
		std::cout << "W down" << std::endl;
		break;
	case SDLK_a:
		for (const auto& e : m_entities)
		{
			auto& ic = Game::coordinator->get_component<InputComponent>(e);

			ic.buttonStates[1] = true;
		}
		std::cout << "A down" << std::endl;
		break;
	case SDLK_s:
		for (const auto& e : m_entities)
		{
			auto& ic = Game::coordinator->get_component<InputComponent>(e);

			ic.buttonStates[2] = true;
		}
		std::cout << "S down" << std::endl;
		break;
	case SDLK_d:
		for (const auto& e : m_entities)
		{
			auto& ic = Game::coordinator->get_component<InputComponent>(e);

			ic.buttonStates[3] = true;
		}
		std::cout << "D down" << std::endl;
		break;


	default:
		break;
	}
}
void InputSystem::key_event_up(const int& keycode) const
{
	switch (keycode)
	{
	case SDLK_w:
		for (const auto& e : m_entities)
		{
			auto& ic = Game::coordinator->get_component<InputComponent>(e);

			ic.buttonStates[0] = false;

		}
		std::cout << "W up" << std::endl;
		break;

	default:
		break;
	}
}
