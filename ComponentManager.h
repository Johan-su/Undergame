#pragma once
#include <string>
#include <array>
#include <memory>
#include <unordered_map>
#include "ECS.h"
class ComponentManager
{
public:
	ComponentManager()
	: m_componentTypeCount(0), m_arrayPointers({})
	{
	}
	template<typename T>
	void register_component_type()
	{
		if (m_componentTypeCount >= 64)
		{
			throw "too many component types";
			return;
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
	void add_component(const Entity& e, T component)
	{
		std::string componentName = typeid(T).name();
		get_component_array<T>()->add_component(e, component);

	}
	template<typename T>
	void destroy_component(const Entity& e)
	{
		get_component_array<T>()->destroy_component(e);
	}
	void remove_entity(const Entity& e)
	{
		for (auto const& arr : m_arrayPointers)
		{
			arr->destroy_component(e);
		}
	}
	template<typename T>
	ComponentArray<T>* get_component_array()
	{
		std::string componentName = typeid(T).name();
		if (m_typeToArray.find(componentName) != m_typeToArray.end())
		{
			return static_cast<ComponentArray<T>*>(m_arrayPointers[m_typeToArray[componentName]]);
			//return m_arrayPointers[m_typeToArray[componentName]];
		}
		throw "failed to find array";
	}

	template<typename T>
	uint8_t get_component_pos()
	{
		std::string componentName = typeid(T).name();
		return m_typeToArray[componentName];
	}

	template<typename T>
	T& get_component(const Entity& e)
	{
		return get_component_array<T>()->get_component(e);
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

	std::array<ComponentArrayV*, MAX_COMPONENTS> m_arrayPointers;
};