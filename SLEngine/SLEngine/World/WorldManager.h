#pragma once

#include "stdafx.h"

NS_SL_BEGIN

class World;

class WorldManager
{
public:
	static WorldManager* GetInstance();

	WorldManager();
	~WorldManager();

	void replaceWorld(World* pWorldNew);
	World* getWorldCur();

private:
	World* m_pWorldCur;
};

NS_SL_END
