#pragma once
#include <string>
#include <array>
#include <unordered_map>
#include "ECS.h"
class ComponentManager
{
public:
	ComponentManager()
	: m_componentTypeCount(0)
	{
	}
	template<typename T>
	void register_component_type()
	{
		if (m_componentTypeCount >= 64)
		{
			throw "too many component types";
		}
		std::string componentName = typeid(T).name();
		for (int i = 0; i < m_componentTypeCount; ++i)
		{
			if (m_typeToArray.find(componentName) != m_typeToArray.end())
			{
				throw "component already exists";
			}
		}
		m_typeToArray[componentName] = m_componentTypeCount;
		m_arrayPointers[m_componentTypeCount] = new ComponentArray<T>();
		++m_componentTypeCount;
	}
	template<typename T>
	void add_component(const Entity& e)
	{
		std::string componentName = typeid(T).name();

		if (m_typeToArray.find(componentName) != m_typeToArray.end())
		{

		}

	}

	template<typename T>
	ComponentArray<T>* get_component_array()
	{
		std::string componentName = typeid(T).name();
		if (m_typeToArray.find(componentName) != m_typeToArray.end())
		{
			return m_arrayPointers[m_typeToArray[componentName]];
		}
		std::cout << "failed to find array" << std::endl;
		return nullptr;
	}




	void clean()
	{
		for (int i = 0; i < m_componentTypeCount; ++i)
		{
			delete m_arrayPointers[i];
		}
	}
private:
	//std::array<std::string, MAX_COMPONENTS> m_componentTypes;

	std::unordered_map<std::string, uint8_t> m_typeToArray;
	uint8_t m_componentTypeCount;

	std::array<void*, MAX_COMPONENTS> m_arrayPointers;
};