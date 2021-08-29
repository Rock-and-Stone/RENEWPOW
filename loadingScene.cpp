#include "pch.h"
#include "loadingScene.h"
#include "progressBar.h"

loadingScene::loadingScene()
	: _background(nullptr), 
	_loadingBar(nullptr),
	_currentCount(0)
{
}


loadingScene::~loadingScene()
{
}

HRESULT loadingScene::init()
{
	_background = IMAGEMANAGER->addImage("���", "source/Images/loadingScene/blackWindow.bmp", WINSIZEX, WINSIZEY, true, MAGENTA);

	/*_loadingBar = new progressBar;
	_loadingBar->init(0, WINSIZEY - 50, WINSIZEX, 50);
	_loadingBar->setGauge(0, 0);*/

	IMAGEMANAGER->addFrameImage("loading", "source/Images/loadingScene/loading.bmp", 822, 62, 3, 1, true, MAGENTA);
	_loadingImg = IMAGEMANAGER->findImage("loading");
	_frameX = 0;
	_count = 0;

	CreateThread(
		NULL,				//������ ���ȼӼ�(�ڽ������� �����Ҷ�)
		NULL,				//�������� ����ũ��(0�̸� ���ξ����� ����)
		threadFunction,		//����� �Լ�
		this,				//������ �Ű�����(this �� ������ �� Ŭ����)
		NULL,				//������ Ư��
		NULL);				//������ ID

	return S_OK;
}

void loadingScene::release()
{
	SAFE_DELETE(_loadingBar);
}

void loadingScene::update()
{
 /* _loadingBar->update();
  _loadingBar->setGauge(_currentCount, LOADINGMAX);*/

	if (_currentCount == LOADINGMAX)
	{
		//�̵��� �� ���� ����
<<<<<<< HEAD
<<<<<<< HEAD
		SCENEMANAGER->changeScene("playerScene");
=======
		SCENEMANAGER->changeScene("mainMenuScene");
=======
		SCENEMANAGER->changeScene("inventory");
>>>>>>> 77a5ef50957f43d71ad0261dfbf7a1339d2770bc
	}

	_count++;

	if (_count % 30 == 0)
	{
		_frameX++;
>>>>>>> 53bf743197c2793c910e2e0ae603992dd0fa8733
	}
	if (_frameX >= 3) _frameX = 0;
}

void loadingScene::render()
{
	_background->render(getMemDC());
	//_loadingBar->render();
	_loadingImg->frameRender(getMemDC(), 50, WINSIZEY - 100, _frameX, 0);
}

