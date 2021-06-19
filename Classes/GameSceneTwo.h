#ifndef __GAME_SCENE_TWO_H__
#define __GAME_SCENE_TWO_H__

#include "cocos2d.h"

class GameSceneTwo : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void GotoGameSceneOne(cocos2d::Ref* pSender);
    // implement the "static create()" method manually
    CREATE_FUNC(GameSceneTwo);
};

#endif // __GAME_SCENE_TWO_H__
#pragma once
