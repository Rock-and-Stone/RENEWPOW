#pragma once
#include "gameNode.h"
//#include "CameraManager.h"

//����
enum TOOL
{
	AXE,			//����
	PICKAXE,		//���
	HOE,			//ȣ��
	CAN,			//��������	
	ROD				//���ô�
};

//����
enum WEAPON
{
	SWORD,			//��
	SLINGSHOT		//����

};

//������
enum FISH
{
	PUFFERFISH,		//Ȳ�ݖþ�
	TUNA,			//����
	HALIBUT			//�ξ�
};
//����
enum SEED
{
	CAULIFLOWERSEED,
	PARSNIPSEED,
	POTATOSEED,
	KALESEED
};

//�۹�
enum CROP			//���İ�
{
	CAULIFLOWER,	//�ݸ��ö��	350G	195Hp	87Sp	
	PARSNIP,		//�Ľ���		220G	65Hp	29Sp
	POTATO,			//����		150G	65Hp	29Sp
	KALE			//����		220G	130Hp	58Sp
};

//����
enum ORE
{
	COPPER,			//����		 5G
	IRON,			//ö			10G
	GOLD,			//���		25G
};


class object : public gameNode
{
protected:
	//enum��  ����;
	TOOL		_tool;
	WEAPON		_weapon;
	FISH		_fish;
	SEED		_seed;
	CROP		_crop;
	ORE			_ore;


	image* _objectImg;				//������Ʈ �̹���

	//�浹�� ��Ʈ
	RECT _objectRc;					//��ü�� �浹��Ʈ

	//��ġ��
	float _posX, _posY;				//������Ʈ ������ġ��
	float _rendX, _rendY;			//ī�޶�X,Y
	
	//���� ����
	int _direction;					//����

	int _price;						//������ ����

	int _hP;						//ü���� ä���ش�.
	int _sP;						//���¹̳��� ä���ش�.

	

public:
	object();
	~object();

	virtual HRESULT init();
	virtual HRESULT init(const char* imageName , POINT postition);
	virtual void release();
	virtual void update();
	virtual void render();

	void Draw();



	//======================= ������ & ������ ======================= //

	//ENUM��
	TOOL GetToolType() { return _tool; }
	void SetToolType(TOOL tool) { _tool = tool; }

	WEAPON GetWeaponType() { return _weapon; }
	void SetWeaponType(WEAPON weapon) { _weapon = weapon; }

	FISH GetFishType() { return _fish; }
	void SetFishType(FISH fish) { _fish = fish; }

	SEED GetSeedType() { return _seed; }
	void SetSeedType(SEED seed) { _seed = seed; }

	CROP GetCropType() { return _crop; }
	void SetCropType(CROP crop) { _crop = crop; }

	ORE GetOreType() { return _ore; }
	void SetOreType(ORE ore) { _ore = ore; }
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

	//======================= ========== ======================= //
};

