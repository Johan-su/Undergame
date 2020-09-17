#include "RenderSystem.h"
#include "ECS.h"

void RenderSystem::render()
{
	for (const auto& e : m_entities)
	{
		std::cout << "entity in rendersystem " << e << std::endl;
		auto render = g_coordinator->get_component<RenderComponent>(e);
	}
}


