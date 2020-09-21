#pragma once
#include <SDL.h>
#include "Game.h"
#include "ECS.h"
class InputSystem : public System
{
public:
	void update();

	void key_event_down(const int& keycode) const;

	void key_event_up(const int& keycode) const;

private:

};