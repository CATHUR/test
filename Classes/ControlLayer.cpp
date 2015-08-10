#include "ControlLayer.h"
#include"Global.h"
#include"Hero.h"
USING_NS_CC;
CCSprite *leftSprite;
CCSprite *rightSprite;
CCSprite *jumpSprite;
bool leftSpriteTouched;
bool rightSpriteTouched;
bool jumpSpriteTouched;
CCSize size;
ControlLayer::ControlLayer(void)
{
	sGlobal->controlLayer;
}


ControlLayer::~ControlLayer(void)
{
}
bool ControlLayer::init()
{
	if ( !CCLayer::init() )
	{
		return false;
	}
	
	size=CCDirector::sharedDirector()->getWinSize();
	winLayerInitTimes=0;
	failedLayerInitTimes=0;
	leftSpriteTouched=false;
	rightSpriteTouched=false;
	jumpSpriteTouched=false;
	
	this->setTouchEnabled(true);
	EventDispatcher* eventDispatcher = Director::getInstance()->getEventDispatcher();  
   auto listen = EventListenerTouchAllAtOnce::create();  
    listen->onTouchesBegan = CC_CALLBACK_2(ControlLayer::onTouchesBegan,this);  
    listen->onTouchesMoved = CC_CALLBACK_2(ControlLayer::onTouchesMoved,this);  
    listen->onTouchesEnded = CC_CALLBACK_2(ControlLayer::onTouchesEnded,this);  
    eventDispatcher->addEventListenerWithSceneGraphPriority(listen,this);



	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("button.plist");
	leftSprite=CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("left.png"));
	leftSprite->setPosition(ccp(45,45));
	this->addChild(leftSprite);
	rightSprite=CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("righ.png"));
	rightSprite->setPosition(ccp(45+90+20,45));
	this->addChild(rightSprite);
	jumpSprite=CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("jump.png"));
	jumpSprite->setPosition(ccp(size.width-70,45));
	addChild(jumpSprite);
	this->scheduleUpdate();
	
	return true;
}
void  ControlLayer::onTouchesBegan (const std::vector<Touch*>& touches, cocos2d::Event  *event)
{
	 for(auto &item : touches)  
    {  
        auto touch = item;  
         CCPoint touchs = touch->getLocationInView(); 
       CCPoint  location=CCDirector::sharedDirector()->convertToGL(touchs);


	   if (location.x<90&&location.y<90)
	{
		leftSprite->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("left1.png"));
		leftSpriteTouched=true;
	}else if (location.x>90&&location.x<180&&location.y<90)//ÓÒ°´Å¥
	{
		rightSprite->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("right1.png"));
		rightSpriteTouched=true;
	}
	if (location.x>size.width-140&&location.y<90)//Ìø
	{
		jumpSprite->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("jump1.png"));
		jumpSpriteTouched=true;
	}

	 }
	

}

void  ControlLayer::onTouchesEnded (const std::vector<Touch*>& touches, cocos2d::Event  *event)
{
	 for(auto &item : touches)  
    {  
        auto touch = item;  
         CCPoint touchs = touch->getLocationInView(); 
       CCPoint  location=CCDirector::sharedDirector()->convertToGL(touchs);

	   if (location.x<90&&location.y<90)
	{
		leftSprite->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("left.png"));
		leftSpriteTouched=false;
	}else if (location.x>90&&location.x<180&&location.y<90)
	{
		rightSpriteTouched=false;
		rightSprite->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("righ.png"));
	}
	if (location.x>size.width-140&&location.y<90)
	{
		jumpSprite->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("jump.png"));
		jumpSpriteTouched=false;
	}
	

	 }
	
}
void ControlLayer::onTouchesMoved(const std::vector<Touch*>& touches, cocos2d::Event  *event)
{
	 for(auto &item : touches)  
    {  
        auto touch = item;  
         CCPoint touchs = touch->getLocationInView(); 
       CCPoint  location=CCDirector::sharedDirector()->convertToGL(touchs);

	if (!(location.x<90&&location.y<90))
	{
		if (location.x<size.width/2)
		{
		
		leftSprite->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("left.png"));
		leftSpriteTouched=false;
		}
	}
	if (!(location.x>110&&location.x<200&&location.y<90))
	{
		if (location.x<size.width/2)
		{
		rightSpriteTouched=false;
		rightSprite->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("righ.png"));
		}
	}
	if (!(location.x>(size.width-135)&&location.y<90))
	{
		if (location.x>size.width/2)
		{
			jumpSprite->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("jump.png"));
			jumpSpriteTouched=false;
		}
	}
	

	 }

}
void ControlLayer::update(float dt)
{
	
	int hspeed=0;
	if (leftSpriteTouched)
	{
		hspeed=-2;
	}else if (rightSpriteTouched)
	{
		hspeed=2;
	}else{
		hspeed=0;
	}
	
	sGlobal->hero->move(hspeed);
	
 
}