#pragma once
#include"cocos2d.h"
USING_NS_CC;
class Hero  : public cocos2d::CCNode
{
public:
	Hero(void);
	~Hero(void);
	//静态方法，用于创建勇士实例
	static Hero *heroWithinLayer();

	//让勇士向指定方向移动一格
	void move(int i);
	void jump();
	bool isanimate;
	//初始化方法
	bool heroInit();
	//地图跟随
	void mapfollowing();
	bool issettedPosition(Point position);


    bool isHeroMoving;
	bool isJumpDone;
	float hspeed;
	float vspeed;
	bool isDead;
	bool isWin;
private:
	//用于显示勇士形象的精灵
	CCSprite *heroSprite;
	//临时保存目标的Tilemap坐标
	CCPoint targetTileCoord;
	CCPoint targetPosition;
	float speed;
};
