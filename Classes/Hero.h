#pragma once
#include"cocos2d.h"
USING_NS_CC;
class Hero  : public cocos2d::CCNode
{
public:
	Hero(void);
	~Hero(void);
	//��̬���������ڴ�����ʿʵ��
	static Hero *heroWithinLayer();

	//����ʿ��ָ�������ƶ�һ��
	void move(int i);
	void jump();
	bool isanimate;
	//��ʼ������
	bool heroInit();
	//��ͼ����
	void mapfollowing();
	bool issettedPosition(Point position);


    bool isHeroMoving;
	bool isJumpDone;
	float hspeed;
	float vspeed;
	bool isDead;
	bool isWin;
private:
	//������ʾ��ʿ����ľ���
	CCSprite *heroSprite;
	//��ʱ����Ŀ���Tilemap����
	CCPoint targetTileCoord;
	CCPoint targetPosition;
	float speed;
};
