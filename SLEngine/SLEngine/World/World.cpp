
#include "stdafx.h"
#include "World.h"
#include "Utility/Time.h"

NS_SL_BEGIN

World* World::Create()
{
	World* pWorld = new World();
	if (pWorld != nullptr && pWorld->init())
	{
		pWorld->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(pWorld);
	}

	return pWorld;
}

World::World()
{
}

World::~World()
{
}

bool World::init()
{
	return true;
}

void World::onEnter()
{
}

void World::onExit()
{
}

void World::onUpdate()
{
	float fDelta = Time::GetInstance()->getDelta();
	std::cout << "fDelta: " << fDelta << std::endl;
}

NS_SL_END
