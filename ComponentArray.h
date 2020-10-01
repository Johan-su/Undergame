#pragma once
#include <iostream>
#include "ECS.h"




class ComponentArrayV
{
public:
	virtual void destroy_entity(const Entity& e) = 0;
};




template<typename T>
class ComponentArray : public ComponentArrayV
{
public:
	ComponentArray()
		: m_size(0)
	{
	}
	void add_component(const Entity& e, T component)
	{
		m_componentArray[m_size] = component;
		index[e] = m_size;
		++m_size;
	}
	void destroy_component(const Entity& e)
	{
		if (index[e] == m_size-1) // if at the end of array just remove it, it will still be a packed array.
		{
			--m_size;
			return;
		}
		index[m_size - 1] = e; // replace last index to point to, replace the last element with the newly destroyed one.
		//index[e] = m_size - 1;
		m_componentArray[index[e]] = m_componentArray[m_size-1]; // moves component from last element, to newly destroyed.
		--m_size;
	}
	void destroy_entity(const Entity& e) override
	{
		if (index[e] < m_size)
		{
			destroy_component(e);
		}
	}
	T& get_component(const Entity& e)
	{
		return m_componentArray[index[e]]; 
	}

	uint32_t get_size() const
	{
		return m_size;
	}

private:
	std::array<T, MAX_ENTITIES> m_componentArray;
	std::array<uint32_t, MAX_ENTITIES> index;
	uint32_t m_size;
};