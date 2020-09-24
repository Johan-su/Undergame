#pragma once
#include <memory>
#include <vector>
#include <SDL.h>

class Texture
{
public:

	static void init();

	static SDL_Texture* get_texture(uint32_t pos);

private:
	static void load_texture(const char* path);

	static std::vector<SDL_Texture*>* m_textures;


};