#include <functional>
#include "DebugMacros.h"
#include "SDL.h"
#include "Texture.h"
#include "ECS.h"
#include "Game.h"
#include "EntityCreator.h"


std::vector<std::function<void(const Entity& ,const float&, const float&, void* data)>> EntityCreator::func_pointers;



void EntityCreator::init()
{
	func_pointers.push_back([](const Entity& e, const float& x, const float& y, void* data) // Playercontrolled
		{
			auto positionc = PositionComponent();
			auto cc = ColliderComponent();

			auto sc = SizeComponent();
			auto rc = RenderComponent();

			auto pc = PlayerComponent();
			auto ic = InputComponent();

			auto hc = HealthComponent();
			auto mc = MovementComponent();

			auto shc = ShooterComponent();
			auto dc = DiggerComponent();

#ifdef ECS_DEBUG
			positionc.entity = e;
			cc.entity = e;

			sc.entity = e;
			rc.entity = e;

			pc.entity = e;
			ic.entity = e;

			hc.entity = e;
			mc.entity = e;

			shc.entity = e;
			dc.entity = e;
#endif

			positionc.pos.x = x;
			positionc.pos.y = y;

			cc.id = 0xFFFFFFFF;
			cc.other_entity = 0xFFFFFFFF;

			sc.size.x = 24;
			sc.size.y = 24; 

			rc.src_rect = {0, 0, 92, 136}; // TODO: determine texture

			rc.texture = Texture::get_texture(2); // TODO: determine texture

			//pc.id = create_player_id();
			pc.bombs = 0;
			pc.bullets = 0;
			pc.bulletWeaponsType = 0;
			pc.explosiveWeaponsType = 0;

			hc.max_health = 100.0f;
			hc.health = hc.max_health;

			mc.speed = 10.0f;

			shc.gunlength = 34;
			dc.drillLVL = 0;
			dc.drillStates = 0;

			Game::coordinator->add_component<PositionComponent>(e, positionc);
			Game::coordinator->add_component<ColliderComponent>(e, cc);

			Game::coordinator->add_component<SizeComponent>(e, sc);
			Game::coordinator->add_component<RenderComponent>(e, rc);

			Game::coordinator->add_component<PlayerComponent>(e, pc);
			Game::coordinator->add_component<InputComponent>(e, ic);

			Game::coordinator->add_component<HealthComponent>(e, hc);
			Game::coordinator->add_component<MovementComponent>(e, mc);

			Game::coordinator->add_component<ShooterComponent>(e, shc);


		});
	func_pointers.push_back([](const Entity& e, const float& x, const float& y, void* data) // NPC 
		{
			auto positionc = PositionComponent();
			auto sc = SizeComponent();
			auto rc = RenderComponent();
			auto hc = HealthComponent();
#ifdef ECS_DEBUG
			positionc.entity = e;
			sc.entity = e;

			rc.entity = e;
			hc.entity = e;
#endif
			positionc.pos.x = x;
			positionc.pos.y = y;

			sc.size.x = 50;
			sc.size.y = 50;

			rc.src_rect = { 0, 0, 0, 0 }; //TODO: determine texture

			rc.texture = nullptr; //TODO: determine texture

			//pc.id = create_player_id();

			Game::coordinator->add_component<PositionComponent>(e, positionc);
			Game::coordinator->add_component<SizeComponent>(e, sc);
			Game::coordinator->add_component<RenderComponent>(e, rc);
			Game::coordinator->add_component<HealthComponent>(e, hc);

		});
	func_pointers.push_back([](const Entity& e, const float& x, const float& y, void* data) // tile
		{
			auto positionc = PositionComponent();
			auto tc = TileComponent();
			auto sc = SizeComponent();
			auto hc = HealthComponent();

#ifdef ECS_DEBUG
			positionc.entity = e;
			tc.entity = e;

			sc.entity = e;
			hc.entity = e;
#endif

			positionc.pos.x = x;
			positionc.pos.y = y;

			tc.type = *static_cast<uint8_t*>(data);

			switch (tc.type) // setting tilehealth
			{
			case 1:

			default:
				break;
			}

			sc.size.x = TILE_SIZE;
			sc.size.y = TILE_SIZE;


			hc.max_health = 100.0f;
			hc.health = hc.max_health;


			Game::coordinator->add_component<PositionComponent>(e, positionc);
			Game::coordinator->add_component<TileComponent>(e, tc);
			Game::coordinator->add_component<SizeComponent>(e, sc);
			Game::coordinator->add_component<HealthComponent>(e, hc);

		});
	func_pointers.push_back([](const Entity& e, const float& x, const float& y, void* data) // mole
		{
			auto positionc = PositionComponent();
			auto cc = ColliderComponent();

			auto sc = SizeComponent();
			auto rc = RenderComponent();

			auto hc = HealthComponent();
			auto mc = MovementComponent();

			auto ai = AiComponent();

#ifdef ECS_DEBUG
			positionc.entity = e;
			cc.entity = e;

			sc.entity = e;
			rc.entity = e;

			hc.entity = e;
			mc.entity = e;

			ai.entity = e;
#endif

			positionc.pos.x = x;
			positionc.pos.y = y;

			cc.id = 0xFFFFFFFF;
			cc.other_entity = 0xFFFFFFFF;

			sc.size.x = 0;
			sc.size.y = 0;

			rc.src_rect = { 0, 0, 0, 0 }; // TODO: determine texture

			rc.texture = nullptr; // TODO: determine texture

			mc.speed = 0.0f;

			Game::coordinator->add_component<PositionComponent>(e, positionc);
			Game::coordinator->add_component<ColliderComponent>(e, cc);

			Game::coordinator->add_component<SizeComponent>(e, sc);
			Game::coordinator->add_component<RenderComponent>(e, rc);

			Game::coordinator->add_component<HealthComponent>(e, hc);
			Game::coordinator->add_component<MovementComponent>(e, mc);
		});
	func_pointers.push_back([](const Entity& e, const float& x, const float& y, void* data) // bullet
		{
			auto positionc = PositionComponent();
			auto cc = ColliderComponent();

			auto sc = SizeComponent();
			auto rc = RenderComponent();

			auto mc = MovementComponent();
			auto pc = ProjectileComponent();

			auto health = HealthComponent();

#ifdef ECS_DEBUG
			positionc.entity = e;
			cc.entity = e;

			sc.entity = e;
			rc.entity = e;

			mc.entity = e;
			pc.entity = e;

			health.entity = e;
#endif

			positionc.pos.x = x;
			positionc.pos.y = y;

			cc.id = 0xFFFFFFFF;
			cc.other_entity = 0xFFFFFFFF;

			sc.size.x = 4;
			sc.size.y = 4;

			rc.src_rect = { 0, 0, 677, 320 }; // TODO: determine texture

			rc.texture = Texture::get_texture(1); // TODO: determine texture

			mc.speed = 1.0f;
			//mc.rotation = 4.0f;

			mc.rotation = *static_cast<float*>(data);

			mc.velocity.x = cosf(mc.rotation);
			mc.velocity.y = sinf(mc.rotation);

			pc.damage = 0.0f;

			health.max_health = 1.0f;

			health.health = health.max_health;

			Game::coordinator->add_component<PositionComponent>(e, positionc);
			Game::coordinator->add_component<ColliderComponent>(e, cc);

			Game::coordinator->add_component<SizeComponent>(e, sc);
			Game::coordinator->add_component<RenderComponent>(e, rc);

			Game::coordinator->add_component<MovementComponent>(e, mc);
			Game::coordinator->add_component<ProjectileComponent>(e, pc);

			Game::coordinator->add_component<HealthComponent>(e, health);

		});
}

void EntityCreator::create_entity(const size_t& type, const float& x, const float& y, void* data)
{
	SDL_assert(Game::coordinator != nullptr);
	Entity e = Game::coordinator->create_entity();


	const auto& func = func_pointers[type];
	func(e, x, y, data);
}

unsigned int EntityCreator::create_player_id()
{
	static uint8_t id = -1;
	return ++id;
}