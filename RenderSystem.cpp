#include "RenderSystem.h"
#include "ECS.h"

void RenderSystem::render()
{
	for (const auto& e : m_entities)
	{
		auto render = g_coordinator->get_component<RenderComponent>(e);
	}
}


