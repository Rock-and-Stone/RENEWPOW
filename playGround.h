#pragma once
#include "gameNode.h"
#include "loadingScene.h"
#include "playerScene.h"


class playGround : public gameNode
{
private:
	
	   	

public:
	playGround();
	~playGround();

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();			//�׸��� �Լ�

	
	
};
