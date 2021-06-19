#include "GameSceneOne.h"
#include "GameSceneTwo.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
bool isCheck = true;
Scene* GameSceneTwo::createScene()
{
    return GameSceneTwo::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool GameSceneTwo::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    //auto closeItem = MenuItemImage::create(
    //    "CloseNormal.png",
    //    "CloseSelected.png",
    //    CC_CALLBACK_1(GameSceneOne::menuCloseCallback, this));

    //if (closeItem == nullptr ||
    //    closeItem->getContentSize().width <= 0 ||
    //    closeItem->getContentSize().height <= 0)
    //{
    //    problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    //}
    //else
    //{
    //    float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
    //    float y = origin.y + closeItem->getContentSize().height / 2;
    //    closeItem->setPosition(Vec2(x, y));
    //}

    //// create menu, it's an autorelease object
    //auto menu = Menu::create(closeItem, NULL);
    //menu->setPosition(Vec2::ZERO);
    //this->addChild(menu, 1);

    ///////////////////////////////
    //// 3. add your codes below...

    //// add a label shows "Hello World"
    //// create and initialize a label

    //auto label = Label::createWithTTF("TicTacToe", "fonts/Marker Felt.ttf", 24);
    //if (label == nullptr)
    //{
    //    problemLoading("'fonts/Marker Felt.ttf'");
    //}
    //else
    //{
    //    // position the label on the center of the screen
    //    label->setPosition(Vec2(origin.x + visibleSize.width / 2,
    //        origin.y + visibleSize.height - label->getContentSize().height));

    //    // add the label as a child to this layer
    //    this->addChild(label, 1);
    //}

    // add "HelloWorld" splash screen"
    auto background = Sprite::create("image/bg.png");
    background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(background, 0);
    /*auto twoPlayers = Sprite::create("image/reset.png");
    twoPlayers->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 220));
    this->addChild(twoPlayers, 0);*/

    auto playItemOne = MenuItemImage::create("image/reset1.png", "image/reset1.png", CC_CALLBACK_1(GameSceneTwo::GotoGameSceneOne, this));
    playItemOne->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2 -150);
    auto onePlayer = Menu::create(playItemOne, NULL);
    onePlayer->setPosition(Point::ZERO);
    this->addChild(onePlayer);
    auto touchListen = EventListenerTouchOneByOne::create();
    touchListen->onTouchBegan = [](Touch* touch, Event* event) { return true;};
    touchListen->onTouchMoved = [](Touch* touch, Event* event) {};
    touchListen->onTouchEnded = [=](Touch* touch, Event* event) {
        auto x = touch->getLocation().x;
        auto y = touch->getLocation().y;
        auto ex = Sprite::create("image/ex.png");
        auto oh = Sprite::create("image/oh.png");
        if (isCheck) {
            if (x >= 0 && x <= 109.5 && y <= 448.5 && y >= 346.5) {
                ex->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100, visibleSize.height / 2 + origin.y + 150));
                this->addChild(ex);
                isCheck = false;
            }
            if (x >= 0 && x <= 109.5 && y < 346.5 && y >= 262.5) {
                ex->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100, visibleSize.height / 2 + origin.y + 50));
                this->addChild(ex);
                isCheck = false;
            }
            if (x >= 0 && x <= 109.5 && y < 262.5 && y >= 178.5) {
                ex->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100, visibleSize.height / 2 + origin.y - 50));
                this->addChild(ex);
                isCheck = false;
            }
            if (x > 109.5 && x <= 193.5 && y <= 448.5 && y >= 346.5) {
                ex->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 150));
                this->addChild(ex);
                isCheck = false;
            }
            if (x > 109.5 && x <= 193.5 && y < 346.5 && y >= 262.5) {
                ex->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 50));
                this->addChild(ex);
                isCheck = false;
            }
            if (x > 109.5 && x <= 193.5 && y < 262.5 && y >= 178.5) {
                ex->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 50));
                this->addChild(ex);
                isCheck = false;
            }
            if (x >= 193.5 && x <= 278 && y <= 448.5 && y >= 346.5) {
                ex->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 150));
                this->addChild(ex);
                isCheck = false;
            }
            if (x >= 193.5 && x <= 278 && y < 346.5 && y >= 262.5) {
                ex->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 50));
                this->addChild(ex);
                isCheck = false;
            }
            if (x >= 193.5 && x <= 278 && y < 262.5 && y >= 178.5) {
                ex->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y - 50));
                this->addChild(ex);
                isCheck = false;
            }
        }
        else {
            if (x >= 0 && x <= 109.5 && y <= 448.5 && y >= 346.5) {
                oh->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100, visibleSize.height / 2 + origin.y + 150));
                this->addChild(oh);
                isCheck = true;
            }
            if (x >= 0 && x <= 109.5 && y < 346.5 && y >= 262.5) {
                oh->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100, visibleSize.height / 2 + origin.y + 50));
                this->addChild(oh);
                isCheck = true;
            }
            if (x >= 0 && x <= 109.5 && y < 262.5 && y >= 178.5) {
                oh->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100, visibleSize.height / 2 + origin.y - 50));
                this->addChild(oh);
                isCheck = false;
            }
            if (x > 109.5 && x <= 193.5 && y <= 448.5 && y >= 346.5) {
                oh->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 150));
                this->addChild(oh);
                isCheck = true;
            }
            if (x > 109.5 && x <= 193.5 && y < 346.5 && y >= 262.5) {
                oh->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 50));
                this->addChild(oh);
                isCheck = true;
            }
            if (x > 109.5 && x <= 193.5 && y < 262.5 && y >= 178.5) {
                oh->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 50));
                this->addChild(oh);
                isCheck = true;
            }
            if (x >= 193.5 && x <= 278 && y <= 448.5 && y >= 346.5) {
                oh->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 150));
                this->addChild(oh);
                isCheck = true;
            }
            if (x >= 193.5 && x <= 278 && y < 346.5 && y >= 262.5) {
                oh->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 50));
                this->addChild(oh);
                isCheck = true;
            }
            if (x >= 193.5 && x <= 278 && y < 262.5 && y >= 178.5) {
                oh->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y - 50));
                this->addChild(oh);
                isCheck = true;
            }
        }
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListen, this);





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
    return true;
}


void GameSceneTwo::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}

void GameSceneTwo::GotoGameSceneOne(cocos2d::Ref* pSender) {
    auto scene = GameSceneOne::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(1.0f, scene));
}