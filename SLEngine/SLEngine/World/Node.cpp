
#include "stdafx.h"
#include "Node.h"

NS_SL_BEGIN

Node* Node::Create()
{
	Node* pNode = new Node();
	if (pNode != nullptr && pNode->init())
	{
		pNode->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(pNode);
	}

	return pNode;
}

bool Node::init()
{
	return true;
}

void Node::onEnter()
{
}

void Node::onExit()
{
}

void Node::onUpdate()
{
}

void Node::addChild(Node* pNode)
{
	m_cChildrenVector.pushBack(pNode);
}

void Node::removeChild(Node* pNode)
{
	if (m_cChildrenVector.empty())
	{
		return;
	}

	unsigned int nIndex = m_cChildrenVector.getIndex(pNode);
	if (nIndex != UINT_MAX)
	{
		pNode->onExit();

		pNode->setParent(nullptr);

		m_cChildrenVector.erase(nIndex);
	}
}

void Node::setParent(Node* pParent)
{
	m_pParent = pParent;
}

NS_SL_END
