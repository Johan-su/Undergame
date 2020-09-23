#include <vector>
#include "Texture.h"
#include "Game.h"

std::vector<SDL_Texture*>* Texture::m_textures;


void Texture::init()
{
	m_textures = new std::vector<SDL_Texture*>;
	load_texture("resources/textures/tilesheet/TileSheet.bmp");






}

void Texture::load_texture(const char* path)
{
	m_textures->push_back(SDL_CreateTextureFromSurface(Game::renderer, SDL_LoadBMP(path)));
}

SDL_Texture* Texture::get_texture(uint32_t pos)
{

	return m_textures->at(pos);
}