DWORD CALLBACK threadFunction(LPVOID lpParameter)
{
	loadingScene* loadingHelper = (loadingScene*)lpParameter;


	while (loadingHelper->_currentCount != LOADINGMAX)
	{
<<<<<<< HEAD
		//�ҽ� ���� �߰�	
		//IMAGEMANAGER->addFrameImage("playerTool", "playerTool.bmp", 96, 16, 6, 0, true, RGB(255, 0, 255)); // �÷��̾� ����
		IMAGEMANAGER->addFrameImage("player","source/Images/�÷��̾��̹���3.bmp",576,2176,12,34,true,MAGENTA);

=======
		//�ҽ� ���� �߰�
		
		//IMAGEMANAGER->addFrameImage("playerTool", "playerTool.bmp", 96, 16, 6, 0, true, RGB(255, 0, 255)); // �÷��̾� ����
<<<<<<< HEAD
>>>>>>> 53bf743197c2793c910e2e0ae603992dd0fa8733

=======
		   //�ҽ� ���� �߰�
		// �κ��丮 UI
		IMAGEMANAGER->addImage("itemInventory", "source/Images/inventory/itemInventory.bmp", 750, 550, true, MAGENTA);
		// ������ UI
		IMAGEMANAGER->addImage("quickSlot", "source/Images/inventory/playerQuickslot.bmp", 565, 69, true, MAGENTA);
		// ���۸޴�
		IMAGEMANAGER->addImage("craftMenu", "source/Images/inventory/Craftinven.bmp", 750, 550, true, MAGENTA);
		// ���ȸ޴�
		IMAGEMANAGER->addImage("statMenu", "source/Images/inventory/skill.bmp", 750, 550, true, MAGENTA);
		// �����޴�
		IMAGEMANAGER->addImage("settingMenu", "source/Images/inventory/setting.bmp", 750, 550, true, MAGENTA);
		// ������޴�
		//IMAGEMANAGER->addImage("")

		////���� �κ��丮
		//IMAGEMANAGER->addFrameImage("playerTool", "source/Images/playerInventory/playerTool.bmp", 96, 16, 6, 0, true, RGB(255, 0, 255)); // �÷��̾� ����
		////���� ������
		//IMAGEMANAGER->addFrameImage("seedItem", "source/Images/BMP/���Ѿ�����(original).bmp", 360, 160, 9, 4, true, RGB(255, 0, 255));
		////���� �����۾����ܿ�
		//IMAGEMANAGER->addFrameImage("seedItemSmall", "source/Images/BMP/small���Ѿ�����(original).bmp", 144, 64, 9, 4, true, RGB(255, 0, 255));
		////�۹�
		//IMAGEMANAGER->addFrameImage("crops", "source/Images/BMP/����(ori).bmp", 640, 120, 16, 3, true, RGB(255, 0, 255));
		////�۹� ������
		//IMAGEMANAGER->addFrameImage("cropsSmall", "source/Images/BMP/����small(ori).bmp", 256, 48, 16, 3, true, RGB(255, 0, 255));
>>>>>>> 77a5ef50957f43d71ad0261dfbf7a1339d2770bc

		//==================UI �κ� ���� �߰� ��=====================
		//�̹���
		IMAGEMANAGER->addImage("title", "source/images/mainScene/title.bmp", 690, 318, true, MAGENTA);
		IMAGEMANAGER->addImage("mainScene", "source/images/mainScene/mainScene.bmp", WINSIZEX, WINSIZEY, true, MAGENTA);
		IMAGEMANAGER->addFrameImage("start", "source/images/mainScene/start.bmp", 185, 292, 1, 2, true, MAGENTA);
		IMAGEMANAGER->addFrameImage("load", "source/images/mainScene/load.bmp", 185, 292, 1, 2, true, MAGENTA);
		IMAGEMANAGER->addFrameImage("mapTool", "source/images/mainScene/mapTool.bmp", 185, 292, 1, 2, true, MAGENTA);
		IMAGEMANAGER->addFrameImage("exit", "source/images/mainScene/exit.bmp", 185, 292, 1, 2, true, MAGENTA);
		IMAGEMANAGER->addFrameImage("back", "source/images/mainScene/back.bmp", 198, 162, 1, 2, true, MAGENTA);
		

		//����
		//SOUNDMANAGER->addSound("bugCave", "source/Sounds/bugCave.mp3", true, true);				//���� �Ҹ�
		//SOUNDMANAGER->addSound("character", "source/Sounds/character.mp3", true, false);		//�층 �츮�������� �Ҹ�
		//SOUNDMANAGER->addSound("death", "source/Sounds/death.mp3", true, false);				//���� �� ���� �Ҹ�
		//SOUNDMANAGER->addSound("doorOpen", "source/Sounds/doorOpen.mp3", true, false);			//���� �� ���� �Ҹ�
		//SOUNDMANAGER->addSound("springBGM", "source/Sounds/springBGM.mp3", true, true);			//�ΰ��� ��� ����
		//SOUNDMANAGER->addSound("fireSpell", "source/Sounds/fireSpell.mp3", true, false);		//�뱤�� �����Ǵ� �Ҹ�
		//SOUNDMANAGER->addSound("getItem", "source/Sounds/getItem.mp3", true, false);			//������ �ֿ� �� ���� �Ҹ�
		//SOUNDMANAGER->addSound("hitGrass", "source/Sounds/hitGrass.mp3", true, false);			//������ Ǯ �� �� ���� ȿ����
		//SOUNDMANAGER->addSound("hitRock", "source/Sounds/hitRock.mp3", true, false);			//��̷� �� ���� �� ���� ȿ����
		//SOUNDMANAGER->addSound("hitTree", "source/Sounds/hitTree.mp3", true, false);			//������ ���� ���� �� ���� ȿ����
		//SOUNDMANAGER->addSound("hitPlayer", "source/Sounds/hitPlayer.mp3", true, false);		//���� �� �� ���� �Ҹ�
		//SOUNDMANAGER->addSound("hoe", "source/Sounds/hoe.mp3", true, false);					//�� ���� ���� �Ҹ�
		//SOUNDMANAGER->addSound("menuClose", "source/Sounds/menuClose.mp3", true, false);		//�޴� �ݴ� �Ҹ�
		//SOUNDMANAGER->addSound("menuOpen", "source/Sounds/menuOpen.mp3", true, false);			//�޴� ���� �Ҹ�
		//SOUNDMANAGER->addSound("menuSelect", "source/Sounds/menuSelect.mp3", true, false);		//�޴� ���� �Ҹ�
		//SOUNDMANAGER->addSound("monsterDead", "source/Sounds/monsterDead.mp3", true, false);	//���� �״� �Ҹ�
		//SOUNDMANAGER->addSound("moveGrass", "source/Sounds/moveGrass.mp3", true, false);		//Ǯ���� ���� ��
		//SOUNDMANAGER->addSound("moveRock", "source/Sounds/moveRock.mp3", true, false);			//������ ���� ��
		//SOUNDMANAGER->addSound("moveSoil", "source/Sounds/moveSoil.mp3", true, false);			//���� ���� ��
		//SOUNDMANAGER->addSound("day", "source/Sounds/day.mp3", true, true);						//��ħ�� �� �� ���� �Ҹ�
		//SOUNDMANAGER->addSound("night", "source/Sounds/night.mp3", true, true);					//���� �� �� ���� �Ҹ�
		//SOUNDMANAGER->addSound("opening", "source/Sounds/opening.mp3", true, true);				//������ �Ҹ�
		//SOUNDMANAGER->addSound("pickUpItem", "source/Sounds/pickUpItem.mp3", true, false);		//�Ⱦ� ������(?)
		//SOUNDMANAGER->addSound("purchase", "source/Sounds/purchase.mp3", true, false);			//���� ���� �Ҹ�
		//SOUNDMANAGER->addSound("removeGrass", "source/Sounds/removeGrass.mp3", true, false);	//Ǯ ���� �Ҹ�
		//SOUNDMANAGER->addSound("removeRock", "source/Sounds/removeRock.mp3", true, false);		//�� ���� �Ҹ�
		//SOUNDMANAGER->addSound("removeTree", "source/Sounds/removeTree.mp3", true, false);		//���� ���� �Ҹ�
		//SOUNDMANAGER->addSound("seeds", "source/Sounds/seeds.mp3", true, false);				//���� �ɴ� �Ҹ�
		//SOUNDMANAGER->addSound("slime", "source/Sounds/slime.mp3", true, false);				//�������� ������ �� ���� �Ҹ�
		//SOUNDMANAGER->addSound("toolSwap", "source/Sounds/toolSwap.mp3", true, false);			//�Ǵ����� ���� �Ҹ�
		//SOUNDMANAGER->addSound("watering", "source/Sounds/watering.mp3", true, false);			//���� ��ų� ���� �� �� ���� �Ҹ�




		



		loadingHelper->_currentCount++;
	}
	return 0;
}
