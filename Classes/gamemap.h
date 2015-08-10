#pragma once
#include"cocos2d.h"
#include"Global.h"
USING_NS_CC;
class GameMap : public cocos2d::CCTMXTiledMap
{
private:
	CCTMXLayer* hidematelayer;
public:
	GameMap(void);
	~GameMap(void);
	//��̬��������������GameMapʵ��
	static GameMap* gameMapWithTMXFile(const char *tmxFile);

	//TiledMap��cocos2d-x����ϵ�໥ת���ķ���
	CCPoint tileCoordForPosition(CCPoint position);
	CCPoint positionForTileCoord(CCPoint tileCoord);
	
	CCTMXLayer* gethidemate();
	
	
};

