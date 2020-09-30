#pragma once
#include <SDL.h>
#include "Game.h"
#include "ECS.h"
class InputSystem : public System
{
public:
	void update();

	void mouse_pos() const;

	void mouse_event_down() const;

	void mouse_event_up() const;

	void key_event_down() const;

	void key_event_up() const;

private:

};