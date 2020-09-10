#pragma once
#include <set>
#include "ECS.h"
class System

{
public:
	std::set<uint32_t> m_entities;
};