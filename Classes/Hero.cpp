#include"Hero.h"
#include "Hero.h"
#include"Global.h"
#include "gamemap.h"
USING_NS_CC;

Hero::Hero(void)
{
	sGlobal->hero=this;
}


Hero::~Hero(void)
{
}

//��̬��������������Heroʵ��
Hero* Hero::heroWithinLayer()
{
	//newһ������
	Hero *pRet = new Hero();
	//����init����
	if (pRet && pRet->heroInit())
	{
		//��ʵ������autorelease�أ�ͳһ��������ƶ������������
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}
bool Hero::heroInit()
{
	
	
	isWin=false;
	isanimate=false;
	hspeed=0;
	isDead=false;
	//
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("leader.plist");
	heroSprite = CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("alcl3.png"));
	//����ê��
	heroSprite->setAnchorPoint(ccp(0,0));
	
	//��������ʾ��heroSprite�ӵ��Լ��Ľڵ���
	this->addChild(heroSprite);
	this->setAnchorPoint(ccp(0,0));
	//һ��ʼ������move״̬��
	isHeroMoving = false;
	isJumpDone=false;
	vspeed=0;
	return true;
}
void Hero::mapfollowing(){

}
/*
�Ѿ��ڵ�ͼ��ǲ��ܴ����ĸ��ӣ�name=hidemate�����˷���Ϊ�жϡ�
*/
bool  Hero::issettedPosition(Point position){
	
	Point tileCoord = sGlobal->gameMap->tileCoordForPosition(position);
	
	int tileGid =sGlobal->gameMap->gethidemate()->tileGIDAt(tileCoord);

	if (tileGid)
	{
		
		Value propertiesValue = sGlobal->gameMap->getPropertiesForGID(tileGid);
		
		CCLOG("ok!!!!!!!!!!!,%d",propertiesValue);
         if(!propertiesValue.isNull())
         {	
             ValueMap& properties = propertiesValue.asValueMap();
               if (!properties.empty()) {
            auto collision = properties["Collidable"].asString();
            if ("True" == collision) {
				return false;
			}else
			{
				return true;
			}
        }else
			{
				return true;
			}
	}else
	{
		return true;
	}	

	}else
	{
		return true;
	}
       


}


void Hero::move(int i)
{
	   if (isDead)
	   {return;
	   }
	   if(i>0)
	   {
		   //����Ϊ48*48
         float targetX=this->getPositionX()+i+48;
		

       for (float j=this->getPositionY();j<=(48+this->getPositionY());j++)
	   {
		   if (!(issettedPosition(ccp(targetX,j))))
		   {
			   i=0;
		   }
	   }


	   }
	   if(i<0)
	   {
	   float targetX2=this->getPositionX()+i;
	   for (float j=this->getPositionY();j<=(48+this->getPositionY());j++)
	   {
		   if (!(issettedPosition(ccp(targetX2,j))))
		   {
			   i=0;
		   }
	   }
	   }
		this->setPosition(this->getPositionX()+1*i,this->getPositionY());
		mapfollowing();
		
	
}