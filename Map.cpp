#include "pch.h"
#include "Map.h"

Map::Map()
{
}


Map::~Map()
{
}

HRESULT Map::init()
{
	IMAGEMANAGER->addFrameImage("mapTiles", "maptiles.bmp", 640, 288, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));

	load();
	SetSample();

	return S_OK;
}

void Map::release()
{

}

void Map::update()
{
	if (KEYMANAGER->isOnceKeyDown('O')) save();
	if (KEYMANAGER->isOnceKeyDown('L')) load();
	
	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON)) SetMap();
}

void Map::render()
{
	IMAGEMANAGER->render("mapTiles", getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("mapTiles")->getWidth(), 0);

	//���� �׸���
	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		IMAGEMANAGER->frameRender("mapTiles", getMemDC(),
			_tiles[i].rc.left, _tiles[i].rc.top,
			_tiles[i].terrainFrameX, _tiles[i].terrainFrameY);
	}

	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		//������Ʈ �Ӽ��� �ƴϸ� �׸������� (���찳�� ���ﶧ ������)
		if (_tiles[i].obj == OBJ_NONE) continue;
		IMAGEMANAGER->frameRender("mapTiles", getMemDC(),
			_tiles[i].rc.left, _tiles[i].rc.top,
			_tiles[i].objFrameX, _tiles[i].objFrameY);
	}
}

void Map::save()
{
	HANDLE file;
	DWORD write;

	file = CreateFile("tileMapSave.map", GENERIC_WRITE, NULL, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, _tiles, sizeof(tagTile) * TILEX * TILEY, &write, NULL);

	CloseHandle(file);
}

void Map::load()
{
	HANDLE file;
	DWORD read;

	file = CreateFile("tileMapSave.map", GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, _tiles, sizeof(tagTile) * TILEX * TILEY, &read, NULL);
	ReadFile(file, _pos, sizeof(int) * 2, &read, NULL);

	memset(_attribute, 0, sizeof(DWORD) * TILEX * TILEY);
	memset(_pos, 0, sizeof(int) * 2);

	//STEP 1
	//Ÿ���� �ҷ��ͼ� �ش� Ÿ�Ͽ� �Ӽ����� �ο��Ѵ�
	//�� Ÿ��, �Ǵ� ������Ʈ ���� �������� Ÿ���̴�

	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		if (_tiles[i].terrain == TR_WATER) _attribute[i] |= ATTR_UNMOVE;
		if (_tiles[i].obj == OBJ_BLOCK1) _attribute[i] |= ATTR_UNMOVE;
		if (_tiles[i].obj == OBJ_BLOCK3) _attribute[i] |= ATTR_UNMOVE;
		if (_tiles[i].obj == OBJ_BLOCKS) _attribute[i] |= ATTR_UNMOVE;

	}


	CloseHandle(file);
}

void Map::SetSample()
{
	_ctrSelect = CTRL_TERRAINDRAW;

	for (int i = 0; i < SAMPLETILEY; ++i)
	{
		for (int j = 0; j < SAMPLETILEX; ++j)
		{
			_sampleTile[i * SAMPLETILEX + j].terrainFrameX = j;
			_sampleTile[i * SAMPLETILEX + j].terrainFrameY = i;

			SetRect(&_sampleTile[i * SAMPLETILEX + j].rcTile,
				(WINSIZEX - IMAGEMANAGER->findImage("mapTiles")->getWidth()) + j * TILESIZE,
				i * TILESIZE,
				(WINSIZEX - IMAGEMANAGER->findImage("mapTiles")->getWidth()) + j * TILESIZE + TILESIZE,
				i * TILESIZE + TILESIZE);
		}
	}

	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			SetRect(&_tiles[i * TILEX + j].rc,
				j * TILESIZE,
				i * TILESIZE,
				j * TILESIZE + TILESIZE,
				i * TILESIZE + TILESIZE);
		}
	}

	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		_tiles[i].terrainFrameX = 3;
		_tiles[i].terrainFrameY = 0;
		_tiles[i].objFrameX = 0;
		_tiles[i].objFrameY = 0;
		_tiles[i].terrain = terrainSelect(_tiles[i].terrainFrameX, _tiles[i].terrainFrameY);
		_tiles[i].obj = OBJ_NONE;
	}
}

void Map::SetMap()
{
	//Ÿ�ϼ¿��� ���� � Ÿ���� Ŭ���ߴ�!
	for (int i = 0; i < SAMPLETILEX * SAMPLETILEY; ++i)
	{
		if (PtInRect(&_sampleTile[i].rcTile, _ptMouse))
		{
			_currentTile.x = _sampleTile[i].terrainFrameX;
			_currentTile.y = _sampleTile[i].terrainFrameY;
			break;
		}
	}

	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		if (PtInRect(&_tiles[i].rc, _ptMouse))
		{
			if (_ctrSelect == CTRL_TERRAINDRAW)
			{
				_tiles[i].terrainFrameX = _currentTile.x;
				_tiles[i].terrainFrameY = _currentTile.y;

				_tiles[i].terrain = terrainSelect(_currentTile.x, _currentTile.y);
			}
			else if (_ctrSelect == CTRL_OBJDRAW)
			{
				_tiles[i].objFrameX = _currentTile.x;
				_tiles[i].objFrameY = _currentTile.y;

				_tiles[i].obj = objSelect(_currentTile.x, _currentTile.y);
			}
			else if (_ctrSelect == CTRL_ERASER)
			{
				_tiles[i].objFrameX = NULL;
				_tiles[i].objFrameY = NULL;
				_tiles[i].obj = OBJ_NONE;
			}

			InvalidateRect(_hWnd, NULL, false);
			break;
		}
	}

}

TERRAIN Map::terrainSelect(int frameX, int frameY)
{
	if (frameX == 1 && frameY == 0)
	{
		return TR_CEMENT;
	}
	else if (frameX == 2 && frameY == 0)
	{
		return TR_DESERT;
	}
	else if (frameX == 3 && frameY == 0)
	{
		return TR_GRASS;
	}
	else if (frameX == 4 && frameY == 0)
	{
		return TR_WATER;
	}


	return TR_GRASS;
}

OBJECT Map::objSelect(int frameX, int frameY)
{
	if (frameX == 0 && frameY == 0) return OBJ_TANK1;
	else if (frameX == 0 && frameY == 8) return OBJ_TANK2;
	else if (frameX == 0 && frameY == 1) return OBJ_BLOCK1;
	else if (frameX == 0 && frameY == 2) return OBJ_BLOCK3;
	else if (frameX == 15 && frameY == 3) return OBJ_BLOCKS;

	return OBJ_BLOCK1;
}