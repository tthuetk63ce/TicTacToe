#ifndef __PLAYER_WIN_SCENE_H__
#define __PLAYER_WIN_SCENE_H__

#include "cocos2d.h"

class PlayerWinScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene(int isCheck);

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void RestartSceneOne(float restart);
    
    // implement the "static create()" method manually
    CREATE_FUNC(PlayerWinScene);
};

#endif // __PLAYER_WIN_SCENE_H__
#pragma once
