#pragma once
#include "Entity.h"
#include "Component.h"
#include <memory>



inline std::size_t getID()
{
	static std::size_t id = 0u;
	return ++id;
}