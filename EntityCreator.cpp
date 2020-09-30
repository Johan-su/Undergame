#include <functional>
#include "SDL.h"
#include "Texture.h"
#include "ECS.h"
#include "Game.h"
#include "EntityCreator.h"


std::vector<std::function<void(const Entity& ,const float&, const float&, unsigned long long)>> EntityCreator::func_pointers;



void EntityCreator::init()
{
	func_pointers.push_back([](const Entity& e, const float& x, const float& y, unsigned long long data) // Playercontrolled
		{
			auto positionc = PositionComponent();
			auto cc = ColliderComponent();

			auto sc = SizeComponent();
			auto rc = RenderComponent();

			auto pc = PlayerComponent();
			auto ic = InputComponent();

			auto hc = HealthComponent();
			auto mc = MovementComponent();

			positionc.pos.x = x;
			positionc.pos.y = y;

			sc.size.x = 24;
			sc.size.y = 24; 

			rc.src_rect = {0, 0, 92, 136}; // TODO: determine texture

			rc.texture = Texture::get_texture(2); // TODO: determine texture

			pc.id = create_player_id();

			mc.speed = 2.0f;

			Game::coordinator->add_component<PositionComponent>(e, positionc);
			Game::coordinator->add_component<ColliderComponent>(e, cc);

			Game::coordinator->add_component<SizeComponent>(e, sc);
			Game::coordinator->add_component<RenderComponent>(e, rc);

			Game::coordinator->add_component<PlayerComponent>(e, pc);
			Game::coordinator->add_component<InputComponent>(e, ic);

			Game::coordinator->add_component<HealthComponent>(e, hc);
			Game::coordinator->add_component<MovementComponent>(e, mc);

		});
	func_pointers.push_back([](const Entity& e, const float& x, const float& y, unsigned long long data) // NPC 
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
	func_pointers.push_back([](const Entity& e, const float& x, const float& y, unsigned long long data) // tile
		{
			auto positionc = PositionComponent();
			auto tc = TileComponent();
			auto sc = SizeComponent();
			auto hc = HealthComponent();
			auto cc = ColliderComponent();

			positionc.pos.x = x;
			positionc.pos.y = y;

			tc.type = static_cast<char>(data);

			sc.size.x = TILE_SIZE;
			sc.size.y = TILE_SIZE;


			hc.max_health = 100.0f;
			hc.health = hc.max_health;


			Game::coordinator->add_component<PositionComponent>(e, positionc);
			Game::coordinator->add_component<TileComponent>(e, tc);
			Game::coordinator->add_component<SizeComponent>(e, sc);
			Game::coordinator->add_component<HealthComponent>(e, hc);
			Game::coordinator->add_component<ColliderComponent>(e, cc);


		});
	func_pointers.push_back([](const Entity& e, const float& x, const float& y, unsigned long long data) // mole
		{
			auto positionc = PositionComponent();
			auto cc = ColliderComponent();

			auto sc = SizeComponent();
			auto rc = RenderComponent();

			auto hc = HealthComponent();
			auto mc = MovementComponent();

			positionc.pos.x = x;
			positionc.pos.y = y;

			sc.size.x = 0;
			sc.size.y = 0;

			rc.src_rect = { 0, 0, 0, 0 }; // TODO: determine texture

			rc.texture = nullptr; // TODO: determine texture

			mc.speed = 2.0f;

			Game::coordinator->add_component<PositionComponent>(e, positionc);
			Game::coordinator->add_component<ColliderComponent>(e, cc);

			Game::coordinator->add_component<SizeComponent>(e, sc);
			Game::coordinator->add_component<RenderComponent>(e, rc);

			Game::coordinator->add_component<HealthComponent>(e, hc);
			Game::coordinator->add_component<MovementComponent>(e, mc);
		});
}

Entity EntityCreator::create_entity(const size_t& type, const float& x, const float& y, unsigned long long data)
{
	SDL_assert(Game::coordinator != nullptr);
	Entity e = Game::coordinator->create_entity();


	const auto& func = func_pointers[type];
	func(e, x, y, data);







	return e;
}

unsigned int EntityCreator::create_player_id()
{
	static uint8_t id = -1;
	return ++id;
}