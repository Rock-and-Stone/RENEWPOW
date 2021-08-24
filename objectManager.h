#pragma once
#include "gameNode.h"
#include <vector>

#include "axe.h"
#include "pickAxe.h"
#include "hoe.h"
#include "can.h"
#include "rod.h"

#include "sword.h"
#include "slingShot.h"

#include "pufferFish.h"
#include "tuna.h"
#include "haliBut.h"

#include "cauliFlower.h"
#include "parsnip.h"
#include "potato.h"
#include "kale.h"

#include "cauliFlowerSeed.h"
#include "parsnipSeed.h"
#include "potatoSeed.h"
#include "kaleSeed.h"

#include "copper.h"
#include "iron.h"
#include "gold.h"


class objectManager : public gameNode
{
private:
	vector<object*>				_vObject;
	vector<object*>::iterator	_viObject;

private:
	//����
	axe*				_axe;
	pickAxe*			_pickAxe;
	hoe*				_hoe;
	can*			    _can;
	rod*				_rod;
	//����
	sword*				_sword;
	slingShot*			_slingShot;
	//����
	pufferFish*			_pufferFish;
	tuna*				_tuna;
	haliBut*			_halibut;
	//����
	cauliFlowerSeed*	_cauliFlowerSeed;
	parsnipSeed*		_parsnipSeed;
	potatoSeed*			_potatoSeed;
	kaleSeed*			_kaleSeed;
	//�۹�
	cauliFlower*		_cauliFlower;
	parsnip*			_parsnip;
	potato*				_potato;
	kale*				_kale;
	//����
	copper*				_copper;
	iron*				_iron;
	gold*				_gold;

	


	int _objectNum;



public:
	objectManager();
	~objectManager();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	//���� 
	void SetAxe();
	void SetPickAxe();
	void SetHoe();
	void SetCan();
	void SetRod();
	//��	��
	void SetSword();
	void SetSlingShot();
	//��	��
	void SetPufferFish();
	void SetTuna();
	void SetHaliBut();
	//��	��
	void SetCauliFlowerSeed();
	void SetParsnipSeed();
	void SetPotatoSeed();
	void SetKaleSeed();
	//�۹�
	void SetCauliFlower();
	void SetParsnip();
	void SetPotato();
	void SetKale();
	//����
	void SetCopper();
	void SetIron();
	void SetGold();


	//======================= ������ & ������ ======================= //
	vector<object*> GetVObject() { return _vObject; }
	vector<object*>::iterator GetVIObject() { return _viObject; }

	//======================= ============== ======================= //
	//=======================   �޸� ��ũ   ======================= //
	// 
	//======================= ============== ======================= //








};

