#include"cocos2d.h"
#include "Global.h"
USING_NS_CC;
class ControlLayer : public cocos2d::CCLayer
{
public:
	ControlLayer(void);
	~ControlLayer(void);
		virtual bool init();

		CREATE_FUNC(ControlLayer);

		void  onTouchesBegan (const std::vector<Touch*>& touches, cocos2d::Event  *event);
		void  onTouchesEnded (const std::vector<Touch*>& touches, cocos2d::Event  *event);
		void  onTouchesMoved(const std::vector<Touch*>& touches, cocos2d::Event  *event);
		void  update(float delta);
		int failedLayerInitTimes;
	   int 	winLayerInitTimes;


};