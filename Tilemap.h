#pragma once
#include <cstdint>
#include <array>
struct TileMap
{
	std::array<uint8_t, 4096*4096> grid;
};