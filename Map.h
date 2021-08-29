#pragma once
#include "tileNode.h"
#include "gameNode.h"
#include "button.h"

//Ÿ�� �� ���� 20�� ���� 9��
#define SAMPLEOBJECTX 13
#define SAMPLEOBJECTY 18


enum CTRL
{
	CTRL_SAVE,			//���̺�		��ư
	CTRL_LOAD,			//�ε�		��ư
	CTRL_TERRAINDRAW,	//����		��ư
	CTRL_OBJDRAW,		//������Ʈ	��ư
	CTRL_ERASER,		//���찳		��ư
	CTRL_END
};

struct tagCurrentTile
{
	int x;
	int y;
};


class Map : public gameNode
{
private:
	tagTile _tiles[TILEX * TILEY];		//Ÿ��
	DWORD _attribute[TILEX * TILEY];	//Ÿ�ϼӼ�

	tagCurrentTile _currentTile;
	tagSampleTile _sampleTile[SAMPLETILEX * SAMPLETILEY];

	button* _buttonSave;
	button* _buttonLoad;
	button* _buttonDraw;
	button* _buttonObject;
	button* _buttonErase;

	button* _buttonLeft;
	button* _buttonRight;

	int _pos[2];
	int _ctrSelect;
	bool _isPicked;

	float _posX, _posY;
	float _rendX, _rendY;

public:
	Map();
	~Map();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void save();
	void load();

	void Movement();

	void SetSample(int select, string str);
	void PickSample();
	void DrawMap();
	void AutoDraw(tagTile* currentTile);

	static void Button(void* obj);

	tagTile* getTile() { return _tiles; }


	//STEP2
	//Ÿ�ϼӼ��� ���� �����ڵ� ������־�� �Ҳ��ϴ�
	DWORD* getAttribute() { return _attribute; }

	TERRAIN terrainSelect(int frameX, int frameY);
	OBJECT objSelect(int frameX, int frameY);

	//�츰 ����ϰ� ���� �ʽ��ϴ�
	int getPosFirst() { return _pos[0]; }
	int getPosSecond() { return _pos[1]; }

	
};

