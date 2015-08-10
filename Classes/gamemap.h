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
	//静态方法，用于生成GameMap实例
	static GameMap* gameMapWithTMXFile(const char *tmxFile);

	//TiledMap和cocos2d-x坐标系相互转换的方法
	CCPoint tileCoordForPosition(CCPoint position);
	CCPoint positionForTileCoord(CCPoint tileCoord);
	
	CCTMXLayer* gethidemate();
	
	
};

