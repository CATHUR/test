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

//静态方法，用于生成Hero实例
Hero* Hero::heroWithinLayer()
{
	//new一个对象
	Hero *pRet = new Hero();
	//调用init方法
	if (pRet && pRet->heroInit())
	{
		//将实例放入autorelease池，统一由引擎控制对象的生命周期
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
	//设置锚点
	heroSprite->setAnchorPoint(ccp(0,0));
	
	//将用于显示的heroSprite加到自己的节点下
	this->addChild(heroSprite);
	this->setAnchorPoint(ccp(0,0));
	//一开始不处于move状态。
	isHeroMoving = false;
	isJumpDone=false;
	vspeed=0;
	return true;
}
void Hero::mapfollowing(){

}
/*
已经在地图标记不能穿过的格子（name=hidemate），此方法为判断。
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
		   //精灵为48*48
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