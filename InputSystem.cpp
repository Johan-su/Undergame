#include <SDL.h>
#include "Game.h"
#include "InputSystem.h"

void InputSystem::update()
{
	mouse_pos();
	switch (Game::event.type)
	{
	case SDL_QUIT:
		Game::Running = false;
		break;

	case SDL_MOUSEBUTTONDOWN:
		mouse_event_down();
		break;

	case SDL_MOUSEBUTTONUP:
		mouse_event_up();
		break;

	case SDL_KEYDOWN:
		key_event_down();
		break;

	case SDL_KEYUP:
		key_event_up();
		break;
	}
}

void InputSystem::mouse_pos() const
{
	for (const auto& e : m_entities)
	{
		auto& ic = Game::coordinator->get_component<InputComponent>(e);
		ic.x = Game::event.button.x + Game::offsetx;
		ic.y = Game::event.button.y + Game::offsety;

	}
}


void InputSystem::mouse_event_down() const
{
	switch (Game::event.button.button)
	{
	case SDL_BUTTON_LEFT:
		for (const auto& e : m_entities)
		{
		auto& ic = Game::coordinator->get_component<InputComponent>(e);

		ic.buttonStates[4] = true;
		std::cout << "mouse_left down" << std::endl;
		std::cout << "mouse_x " << ic.x << " mouse_y " << ic.y << std::endl;
		}
		break;
	case SDL_BUTTON_MIDDLE:
		for (const auto& e : m_entities)
		{
			auto& ic = Game::coordinator->get_component<InputComponent>(e);

			ic.buttonStates[5] = true;
			std::cout << "mouse_middle down" << std::endl;
			std::cout << "mouse_x " << ic.x << " mouse_y " << ic.y << std::endl;

		}
		break;
	case SDL_BUTTON_RIGHT:
		for (const auto& e : m_entities)
		{
			auto& ic = Game::coordinator->get_component<InputComponent>(e);

			ic.buttonStates[6] = true;
			std::cout << "mouse_right down" << std::endl;
			std::cout << "mouse_x " << ic.x << " mouse_y " << ic.y << std::endl;

		}
		break;
	}
	
}
void InputSystem::mouse_event_up() const
{
	switch (Game::event.button.button)
	{
	case SDL_BUTTON_LEFT:
		for (const auto& e : m_entities)
		{
			auto& ic = Game::coordinator->get_component<InputComponent>(e);

			ic.buttonStates[4] = false;
			std::cout << "mouse_left up" << std::endl;
			std::cout << "mouse_x " << ic.x << " mouse_y " << ic.y << std::endl;

		}
		break;
	case SDL_BUTTON_MIDDLE:
		for (const auto& e : m_entities)
		{
			auto& ic = Game::coordinator->get_component<InputComponent>(e);

			ic.buttonStates[5] = false;
			std::cout << "mouse_middle up" << std::endl;
			std::cout << "mouse_x " << ic.x << " mouse_y " << ic.y << std::endl;

		}
		break;
	case SDL_BUTTON_RIGHT:
		for (const auto& e : m_entities)
		{
			auto& ic = Game::coordinator->get_component<InputComponent>(e);

			ic.buttonStates[6] = false;
			std::cout << "mouse_right up" << std::endl;
			std::cout << "mouse_x " << ic.x << " mouse_y " << ic.y << std::endl;

		}
		break;
	}
}



void InputSystem::key_event_down() const
{
	switch (Game::event.key.keysym.sym)
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
	}
}

void InputSystem::key_event_up() const
{
	switch (Game::event.key.keysym.sym)
	{
	case SDLK_w:
		for (const auto& e : m_entities)
		{
			auto& ic = Game::coordinator->get_component<InputComponent>(e);

			ic.buttonStates[0] = false;

		}
		std::cout << "W up" << std::endl;
		break;
	case SDLK_a:
		for (const auto& e : m_entities)
		{
			auto& ic = Game::coordinator->get_component<InputComponent>(e);

			ic.buttonStates[1] = false;
		}
		std::cout << "A up" << std::endl;
		break;
	case SDLK_s:
		for (const auto& e : m_entities)
		{
			auto& ic = Game::coordinator->get_component<InputComponent>(e);

			ic.buttonStates[2] = false;
		}
		std::cout << "S up" << std::endl;
		break;
	case SDLK_d:
		for (const auto& e : m_entities)
		{
			auto& ic = Game::coordinator->get_component<InputComponent>(e);

			ic.buttonStates[3] = false;
		}
		std::cout << "D up" << std::endl;
		break;
	}
}
