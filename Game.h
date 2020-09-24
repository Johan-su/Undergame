#pragma once
#include <SDL.h>
#include "ECS.h"

class Game //TODO: change to namespace
{
public:


	static bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	
	static void clean();

	static void update();

	static void events();

	static void render();

	static void ECS_init();

	static void components_init();

	static void systems_init();

public:
	static bool Running;
	static SDL_Window* window;
	static SDL_Renderer* renderer;
	static SDL_Event event;
	static Coordinator* coordinator;
	static std::vector<Entity>* entities;

private:
	Game();

private:
};