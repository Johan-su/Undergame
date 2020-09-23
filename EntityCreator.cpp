#include <functional>
#include "ECS.h"
#include "Game.h"
#include "EntityCreator.h"


std::vector<std::function<void(const float&, const float&, const Entity&)>> EntityCreator::func_pointers;



void EntityCreator::init()
{
	func_pointers.push_back([](const float& x, const float& y, const Entity& e) // Playercontrolled
		{
			auto positionc = PositionComponent();
			auto sc = SizeComponent();
			auto rc = RenderComponent();
			auto pc = PlayerComponent();
			auto ic = InputComponent();
			auto hc = HealthComponent();

			positionc.pos.x = x;
			positionc.pos.y = y;

			sc.size.x = 50;
			sc.size.y = 50; 

			rc.src_rect = {0, 0, 0, 0}; //TODO: determine texture

			rc.texture = nullptr; //TODO: determine texture

			pc.id = create_player_id();

			Game::coordinator->add_component<PositionComponent>(e, positionc);
			Game::coordinator->add_component<SizeComponent>(e, sc);
			Game::coordinator->add_component<RenderComponent>(e, rc);
			Game::coordinator->add_component<PlayerComponent>(e, pc);
			Game::coordinator->add_component<InputComponent>(e, ic);
			Game::coordinator->add_component<HealthComponent>(e, hc);

		});
	func_pointers.push_back([](const float& x, const float& y, const Entity& e) // NPC
		{
			auto positionc = PositionComponent();
			auto sc = SizeComponent();
			auto rc = RenderComponent();
			auto pc = PlayerComponent();
			auto hc = HealthComponent();

			positionc.pos.x = x;
			positionc.pos.y = y;

			sc.size.x = 50;
			sc.size.y = 50;

			rc.src_rect = { 0, 0, 0, 0 }; //TODO: determine texture

			rc.texture = nullptr; //TODO: determine texture

			pc.id = create_player_id();

			Game::coordinator->add_component<PositionComponent>(e, positionc);
			Game::coordinator->add_component<SizeComponent>(e, sc);
			Game::coordinator->add_component<RenderComponent>(e, rc);
			Game::coordinator->add_component<PlayerComponent>(e, pc);
			Game::coordinator->add_component<HealthComponent>(e, hc);

		});
	func_pointers.push_back([](const float& x, const float& y, const Entity& e) // tile
		{
			auto positionc = PositionComponent();
			auto tc = TileComponent();
			auto sc = SizeComponent();
			auto rc = RenderComponent();
			auto hc = HealthComponent();



			Game::coordinator->add_component<PositionComponent>(e, positionc);
			Game::coordinator->add_component<TileComponent>(e, tc);
			Game::coordinator->add_component<SizeComponent>(e, sc);
			Game::coordinator->add_component<RenderComponent>(e, rc);
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
}

Entity EntityCreator::create_entity(const float& x, const float& y, const size_t& type) //TODO: add a way to add extra args, maybe with variadic arguments or something else.
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