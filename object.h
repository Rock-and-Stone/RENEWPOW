#pragma once
#include "gameNode.h"
//#include "CameraManager.h"

//도구
enum TOOL
{
	AXE,			//도끼
	PICKAXE,		//곡괭이
	HOE,			//호미
	CAN,			//물조리개	
	ROD				//낚시대
};

//무기
enum WEAPON
{
	SWORD,			//검
	SLINGSHOT		//새총

};

//물꼬기
enum FISH
{
	PUFFERFISH,		//황금뽂어
	TUNA,			//참취
	HALIBUT			//꽝어
};
//씨앗
enum SEED
{
	CAULIFLOWERSEED,
	PARSNIPSEED,
	POTATOSEED,
	KALESEED
};

//작물
enum CROP			//음식겸
{
	CAULIFLOWER,	//콜리플라워	350G	195Hp	87Sp	
	PARSNIP,		//파스닙		220G	65Hp	29Sp
	POTATO,			//감자		150G	65Hp	29Sp
	KALE			//케일		220G	130Hp	58Sp
};

//광물
enum ORE
{
	COPPER,			//구리		 5G
	IRON,			//철			10G
	GOLD,			//골드		25G
};


class object : public gameNode
{
protected:
	//enum문  변수;
	TOOL		_tool;
	WEAPON		_weapon;
	FISH		_fish;
	SEED		_seed;
	CROP		_crop;
	ORE			_ore;


	image* _objectImg;				//오브젝트 이미지

	//충돌용 렉트
	RECT _objectRc;					//물체의 충돌렉트

	//위치값
	float _posX, _posY;				//오브젝트 실제위치값
	float _rendX, _rendY;			//카메라X,Y
	
	//방향 설정
	int _direction;					//방향

	int _price;						//물건의 가격

	int _hP;						//체력을 채워준다.
	int _sP;						//스태미나를 채워준다.

	

public:
	object();
	~object();

	virtual HRESULT init();
	virtual HRESULT init(const char* imageName , POINT postition);
	virtual void release();
	virtual void update();
	virtual void render();

	void Draw();



	//======================= 접근자 & 설정자 ======================= //

	//ENUM문
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
	
	//기타 변수들
	inline RECT GetRect() { return _objectRc; }
	
	//이미지 겟
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

