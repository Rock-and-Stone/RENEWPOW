#include "pch.h"
#include "inventory.h"

HRESULT inventory::init()
{
    _quickSlot = IMAGEMANAGER->findImage("quickSlot");
    _invenImg = IMAGEMANAGER->findImage("itemInventory");


    _quickSlotRc = RectMakeCenter(WINSIZEX / 2, WINSIZEY - _quickSlot->getHeight() / 2, _quickSlot->getWidth(), _quickSlot->getHeight());
    _inventoryRc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, _invenImg->getWidth(), _invenImg->getHeight());



    _isInvenOpen = false;

    return S_OK;
}

void inventory::release()
{
}

void inventory::update()
{
    //카메라에 따라서 퀵슬롯위치 변경
  ////if(camx)
  //{

  //}

  //인벤토리에서 직사각형으로 만들기
  //for (int j = 0; j < IVTILEY; ++j)
  //{
  //    for (int i = 0; i < IVTILEX; ++i)
  //    {
  //        _rc = RectMakeCenter
  //    }
  //}





    if (KEYMANAGER->isOnceKeyDown('E')) _isInvenOpen = !_isInvenOpen;

    if (_isInvenOpen)
    {


    }
    else if (!_isInvenOpen)
    {



    }


}

void inventory::render()
{
    if (_isInvenOpen)
    {
        _invenImg->render(getMemDC(), _inventoryRc.left, _inventoryRc.top);
    }
    else if (!_isInvenOpen)
    {
        _quickSlot->render(getMemDC(), _quickSlotRc.left, _quickSlotRc.top);

    }
}

void inventory::ClickObject()
{
}

void inventory::DragObject()
{
}

void inventory::DragObjectToSwap()
{
}
