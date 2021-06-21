#include "PlayerWinScene.h"
#include "GameSceneOne.h"
#include "GameSceneTwo.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
bool isCheckS;
Scene* PlayerWinScene::createScene(int isCheck)
{
    isCheckS = isCheck;
    return PlayerWinScene::create();
}

// Print useful error message instead of segfaulting when files are not there.

// on "init" you need to initialize your instance
bool PlayerWinScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    if(isCheckS = 0){
        auto x_win = Sprite::create("image/w1.png");
        x_win->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
        this->addChild(x_win, 0);
    }
    else if (isCheckS = 1) {
        auto o_win = Sprite::create("image/w2.png");
        o_win->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
        this->addChild(o_win, 0);
    }
    else if (isCheckS = -1) {
        auto draw = Sprite::create("image/w3.png");
        draw->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
        this->addChild(draw, 0);
    }
    this->scheduleOnce(schedule_selector(PlayerWinScene::RestartSceneOne), 1.0f);
    return true;
}


void PlayerWinScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
}
void PlayerWinScene::RestartSceneOne(float restart) {
    auto scene = GameSceneOne::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(2.0f, scene));
}