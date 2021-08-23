#include "pch.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

//초기화는 여기에다 해라!!!
HRESULT playGround::init()
{
	gameNode::init(true);

	SCENEMANAGER->addScene("loadingScene", new loadingScene);
	SCENEMANAGER->addScene("playerScene", new playerScene);

	SCENEMANAGER->changeScene("loadingScene");

	return S_OK;
}

//메모리 해제는 여기다 해라!!!!
void playGround::release()
{
	gameNode::release();


}

//연산처리는 여기다가!
void playGround::update()
{
	gameNode::update();

	SCENEMANAGER->update();
}

//여기다 그려줘라!!!
void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============위에는 제발 건드리지 마라 ============

	SCENEMANAGER->render();

	char str[25];
	sprintf_s(str, "worldTime : %f", TIMEMANAGER->getWorldTime());
	TextOut(getMemDC(), 0, 0, str, strlen(str));

	//=============== 밑에도 건들지마라 ================
	_backBuffer->render(getHDC(), 0, 0);

}

