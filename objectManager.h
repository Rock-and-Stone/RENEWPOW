#pragma once
#include "gameNode.h"
class objectManager : public gameNode
{
private:

public:
	objectManager();
	~objectManager();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

