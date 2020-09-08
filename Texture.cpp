#include "Texture.h"
#include "Game.h"

SDL_Texture* Texture::Texture_load(const char* path)
{
	return SDL_CreateTextureFromSurface(Game::renderer, SDL_LoadBMP(path));
}