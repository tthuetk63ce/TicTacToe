#ifndef __SCENE_SET_UP__
#define __SCENE_SET_UP__

#include "cocos2d.h"



class SceneSetUp: public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	void loadScene();
	CREATE_FUNC(SceneSetUp);
};



#endif // __SCENE_SET_UP__

