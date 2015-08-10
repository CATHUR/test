#include "Global.h"
#include"stdio.h" 
DECLARE_SINGLETON_MEMBER(Global);

Global::Global(void)
{
	isEffectOn=true;
	isMusicOn=true;
	gameStage=1;
	IQ=250;
}


Global::~Global(void)
{
	
	gameMap=NULL;
}
