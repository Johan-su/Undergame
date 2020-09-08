#pragma once
#include <SDL.h>
class Game
{
public:


	static bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	static void clean();

	static void update();

	static void events();

	static void render();

public:
	static bool Running;

	static SDL_Window* window;
	static SDL_Renderer* renderer;

private:
	Game();

private:
};