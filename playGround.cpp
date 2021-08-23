#include "pch.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

//�ʱ�ȭ�� ���⿡�� �ض�!!!
HRESULT playGround::init()
{
	gameNode::init(true);

	SCENEMANAGER->addScene("loadingScene", new loadingScene);
	SCENEMANAGER->addScene("playerScene", new playerScene);

	SCENEMANAGER->changeScene("loadingScene");

	return S_OK;
}

//�޸� ������ ����� �ض�!!!!
void playGround::release()
{
	gameNode::release();


}

//����ó���� ����ٰ�!
void playGround::update()
{
	gameNode::update();

	SCENEMANAGER->update();
}

//����� �׷����!!!
void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============������ ���� �ǵ帮�� ���� ============

	SCENEMANAGER->render();

	char str[25];
	sprintf_s(str, "worldTime : %f", TIMEMANAGER->getWorldTime());
	TextOut(getMemDC(), 0, 0, str, strlen(str));

	//=============== �ؿ��� �ǵ������� ================
	_backBuffer->render(getHDC(), 0, 0);

}

