#ifndef __GAME_SCENE_ONE_H__
#define __GAME_SCENE_ONE_H__

#include "cocos2d.h"
#include <vector>

class GameSceneOne : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void GotoGameSceneTwo(cocos2d::Ref* pSender);
    void RestartScene(float dt);
    void LoadPlayScene();
    void update(float up) override;
    void ACheckWin(float ai);
    int checkXY(float _x, float _y);
    void playerDraw(int x, int k);
    // implement the "static create()" method manually
    CREATE_FUNC(GameSceneOne);
};

#endif // __GAME_SCENE_ONE_H__
#pragma once
