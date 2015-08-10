#include "GameMap.h"

GameMap::GameMap(void)
{
	sGlobal->gameMap=this;
}


GameMap::~GameMap(void)
{
	this->unscheduleAllSelectors();
}
GameMap* GameMap::gameMapWithTMXFile(const char *tmxFile)
{
	//new一个对象
	GameMap *pRet = new GameMap();
	//调用init方法
	if (pRet->initWithTMXFile(tmxFile))
	{
		
		//将实例放入autorelease池，统一由引擎控制对象的生命周期
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}
//从cocos2d-x坐标转换为Tilemap坐标
CCPoint GameMap::tileCoordForPosition(CCPoint position)
{
	int x = position.x / this->getTileSize().width;
	int y = (((this->getMapSize().height) * this->getTileSize().height) - position.y) / this->getTileSize().height;
	
	return ccp(x, y);
	
}

//从Tilemap坐标转换为cocos2d-x坐标
CCPoint GameMap::positionForTileCoord(CCPoint tileCoord)
{
	CCPoint pos =  ccp((tileCoord.x * this->getTileSize().width),
		((this->getMapSize().height - tileCoord.y) * this->getTileSize().height));
	return pos;
}
CCTMXLayer* GameMap::gethidemate()
{
	hidematelayer=getLayer("hidemate");
	return hidematelayer;
}

