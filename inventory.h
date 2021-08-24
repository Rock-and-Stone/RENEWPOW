#pragma once
#include "gameNode.h"
#include <vector>


#define IVTILEX 12
#define IVTILEY 3

#define IVTILESIZE 16



class inventory : public gameNode
{
private:

	image* _quickSlot;
	image* _invenImg;

	RECT	_quickSlotRc;
	RECT	_inventoryRc;
	RECT	_rc;


	bool	_isInvenOpen;


public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void ClickObject();
	void DragObject();
	void DragObjectToSwap();
};

