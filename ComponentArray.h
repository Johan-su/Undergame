#pragma once
#include <iostream>
#include "ECS.h"
#define MAX_COMPONENTS 64u
#define MAX_ENTITIES 500000u
template<typename T>
class ComponentArray
{
public:
	ComponentArray()
		: m_size(0)
	{
		std::cout << MAX_ENTITIES << std::endl;
	}
	void add_component(const Entity& e, T component)
	{
		m_componentArray[m_size] = component;
		index[e.id] = m_size;
		++m_size;
	}
	void destroy_component(const Entity& e)
	{
		if (index[e.id] == m_size)
		{
			--m_size;
			return;
		}
		m_componentArray[index[e.id]] = m_componentArray[m_size-1];


		--m_size;
	}
	T& get_component(const Entity& e)
	{
		return m_componentArray[index[e.id]];
	}

	size_t get_size() const
	{
		return m_size;
	}

private:
	std::array<T, MAX_ENTITIES> m_componentArray;
	std::array<uint32_t, MAX_ENTITIES> index;
	size_t m_size;
};