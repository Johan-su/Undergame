#include <functional>
#include "ECS.h"
#include "Game.h"
#include "EntityCreator.h"


std::vector<std::function<void(const float&, const float&, const Entity&)>> EntityCreator::func_pointers;



void EntityCreator::init()
{
	func_pointers.push_back([](const float& x, const float& y, const Entity& e) // Player
		{
			auto tc = TransformComponent();
			auto rc = RenderComponent();
			auto pc = PlayerComponent();
			auto hc = HealthComponent();

			tc.position.x = x;
			tc.position.y = y;

			tc.size.x = 50;
			tc.size.y = 50;

			rc.src_rect = {0, 0, 0, 0};

			rc.texture = nullptr;

			pc.id = create_player_id();

			Game::coordinator->add_component<TransformComponent>(e, tc);
			Game::coordinator->add_component<RenderComponent>(e, rc);
			Game::coordinator->add_component<PlayerComponent>(e, pc);
			Game::coordinator->add_component<HealthComponent>(e, hc);

		});
	func_pointers.push_back([](const float& x, const float& y, const Entity& e)
		{

		});
	func_pointers.push_back([](const float& x, const float& y, const Entity& e)
		{

		});
	func_pointers.push_back([](const float& x, const float& y, const Entity& e)
		{

		});
	func_pointers.push_back([](const float& x, const float& y, const Entity& e)
		{

		});
	func_pointers.push_back([](const float& x, const float& y, const Entity& e)
		{

		});
}

Entity EntityCreator::create_entity(const float& x, const float& y, const size_t& type)
{
	if (Game::coordinator == nullptr)
	{
		throw "nullptr in entitycreator";
	}
	Entity e = Game::coordinator->create_entity();


	const auto& func = func_pointers[type];
	func(x, y, e);







	return e;
}

unsigned int EntityCreator::create_player_id()
{
	static uint8_t id = -1;
	return ++id;
}