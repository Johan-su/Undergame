#pragma once

#define MAX_COMPONENTS 64u
#define MAX_ENTITIES 3000u
#define MAX_SYSTEMS 256u
#define TILE_SIZE 64u
#define MAP_SIZE 16u

#include "Entity.h"

#include "EntityManager.h"

#include "ComponentArray.h"

#include "ComponentManager.h"

#include "System.h"

#include "SystemManager.h"

#include "Coordinator.h"


#include "AiComponent.h"
#include "ColliderComponent.h"
#include "HealthComponent.h"
#include "InputComponent.h"
#include "MovementComponent.h"
#include "PlayerComponent.h"
#include "PositionComponent.h"
#include "ProjectileComponent.h"
#include "RenderComponent.h"
#include "ShooterComponent.h"
#include "SizeComponent.h"
#include "TileComponent.h"

#include "CollisionSystem.h"
#include "HealthSystem.h"
#include "InputSystem.h"
#include "MovementSystem.h"
#include "PlayerSystem.h"
#include "ProjectileSystem.h"
#include "RenderSystem.h"
#include "ShooterSystem.h"
#include "StaticCollisionSystem.h"
#include "StaticRenderSystem.h"






