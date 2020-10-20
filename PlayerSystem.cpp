#include "DebugMacros.h"
#include "Game.h"
#include "ECS.h"
#include <cmath>
#include "PlayerSystem.h"

void PlayerSystem::update()
{
#ifdef _DEBUG
	static int count = 0;
#endif
	for (auto e : m_entities)
	{

		auto& playc = Game::coordinator->get_component<PlayerComponent>(e);
		auto& inputc = Game::coordinator->get_component<InputComponent>(e);
		auto& size = Game::coordinator->get_component<SizeComponent>(e);
		auto& movec = Game::coordinator->get_component<MovementComponent>(e);
		auto& pc = Game::coordinator->get_component<PositionComponent>(e);
		auto& shoot = Game::coordinator->get_component<ShooterComponent>(e);

#ifdef ECS_DEBUG
		SDL_assert(playc.entity == e);
		SDL_assert(inputc.entity == e);
		SDL_assert(size.entity == e);
		SDL_assert(movec.entity == e);
		SDL_assert(pc.entity == e);
		SDL_assert(shoot.entity == e);
#endif

		//movec.rotation = atan2f(pc.pos.x - pc.pos.y, inputc.x - inputc.y);
		movec.rotation = static_cast<float>(atanf(static_cast<float>(pc.pos.y + size.size.y - static_cast<float>(inputc.y)) / static_cast<float>(pc.pos.x + size.size.x - static_cast<float>(inputc.x)))); // 1.57079632679 == pi / 2
		if (inputc.x - pc.pos.x < 0)
		{
			movec.rotation -= 3.14159265359f; // pi
		} //TODO:fix player targeting mouse


		//std::cout << movec.rotation << std::endl;
		set_Camera_to_player(pc);

		movec.velocity.x = 0;
		movec.velocity.y = 0;

#ifdef _DEBUG
		if (count == 60)
		{
			std::cout << pc.pos.x << " px py" << pc.pos.y << std::endl;
			count = 0;
		}
#endif
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
		if (inputc.buttonStates[4] && playc.bullets > 0) // mouse left
		{
			shoot.states[0] = true;
		}
		else
		{
			shoot.states[0] = false;
		}
		if (inputc.buttonStates[5]) // mouse middle
		{

		}
		if (inputc.buttonStates[6]) // mouse right
		{
				
		}
		else
		{

		}
	}
#ifdef _DEBUG
	++count;
#endif
}
void PlayerSystem::set_Camera_to_player(const PositionComponent& pc)
{
	Game::offsetx = static_cast<int>(pc.pos.x - static_cast<float>(SCREEN_WIDTH) / 2);
	Game::offsety = static_cast<int>(pc.pos.y - static_cast<float>(SCREEN_HEIGHT) / 2);
}