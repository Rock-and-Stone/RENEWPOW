#pragma once
#define TILESIZE 32	//Ÿ�� ������ 32X32

#define TILEX 20	//���� Ÿ�� ����
#define TILEY 20	//���� Ÿ�� ����

//Ÿ�� �԰� 20 X 32 ������ϱ� -> �� ������� 640 X 640
#define TILESIZEX TILESIZE * TILEX
#define TILESIZEY TILESIZE * TILEY

//Ÿ�� �� ���� 20�� ���� 9��
#define SAMPLETILEX 15
#define SAMPLETILEY 4

#define SAMPLEOBJECTX 13
#define SAMPLEOBJECTY 18


//�̳ѹ����� �ص� ������ �������� �޸� �Ƴ��ٰ� ���� ���
//��Ʈ�ʵ�� �� �� �غ��ڽ��� (������ �� �̳ѹ� �ᵵ ������)

#define ATTR_UNMOVE 0x00000001	//������ Ÿ��
#define ATTR_HOE	0x00000002	//��������
#define ATTR_ROAD	0x00000004	//��������
#define ATTR_ENTRANCE	0x00000008	//���ⱸ


//����
enum TERRAIN
{
	TR_GRASS_0, TR_GRASS_1, TR_GRASS_2, TR_DIRT, TR_DIRT_WET, TR_WATER, TR_END
};

//������Ʈ
enum OBJECT
{
	OBJ_BLOCK1, OBJ_BLOCK3, OBJ_BLOCKS,
	OBJ_FLAG1, OBJ_FLAG2,
	OBJ_TANK1, OBJ_TANK2, OBJ_NONE
};

enum POS
{
	//1P���� ���(������ ���) 1P ��ũ ������ ��ġ
	POS_FLAG1, POS_FLAG2, POS_TANK1, POS_TANK2
};

//Ÿ�� ����ü (Ÿ�� �������� ����ִ�)
struct tagTile
{
	TERRAIN terrain;
	OBJECT obj;
	RECT rc;
	int terrainFrameX;
	int terrainFrameY;
	int objFrameX;
	int objFrameY;
	int posX, posY;
};

//Ÿ�� ��
struct tagSampleTile
{
	RECT rcTile;
	int terrainFrameX;
	int terrainFrameY;
};
