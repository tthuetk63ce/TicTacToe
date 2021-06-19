#include "SceneSetUp.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
int o_win = 0, x_win = 0, s_draw = 0;

Scene* SceneSetUp::createScene()
{
    return SceneSetUp::create();
};


void SceneSetUp::loadScene() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto h1 = Sprite::create("image/h1.png");
    h1->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100, visibleSize.height / 2 + origin.y + 91.5));
    this->addChild(h1);
    auto h2 = Sprite::create("image/h1.png");
    h2->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100, visibleSize.height / 2 + origin.y - 7.5));
    this->addChild(h2);
    auto hh1 = Sprite::create("image/hh.png");
    hh1->setPosition(Vec2(visibleSize.width / 2 + origin.x - 50.5, visibleSize.height / 2 + origin.y + 91.5));
    this->addChild(hh1);
    auto h3 = Sprite::create("image/h1.png");
    h3->setPosition(Vec2(visibleSize.width / 2 + origin.x - 2.5, visibleSize.height / 2 + origin.y + 91.5));
    this->addChild(h3);
    auto hh2 = Sprite::create("image/hh.png");
    hh2->setPosition(Vec2(visibleSize.width / 2 + origin.x - 50.5, visibleSize.height / 2 + origin.y - 7.5));
    this->addChild(hh2);
    auto h4 = Sprite::create("image/h1.png");
    h4->setPosition(Vec2(visibleSize.width / 2 + origin.x - 2.5, visibleSize.height / 2 + origin.y - 7.5));
    this->addChild(h4);
    auto h5 = Sprite::create("image/h1.png");
    h5->setPosition(Vec2(visibleSize.width / 2 + origin.x + 95, visibleSize.height / 2 + origin.y + 91.5));
    this->addChild(h5);
    auto hh3 = Sprite::create("image/hh.png");
    hh3->setPosition(Vec2(visibleSize.width / 2 + origin.x + 47, visibleSize.height / 2 + origin.y - 7.5));
    this->addChild(hh3);
    auto hh4 = Sprite::create("image/hh.png");
    hh4->setPosition(Vec2(visibleSize.width / 2 + origin.x + 47, visibleSize.height / 2 + origin.y + 91.5));
    this->addChild(hh4);
    auto h6 = Sprite::create("image/h1.png");
    h6->setPosition(Vec2(visibleSize.width / 2 + origin.x + 95, visibleSize.height / 2 + origin.y - 7.5));
    this->addChild(h6);
    auto w1 = Sprite::create("image/v1.png");
    w1->setPosition(Vec2(visibleSize.width / 2 + origin.x - 50.5, visibleSize.height / 2 + origin.y + 141));
    this->addChild(w1);
    auto w2 = Sprite::create("image/v1.png");
    w2->setPosition(Vec2(visibleSize.width / 2 + origin.x - 50.5, visibleSize.height / 2 + origin.y + 42));
    this->addChild(w2);
    auto w3 = Sprite::create("image/v1.png");
    w3->setPosition(Vec2(visibleSize.width / 2 + origin.x - 50.5, visibleSize.height / 2 + origin.y - 57));
    this->addChild(w3);
    auto w4 = Sprite::create("image/v1.png");
    w4->setPosition(Vec2(visibleSize.width / 2 + origin.x + 48.5, visibleSize.height / 2 + origin.y + 141));
    this->addChild(w4);
    auto w5 = Sprite::create("image/v1.png");
    w5->setPosition(Vec2(visibleSize.width / 2 + origin.x + 48.5, visibleSize.height / 2 + origin.y + 42));
    this->addChild(w5);
    auto w6 = Sprite::create("image/v1.png");
    w6->setPosition(Vec2(visibleSize.width / 2 + origin.x + 48.5, visibleSize.height / 2 + origin.y - 57));
    this->addChild(w6);
    auto p1 = Sprite::create("image/w1.png");
    p1->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100, visibleSize.height / 2 + origin.y - 200));
    this->addChild(p1);
    auto p2 = Sprite::create("image/w2.png");
    p2->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 200));
    this->addChild(p2);
    auto p3 = Sprite::create("image/w3.png");
    p3->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y - 200));
    this->addChild(p3);
    __String* OScore = __String::createWithFormat("%i", o_win);
    cocos2d::Label* o_Win = Label::createWithTTF(OScore->getCString(), "fonts/Marker Felt.ttf", visibleSize.height * 0.07);
    o_Win->setColor(Color3B::BLACK);
    o_Win->setPosition(Vec2(visibleSize.width / 2 + origin.x - 50, visibleSize.height / 2 + origin.y - 200));
    this->addChild(o_Win, 10000);

    __String* XScore = __String::createWithFormat("%i", x_win);
    cocos2d::Label* x_Win = Label::createWithTTF(XScore->getCString(), "fonts/Marker Felt.ttf", visibleSize.height * 0.07);
    x_Win->setColor(Color3B::BLACK);
    x_Win->setPosition(Vec2(visibleSize.width / 2 + origin.x + 50, visibleSize.height / 2 + origin.y - 200));
    this->addChild(x_Win, 10000);


    __String* DScore = __String::createWithFormat("%i", s_draw);
    cocos2d::Label* D_Score = Label::createWithTTF(DScore->getCString(), "fonts/Marker Felt.ttf", visibleSize.height * 0.07);
    D_Score->setColor(Color3B::BLACK);
    D_Score->setPosition(Vec2(visibleSize.width / 2 + origin.x + 140, visibleSize.height / 2 + origin.y - 200));
    this->addChild(D_Score, 10000);

}
