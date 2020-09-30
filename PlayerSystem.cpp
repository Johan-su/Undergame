#include "Game.h"
#include "ECS.h"
#include <cmath>
#include "PlayerSystem.h"

void PlayerSystem::update()
{
	for (const auto& e : m_entities)
	{
		//auto& playc = Game::coordinator->get_component<PlayerComponent>(e);
		auto& inputc = Game::coordinator->get_component<InputComponent>(e);
		auto& size = Game::coordinator->get_component<SizeComponent>(e);
		auto& movec = Game::coordinator->get_component<MovementComponent>(e);
		auto& pc = Game::coordinator->get_component<PositionComponent>(e);

		//movec.rotation = atan2f(pc.pos.x - pc.pos.y, inputc.x - inputc.y);
		movec.rotation = 1.57079632679 + atanf(static_cast<float>(pc.pos.y + size.size.y - inputc.y) / static_cast<float>(pc.pos.x + size.size.x - inputc.x)); // 1.57079632679 == pi / 2
		if (inputc.x - pc.pos.x < 0)
		{
			movec.rotation -= 3.14159265359; // pi
		} //TODO:fix player targeting mouse


		std::cout << movec.rotation << std::endl;
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