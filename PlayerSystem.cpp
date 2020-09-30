#include "Game.h"
#include "ECS.h"
#include "PlayerSystem.h"

void PlayerSystem::update()
{
	for (const auto& e : m_entities)
	{
		//auto& playc = Game::coordinator->get_component<PlayerComponent>(e);
		auto& inputc = Game::coordinator->get_component<InputComponent>(e);
		auto& movec = Game::coordinator->get_component<MovementComponent>(e);
		auto& pc = Game::coordinator->get_component<PositionComponent>(e);

		set_Camera_to_player(pc);

		movec.velocity.x = 0;
		movec.velocity.y = 0;


		if (inputc.buttonStates[0]) // w
		{
			movec.velocity.y = -1;
		}
		if (inputc.buttonStates[1]) // a
		{
			movec.velocity.x = -1;
		}
		if (inputc.buttonStates[2]) // s
		{
			movec.velocity.y = 1;
		}
		if (inputc.buttonStates[3]) // d
		{
			movec.velocity.x = 1;
		}
	}
}
void PlayerSystem::set_Camera_to_player(const PositionComponent& pc)
{
	Game::offsetx = pc.pos.x - SCREEN_WIDTH / 2;
	Game::offsety = pc.pos.y - SCREEN_HEIGHT / 2;
}