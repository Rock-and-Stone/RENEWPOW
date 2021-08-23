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
	_background = IMAGEMANAGER->addImage("���", "source/Images/background.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	_loadingBar = new progressBar;
	_loadingBar->init(0, WINSIZEY - 50, WINSIZEX, 50);
	_loadingBar->setGauge(0, 0);

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
  _loadingBar->update();
  _loadingBar->setGauge(_currentCount, LOADINGMAX);

	if (_currentCount == LOADINGMAX)
	{
		//�̵��� �� ���� ����
		SCENEMANAGER->changeScene("playerScene");
	}
}

void loadingScene::render()
{
	_background->render(getMemDC());
	_loadingBar->render();
}

DWORD CALLBACK threadFunction(LPVOID lpParameter)
{
	loadingScene* loadingHelper = (loadingScene*)lpParameter;


	while (loadingHelper->_currentCount != LOADINGMAX)
	{
		//�ҽ� ���� �߰�



		loadingHelper->_currentCount++;
	}
	return 0;
}
