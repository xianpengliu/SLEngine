#pragma once

#include "stdafx.h"
#include "Common/Ref.h"
#include "Utility/Vector.h"

NS_SL_BEGIN

class Node : public Ref
{
public:
	static Node* Create();

	virtual bool init();
	virtual void onEnter();
	virtual void onExit();
	virtual void onUpdate();

	void addChild(Node* pNode);
	void removeChild(Node* pNode);

	void setParent(Node* pParent);

private:
	Vector<Node*> m_cChildrenVector;								// children
	Node* m_pParent;												// reference, not retain
};

NS_SL_END
