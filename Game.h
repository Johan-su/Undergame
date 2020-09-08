#pragma once
#include <SDL.h>
class Game
{
public:
	Game();
	~Game();


	void init();

	void clean();

	void update();

	void render();

public:
	static SDL_renderer* renderer;

private:

private:
};