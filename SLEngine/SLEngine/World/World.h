#pragma once

#include "Node.h"

NS_SL_BEGIN

class World : public Node
{
public:
	static World* Create();

	World();
	virtual ~World();

	virtual bool init();
	virtual void onEnter();
	virtual void onExit();
	virtual void onUpdate();
};

NS_SL_END
