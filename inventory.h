#pragma once
#include "gameNode.h"
#include <vector>
#include "object.h"

#define INVENTORYSIZE 36
#define QUICKSLOTSIZE 12




struct ItemInfo
{
	image* itemImg;
	string itemName;
	string type;

	//�޴� ĭ���� ���� ĭ��
	RECT	rc;
};

class inventory : public gameNode
{
private:
	vector <object*>			_vItems;
	vector <object*>::iterator  _viItems;


	ItemInfo _items[INVENTORYSIZE];

	//���� �����ִ� �޴� �̹���
	image* _currentMenuImg;

	//������
	image* _quickSlot;

	//������â
	RECT	_quickSlotRc;

	//���� �޴�â
	RECT	_menuRc;

	//�޴� �̹�����
	image* _invenImg;
	image* _statImg;
	image* _craftImg;
	image* _settingImg;
	image* _exitImg;

	//�޴��ٲٴ� ��ư��?
	RECT	_storageRc;
	RECT	_statRc;
	RECT	_craftRc;
	RECT	_settingRc;
	RECT	_exitRc;



	//âȰ��ȭ�� 

	BOOL	_isMenuOpen;				//�޴�â
	BOOL	_isInvenOpen;				//�κ�â
	BOOL	_isStatOpen;				//����â
	BOOL	_isCraftOpen;				//����â
	BOOL	_isSettingOpen;				//����â
	BOOL	_isExitOpen;				//Ż��â







public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	void MenuOpen();
	void InvetoryOpen();
	void StatOpen();
	void CraftOpen();
	void SettingOpen();
	void ExitOpen();
	void SelectMenu();




	void ClickObject();
	void DragObject();
	void DragObjectToSwap();
};

