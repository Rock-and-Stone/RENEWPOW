#pragma once
#include "gameNode.h"
//#include "CameraManager.h"


//��ü������ 
enum ALLITEMS 
{
//���� TOOLS
	AXE,			//����
	PICKAXE,		//���
	HOE,			//ȣ��
	CAN,			//��������	
	ROD	,			//���ô�

//���� WEAPON

	SWORD,			//��
	SLINGSHOT,		//����

//������ FISH

	PUFFERFISH,		//Ȳ�ݖþ�
	TUNA,			//����
	HALIBUT,		//�ξ�

//���� SEED

	CAULIFLOWERSEED,
	PARSNIPSEED,
	POTATOSEED,
	KALESEED,

//�۹� CROPS

	CAULIFLOWER,	//�ݸ��ö��	350G	195Hp	87Sp	
	PARSNIP,		//�Ľ���		220G	65Hp	29Sp
	POTATO,			//����		150G	65Hp	29Sp
	KALE,			//����		220G	130Hp	58Sp

//���� ORE
	COPPER,			//����		 5G
	IRON,			//ö			10G
	GOLD			//���		25G
};

enum ITEMTYPE
{
	TOOL,			//����
	WEAPON,			//����
	FISH,			//�����
	SEED,			//����
	CROPS,			//�۹�	= ����
	ORE				//����
};



class object : public gameNode
{
protected:
	//����ü�� �������
	ALLITEMS    _items;						//������
	ITEMTYPE    _itemType;					//������ ����

	image*		_objectImg;					//������Ʈ �̹���

	//�浹�� ��Ʈ
	RECT		_objectRc;					//��ü�� �浹��Ʈ

	//��ġ��
	float		_posX, _posY;				//������Ʈ ������ġ��
	float		_rendX, _rendY;				//ī�޶�X,Y
	

	int			_frameX, _frameY;			//�������̹��� ��ġ


	//���� ����
	int			_direction;					//����
	

	
	int			_price;						//������ ����

	int			_hP;						//ü���� ä���ش�.
	int			_sP;						//���¹̳��� ä���ش�.

	

public:
	object();
	~object();

	virtual HRESULT init();

	virtual HRESULT init(const char* imageName , POINT position, ALLITEMS items, ITEMTYPE itemTypes , int frameX, int frameY);
	//virtual HRESULT init(const char* imageName , POINT postition);

	virtual void release();
	virtual void update();
	virtual void render();

	void Draw();



	//======================= ������ & ������ ======================= //

	//ENUM��
	ALLITEMS GetItems() { return _items; }
	void SetItems(ALLITEMS items) { _items = items; }

	ITEMTYPE GetItemType() { return _itemType; }
	void SetItemType(ITEMTYPE itemtype) { _itemType = itemtype; }
	//=====//
	
	//��Ÿ ������
	inline RECT GetRect() { return _objectRc; }
	
	//�̹��� ��
	image* GetObjectImage() { return _objectImg; }
	void SetObjectImage(image* objImg) { objImg = _objectImg; }
	
	float GetObjectPosX() { return _posX; }
	void SetObjectPosX(float posX) { _posX = posX; }

	float GetObjectPosY() { return _posY; }
	void SetObjectPosY(float posY) { _posY = posY; }

	int GetObjectDirection() { return _direction; }
	void SetObjectDirection(int dir) { _direction = dir; }

	int GetObjectPrice() { return _price; }
	void SetObjectPrice(int price) { _price = price; }

	int GetObjectHp() { return _hP; }
	void SetObjectHp(int hp) { _hP = hp; }

	int GetObjectSp() { return _sP; }
	void SetObjectSp(int sp) { _sP = sp; }
	//======================= ============== ======================= //
	
	//=======================   �޸� ��ũ   ======================= //
	// 
	//======================= ============== ======================= //
};

