#pragma once

#define MAX_COMPONENTS 64u
#define MAX_ENTITIES 500000u
#define MAX_SYSTEMS 256u

#include "Entity.h"

#include "EntityManager.h"

#include "ComponentArray.h"

#include "ComponentManager.h"

#include "System.h"

#include "SystemManager.h"

#include "Coordinator.h"

#include "Scene.h"

//extern std::unique_ptr<Coordinator> g_coordinator; // todo fix global link

static Coordinator* g_coordinator;




#include "RenderSystem.h"

#include "TransformComponent.h"
#include "RenderComponent.h"
#include "PlayerComponent.h"
#include "HealthComponent.h"


