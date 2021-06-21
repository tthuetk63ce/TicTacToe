#include "GameSceneOne.h"
#include "GameSceneTwo.h"
#include "PlayerWinScene.h"
#include "SimpleAudioEngine.h"
#include "AI.h"
using namespace std;
USING_NS_CC;
int isCheckOne;
int x_win, o_win, ox_draw;
int board[9] = { 0 };
int k;
AI* aI;



Scene* GameSceneOne::createScene()
{
    return GameSceneOne::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
// on "init" you need to initialize your instance
bool GameSceneOne::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto background = Sprite::create("image/bg.png");
    background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(background, 0);
    /*auto twoPlayers = Sprite::create("image/reset.png");
    twoPlayers->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 220));
    this->addChild(twoPlayers, 0);
    auto playItemTwo = MenuItemImage::create("image/reset.png", "image/reset.png", CC_CALLBACK_1(GameSceneOne::GotoGameSceneTwo, this));
    playItemTwo->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2 - 150);
    auto twoPlayers = Menu::create(playItemTwo, NULL);
    twoPlayers->setPosition(Point::ZERO);
    this->addChild(twoPlayers);*/
    /*if (isCheckOne==-1) {
        auto xPlayer = Sprite::create("image/xp.png");
        xPlayer->setPosition(Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y + 220));
        this->addChild(xPlayer);
    }
    else if (isCheckOne == 1) {
        auto oPlayer = Sprite::create("image/op.png");
        oPlayer->setPosition(Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y + 220));
        this->addChild(oPlayer);
    };*/

    auto touchListen = EventListenerTouchOneByOne::create();
    touchListen->onTouchBegan = [](Touch* touch, Event* event) {return true;};
    touchListen->onTouchMoved = [](Touch* touch, Event* event) {};
    touchListen->onTouchEnded = [=](Touch* touch, Event* event) {
        float x = touch->getLocation().x;
        float y = touch->getLocation().y;
        k = GameSceneOne::checkXY(x, y);
        if (board[k] == 0) {
            board[k] = -1;
            GameSceneOne::playerDraw(k, board[k]);
            if (aI->win(board) == 0) {
                int x = aI->computerMove(board);
                board[x] = 1;
                GameSceneOne::playerDraw(x, board[x]);
                CCLOG("%d %d\n", k, x);
            }
            else _eventDispatcher->removeEventListener(touchListen);
        }
        else _eventDispatcher->removeEventListener(touchListen);
        switch (aI->win(board))
        {
        case 0:
            isCheckOne=0;
            CCLOG("%d\n", isCheckOne);
            break;
        case 1:
            isCheckOne = 1;
            this->scheduleOnce(schedule_selector(GameSceneOne::RestartScene), 0.5f);
            break;
        case -1:
            isCheckOne = -1;
            this->scheduleOnce(schedule_selector(GameSceneOne::RestartScene), 0.5f);
            break;
        }
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListen, this);


    //touchListen->onTouchEnded = [=](Touch* touch, Event* event) {
    //    auto ex = Sprite::create("image/ex.png");
    //    auto oh = Sprite::create("image/oh.png");
    //    //if (aI->win(board)==0) {
    //    //    if (isCheckOne == -1) {
    //    //        if (x >= 0 && x <= 109.5 && y <= 448.5 && y >= 346.5 && board[0] == 0) {
    //    //            board[0] = -1;
    //    //            ex->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100, visibleSize.height / 2 + origin.y + 150));
    //    //            this->addChild(ex);
    //    //            CCLOG("%d", aI->computerMove(board));
    //    //            isCheckOne = 1;
    //    //        }
    //    //        else if (x >= 0 && x <= 109.5 && y < 346.5 && y >= 262.5 && board[3] == 0) {
    //    //            board[3] = -1;
    //    //            ex->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100, visibleSize.height / 2 + origin.y + 50));
    //    //            this->addChild(ex);
    //    //            CCLOG("%d", aI->computerMove(board));
    //    //            isCheckOne = 1;
    //    //        }
    //    //        else if (x >= 0 && x <= 109.5 && y < 262.5 && y >= 178.5 && board[6] == 0) {
    //    //            board[6] = -1;
    //    //            ex->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100, visibleSize.height / 2 + origin.y - 50));
    //    //            this->addChild(ex);
    //    //            CCLOG("%d", aI->computerMove(board));
    //    //            isCheckOne = 1;
    //    //        }
    //    //        else if (x > 109.5 && x <= 193.5 && y <= 448.5 && y >= 346.5 && board[1] == 0) {
    //    //            board[1] = -1;
    //    //            ex->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 150));
    //    //            this->addChild(ex);
    //    //            CCLOG("%d", aI->computerMove(board));
    //    //            isCheckOne = 1;
    //    //        }
    //    //        else if (x > 109.5 && x <= 193.5 && y < 346.5 && y >= 262.5 && board[4] == 0) {
    //    //            board[4] = -1;
    //    //            ex->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 50));
    //    //            this->addChild(ex);
    //    //            CCLOG("%d", aI->computerMove(board));
    //    //            isCheckOne = 1;
    //    //        }
    //    //        else if (x > 109.5 && x <= 193.5 && y < 262.5 && y >= 178.5 && board[7] == 0) {
    //    //            board[7] = -1;
    //    //            ex->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 50));
    //    //            this->addChild(ex);
    //    //            CCLOG("%d", aI->computerMove(board));
    //    //            isCheckOne = 1;
    //    //        }
    //    //        else if (x >= 193.5 && x <= 278 && y <= 448.5 && y >= 346.5 && board[2] == 0) {
    //    //            board[2] = -1;
    //    //            ex->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 150));
    //    //            this->addChild(ex);
    //    //            CCLOG("%d", aI->computerMove(board));
    //    //            isCheckOne = 1;
    //    //        }
    //    //        else if (x >= 193.5 && x <= 278 && y < 346.5 && y >= 262.5 && board[5] == 0) {
    //    //            board[5] = -1;
    //    //            ex->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 50));
    //    //            this->addChild(ex);
    //    //            CCLOG("%d", aI->computerMove(board));
    //    //            isCheckOne = 1;
    //    //        }
    //    //        else if (x >= 193.5 && x <= 278 && y < 262.5 && y >= 178.5 && board[8] == 0) {
    //    //            board[8] = -1;
    //    //            ex->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y - 50));
    //    //            this->addChild(ex);
    //    //            CCLOG("%d", aI->computerMove(board));
    //    //            isCheckOne = 1;
    //    //        }

    //    //    }
    //    //    /*else {
    //    //        if (aI->computerMove(board) == 0 && board[aI->computerMove(board)]==0) {
    //    //            board[aI->computerMove(board)] = 1;
    //    //            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100, visibleSize.height / 2 + origin.y + 150));
    //    //            this->addChild(oh);
    //    //            isCheckOne = -1;
    //    //        }
    //    //        if (aI->computerMove(board) == 1 && board[aI->computerMove(board)] == 0) {
    //    //            board[aI->computerMove(board)] = 1;
    //    //            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 150));
    //    //            this->addChild(oh);
    //    //            isCheckOne = -1;
    //    //        }
    //    //        if (aI->computerMove(board) == 2 && board[aI->computerMove(board)] == 0) {
    //    //            board[aI->computerMove(board)] = 1;
    //    //            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 150));
    //    //            this->addChild(oh);
    //    //            isCheckOne = -1;
    //    //        }
    //    //        if (aI->computerMove(board) == 3 && board[aI->computerMove(board)] == 0) {
    //    //            board[aI->computerMove(board)] = 1;
    //    //            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100, visibleSize.height / 2 + origin.y + 50));
    //    //            this->addChild(oh);
    //    //            isCheckOne = -1;
    //    //        }
    //    //        if (aI->computerMove(board) == 4 && board[aI->computerMove(board)] == 0) {
    //    //            board[aI->computerMove(board)] = 1;
    //    //            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 50));
    //    //            this->addChild(oh);
    //    //            isCheckOne = -1;
    //    //        }
    //    //        if (aI->computerMove(board) == 5 && board[aI->computerMove(board)] == 0) {
    //    //            board[aI->computerMove(board)] = 1;
    //    //            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 50));
    //    //            this->addChild(oh);
    //    //            isCheckOne = -1;
    //    //        }
    //    //        if (aI->computerMove(board) == 6 && board[aI->computerMove(board)] == 0) {
    //    //            board[aI->computerMove(board)] = 1;
    //    //            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100, visibleSize.height / 2 + origin.y - 50));
    //    //            this->addChild(oh);
    //    //            isCheckOne = -1;
    //    //        }
    //    //        if (aI->computerMove(board) == 7 && board[aI->computerMove(board)] == 0) {
    //    //            board[aI->computerMove(board)] = 1;
    //    //            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 50));
    //    //            this->addChild(oh);
    //    //            isCheckOne = -1;
    //    //        }
    //    //        if (aI->computerMove(board) == 8 && board[aI->computerMove(board)] == 0) {
    //    //            board[aI->computerMove(board)] = 1;
    //    //            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y - 50));
    //    //            this->addChild(oh);
    //    //            isCheckOne = -1;
    //    //        }
    //    //    
    //    //    }*/
    //    //}
    //    /*else {
    //        if (x >= 0 && x <= 109.5 && y <= 448.5 && y >= 346.5 && board[0][0] == 0) {
    //            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100, visibleSize.height / 2 + origin.y + 150));
    //            this->addChild(oh);
    //            board[0][0] = 2;
    //        }
    //        if (x >= 0 && x <= 109.5 && y < 346.5 && y >= 262.5 && board[1][0] == 0) {
    //            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100, visibleSize.height / 2 + origin.y + 50));
    //            this->addChild(oh);
    //            board[1][0] = 2;
    //        }
    //        if (x >= 0 && x <= 109.5 && y < 262.5 && y >= 178.5 && board[2][0] == 0) {
    //            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100, visibleSize.height / 2 + origin.y - 50));
    //            this->addChild(oh);
    //            board[2][0] = 2;
    //        }
    //        if (x > 109.5 && x <= 193.5 && y <= 448.5 && y >= 346.5 && board[0][1] == 0) {
    //            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 150));
    //            this->addChild(oh);
    //            board[0][1] = 2;
    //        }
    //        if (x > 109.5 && x <= 193.5 && y < 346.5 && y >= 262.5 && board[1][1] == 0) {
    //            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 50));
    //            this->addChild(oh);
    //            board[1][1] = 2;
    //        }
    //        if (x > 109.5 && x <= 193.5 && y < 262.5 && y >= 178.5 && board[2][1] == 0) {
    //            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 50));
    //            this->addChild(oh);
    //            board[2][1] = 2;
    //        }
    //        if (x >= 193.5 && x <= 278 && y <= 448.5 && y >= 346.5 && board[0][2] == 0) {
    //            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 150));
    //            this->addChild(oh);
    //            board[0][2] = 2;
    //        }
    //        if (x >= 193.5 && x <= 278 && y < 346.5 && y >= 262.5 && board[1][2] == 0) {
    //            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 50));
    //            this->addChild(oh);
    //            board[1][2] = 2;
    //        }
    //        if (x >= 193.5 && x <= 278 && y < 262.5 && y >= 178.5 && board[2][2] == 0) {
    //            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y - 50));
    //            this->addChild(oh);
    //            board[2][2] = 2;
    //        }
    //        isCheckOne = true;
    //    }*/
    //    /*if (isCheckOne == 1) {
    //        if (aI->computerMove(board) == 0) {
    //            board[aI->computerMove(board)] = 1;
    //            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100, visibleSize.height / 2 + origin.y + 150));
    //            this->addChild(oh);
    //            isCheckOne = -1;
    //        }
    //        if (aI->computerMove(board) == 1) {
    //            board[aI->computerMove(board)] = 1;
    //            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 150));
    //            this->addChild(oh);
    //            isCheckOne = -1;
    //        }
    //        if (aI->computerMove(board) == 2) {
    //            board[aI->computerMove(board)] = 1;
    //            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 150));
    //            this->addChild(oh);
    //            isCheckOne = -1;
    //        }
    //        if (aI->computerMove(board) == 3) {
    //            board[aI->computerMove(board)] = 1;
    //            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100, visibleSize.height / 2 + origin.y + 50));
    //            this->addChild(oh);
    //            isCheckOne = -1;
    //        }
    //        if (aI->computerMove(board) == 4) {
    //            board[aI->computerMove(board)] = 1;
    //            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 50));
    //            this->addChild(oh);
    //            isCheckOne = -1;
    //        }
    //        if (aI->computerMove(board) == 5) {
    //            board[aI->computerMove(board)] = 1;
    //            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 50));
    //            this->addChild(oh);
    //            isCheckOne = -1;
    //        }
    //        if (aI->computerMove(board) == 6) {
    //            board[aI->computerMove(board)] = 1;
    //            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100, visibleSize.height / 2 + origin.y - 50));
    //            this->addChild(oh);
    //            isCheckOne = -1;
    //        }
    //        if (aI->computerMove(board) == 7) {
    //            board[aI->computerMove(board)] = 1;
    //            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 50));
    //            this->addChild(oh);
    //            isCheckOne = -1;
    //        }
    //        if (aI->computerMove(board) == 8) {
    //            board[aI->computerMove(board)] = 1;
    //            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y - 50));
    //            this->addChild(oh);
    //            isCheckOne = -1;
    //        }
    //    }*/

    //    if (isCheckOne==1) {
    //        auto xPlayer = Sprite::create("image/xp.png");
    //        xPlayer->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 220));
    //        this->addChild(xPlayer);
    //    }
    //    else  if (isCheckOne == -1) {
    //        auto oPlayer = Sprite::create("image/op.png");
    //        oPlayer->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 220));
    //        this->addChild(oPlayer);
    //    };
    //    /*if (isCheckOne==1) {
    //        isCheckOne = -1;
    //        this->scheduleOnce(schedule_selector(GameSceneOne::AI),0.5f);
    //    }*/
    //    /*if ((board[0][0] == 1 && board[0][0] == board[0][1] && board[0][1] == board[0][2]) ||
    //        (board[0][0] == 1 && board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
    //        (board[0][0] == 1 && board[0][0] == board[1][0] && board[1][0] == board[2][0]) ||
    //        (board[1][0] == 1 && board[1][0] == board[1][1] && board[1][1] == board[1][2]) ||
    //        (board[2][0] == 1 && board[2][0] == board[2][1] && board[2][1] == board[2][2]) ||
    //        (board[0][2] == 1 && board[0][2] == board[1][2] && board[1][2] == board[2][2]) ||
    //        (board[0][2] == 1 && board[0][2] == board[1][1] && board[1][1] == board[2][0]) ||
    //        (board[0][1] == 1 && board[0][1] == board[1][1] && board[1][1] == board[2][1])) {
    //        _state = "x_win";
    //    }
    //    else if ((board[0][0] == 2 && board[0][0] == board[0][1] && board[0][1] == board[0][2]) ||
    //        (board[0][0] == 2 && board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
    //        (board[0][0] == 2 && board[0][0] == board[1][0] && board[1][0] == board[2][0]) ||
    //        (board[1][0] == 2 && board[1][0] == board[1][1] && board[1][1] == board[1][2]) ||
    //        (board[2][0] == 2 && board[2][0] == board[2][1] && board[2][1] == board[2][2]) ||
    //        (board[0][2] == 2 && board[0][2] == board[1][2] && board[1][2] == board[2][2]) ||
    //        (board[0][2] == 2 && board[0][2] == board[1][1] && board[1][1] == board[2][0]) ||
    //        (board[0][1] == 2 && board[0][1] == board[1][1] && board[1][1] == board[2][1])) {
    //            {
    //                _state = "x_win";
    //            }
    //    }*/

    //};
    
    // xử lý hình ảnh
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
    /*__String* OScore = __String::createWithFormat("%i", o_win);
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
    this->addChild(D_Score, 10000);*/
    this->scheduleUpdate();
    return true;
    
}

int GameSceneOne::checkXY(float x, float y) {
    int _b;
    if (x >= 0 && x <= 109.5 && y <= 448.5 && y >= 346.5) { _b = 0;  return _b; }
    if (x >= 0 && x <= 109.5 && y < 346.5 && y >= 262.5) {_b = 3; return _b;}
    if (x >= 0 && x <= 109.5 && y < 262.5 && y >= 178.5){_b = 6;return _b; }
    if (x > 109.5 && x <= 193.5 && y <= 448.5 && y >= 346.5 ) {_b = 1;return _b; }
    if (x > 109.5 && x <= 193.5 && y < 346.5 && y >= 262.5 ) {_b = 4;return _b; }
    if (x > 109.5 && x <= 193.5 && y < 262.5 && y >= 178.5 ) {_b = 7;return _b; }
    if (x >= 193.5 && x <= 278 && y <= 448.5 && y >= 346.5 ) {_b = 2;return _b; }
    if (x >= 193.5 && x <= 278 && y < 346.5 && y >= 262.5 ) {_b = 5;return _b; }
    if (x >= 193.5 && x <= 278 && y < 262.5 && y >= 178.5 ){ _b = 8;return _b; }

}

void GameSceneOne::playerDraw(int k, int x) {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto oh = Sprite::create("image/oh.png");
    auto ex = Sprite::create("image/ex.png");
        if (k == 0 && x == -1) {
            ex->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100, visibleSize.height / 2 + origin.y + 150));
            this->addChild(ex);
        }
        if (k == 0 && x == 1) {
            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100, visibleSize.height / 2 + origin.y + 150));
            this->addChild(oh);
        }
        if (k == 1 && x == -1) {
            ex->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 150));
            this->addChild(ex);

        }
        if (k == 1 && x == 1) {
            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 150));
            this->addChild(oh);

        }
        if (k == 2 && x == -1) {
            ex->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 150));
            this->addChild(ex);
        }
        if (k == 2 && x == 1) {
            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 150));
            this->addChild(oh);
        }
        if (k == 3 && x == -1) {
            ex->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100, visibleSize.height / 2 + origin.y + 50));
            this->addChild(ex);
        }
        if (k == 3 && x == 1) {
            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100, visibleSize.height / 2 + origin.y + 50));
            this->addChild(oh);
        }
        if (k == 4 && x == -1) {
            ex->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 50));
            this->addChild(ex);
        }
        if (k == 4 && x == 1) {
            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 50));
            this->addChild(oh);
        }
        if (k == 5 && x == -1) {
            ex->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 50));
            this->addChild(ex);
        }
        if (k == 5 && x == 1) {
            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 50));
            this->addChild(oh);
        }
        if (k == 6 && x == -1) {
            ex->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100, visibleSize.height / 2 + origin.y - 50));
            this->addChild(ex);
        }
        if (k == 6 && x == 1) {
            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100, visibleSize.height / 2 + origin.y - 50));
            this->addChild(oh);
        }
        if (k == 7 && x == -1) {
            ex->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 50));
            this->addChild(ex);
        }
        if (k == 7 && x == 1) {
            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 50));
            this->addChild(oh);
        }
        if (k == 8 && x == -1) {
            ex->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y - 50));
            this->addChild(ex);
        }
        if (k == 8 && x == 1) {
            oh->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y - 50));
            this->addChild(oh);
        }
}

void GameSceneOne::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}

void GameSceneOne::GotoGameSceneTwo(cocos2d::Ref* pSender) {
    auto scene = GameSceneTwo::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(1.0f, scene));
}

void GameSceneOne::RestartScene(float dt) {
    auto scene = PlayerWinScene::createScene(isCheckOne);
    Director::getInstance()->replaceScene(TransitionFade::create(0.5f, scene));
}

void GameSceneOne::update(float up) {
    /*if ((board[0][0] == 1 && board[0][0] == board[0][1] && board[0][1] == board[0][2]) ||
        (board[0][0] == 1 && board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][0] == 1 && board[0][0] == board[1][0] && board[1][0] == board[2][0]) ||
        (board[1][0] == 1 && board[1][0] == board[1][1] && board[1][1] == board[1][2]) ||
        (board[2][0] == 1 && board[2][0] == board[2][1] && board[2][1] == board[2][2]) ||
        (board[0][2] == 1 && board[0][2] == board[1][2] && board[1][2] == board[2][2]) ||
        (board[0][2] == 1 && board[0][2] == board[1][1] && board[1][1] == board[2][0]) ||
        (board[0][1] == 1 && board[0][1] == board[1][1] && board[1][1] == board[2][1]))
        x_win++;
    else if ((board[0][0] == 2 && board[0][0] == board[0][1] && board[0][1] == board[0][2]) ||
        (board[0][0] == 2 && board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][0] == 2 && board[0][0] == board[1][0] && board[1][0] == board[2][0]) ||
        (board[1][0] == 2 && board[1][0] == board[1][1] && board[1][1] == board[1][2]) ||
        (board[2][0] == 2 && board[2][0] == board[2][1] && board[2][1] == board[2][2]) ||
        (board[0][2] == 2 && board[0][2] == board[1][2] && board[1][2] == board[2][2]) ||
        (board[0][2] == 2 && board[0][2] == board[1][1] && board[1][1] == board[2][0]) ||
        (board[0][1] == 2 && board[0][1] == board[1][1] && board[1][1] == board[2][1]))
        o_win++;
    else s_draw++;*/
};

//void GameSceneOne::LoadPlayScene() {
//    auto visibleSize = Director::getInstance()->getVisibleSize();
//    Vec2 origin = Director::getInstance()->getVisibleOrigin();
//    auto h1 = Sprite::create("image/h1.png");
//    h1->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100, visibleSize.height / 2 + origin.y + 91.5));
//    this->addChild(h1);
//    auto h2 = Sprite::create("image/h1.png");
//    h2->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100, visibleSize.height / 2 + origin.y - 7.5));
//    this->addChild(h2);
//    auto hh1 = Sprite::create("image/hh.png");
//    hh1->setPosition(Vec2(visibleSize.width / 2 + origin.x - 50.5, visibleSize.height / 2 + origin.y + 91.5));
//    this->addChild(hh1);
//    auto h3 = Sprite::create("image/h1.png");
//    h3->setPosition(Vec2(visibleSize.width / 2 + origin.x - 2.5, visibleSize.height / 2 + origin.y + 91.5));
//    this->addChild(h3);
//    auto hh2 = Sprite::create("image/hh.png");
//    hh2->setPosition(Vec2(visibleSize.width / 2 + origin.x - 50.5, visibleSize.height / 2 + origin.y - 7.5));
//    this->addChild(hh2);
//    auto h4 = Sprite::create("image/h1.png");
//    h4->setPosition(Vec2(visibleSize.width / 2 + origin.x - 2.5, visibleSize.height / 2 + origin.y - 7.5));
//    this->addChild(h4);
//    auto h5 = Sprite::create("image/h1.png");
//    h5->setPosition(Vec2(visibleSize.width / 2 + origin.x + 95, visibleSize.height / 2 + origin.y + 91.5));
//    this->addChild(h5);
//    auto hh3 = Sprite::create("image/hh.png");
//    hh3->setPosition(Vec2(visibleSize.width / 2 + origin.x + 47, visibleSize.height / 2 + origin.y - 7.5));
//    this->addChild(hh3);
//    auto hh4 = Sprite::create("image/hh.png");
//    hh4->setPosition(Vec2(visibleSize.width / 2 + origin.x + 47, visibleSize.height / 2 + origin.y + 91.5));
//    this->addChild(hh4);
//    auto h6 = Sprite::create("image/h1.png");
//    h6->setPosition(Vec2(visibleSize.width / 2 + origin.x + 95, visibleSize.height / 2 + origin.y - 7.5));
//    this->addChild(h6);
//    auto w1 = Sprite::create("image/v1.png");
//    w1->setPosition(Vec2(visibleSize.width / 2 + origin.x - 50.5, visibleSize.height / 2 + origin.y + 141));
//    this->addChild(w1);
//    auto w2 = Sprite::create("image/v1.png");
//    w2->setPosition(Vec2(visibleSize.width / 2 + origin.x - 50.5, visibleSize.height / 2 + origin.y + 42));
//    this->addChild(w2);
//    auto w3 = Sprite::create("image/v1.png");
//    w3->setPosition(Vec2(visibleSize.width / 2 + origin.x - 50.5, visibleSize.height / 2 + origin.y - 57));
//    this->addChild(w3);
//    auto w4 = Sprite::create("image/v1.png");
//    w4->setPosition(Vec2(visibleSize.width / 2 + origin.x + 48.5, visibleSize.height / 2 + origin.y + 141));
//    this->addChild(w4);
//    auto w5 = Sprite::create("image/v1.png");
//    w5->setPosition(Vec2(visibleSize.width / 2 + origin.x + 48.5, visibleSize.height / 2 + origin.y + 42));
//    this->addChild(w5);
//    auto w6 = Sprite::create("image/v1.png");
//    w6->setPosition(Vec2(visibleSize.width / 2 + origin.x + 48.5, visibleSize.height / 2 + origin.y - 57));
//    this->addChild(w6);
//    auto p1 = Sprite::create("image/w1.png");
//    p1->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100, visibleSize.height / 2 + origin.y - 200));
//    this->addChild(p1);
//    auto p2 = Sprite::create("image/w2.png");
//    p2->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 200));
//    this->addChild(p2);
//    auto p3 = Sprite::create("image/w3.png");
//    p3->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y - 200));
//    this->addChild(p3);
//    __String* OScore = __String::createWithFormat("%i", o_win);
//    cocos2d::Label* o_Win = Label::createWithTTF(OScore->getCString(), "fonts/Marker Felt.ttf", visibleSize.height * 0.07);
//    o_Win->setColor(Color3B::BLACK);
//    o_Win->setPosition(Vec2(visibleSize.width / 2 + origin.x - 50, visibleSize.height / 2 + origin.y - 200));
//    this->addChild(o_Win, 10000);
//
//    __String* XScore = __String::createWithFormat("%i", x_win);
//    cocos2d::Label* x_Win = Label::createWithTTF(XScore->getCString(), "fonts/Marker Felt.ttf", visibleSize.height * 0.07);
//    x_Win->setColor(Color3B::BLACK);
//    x_Win->setPosition(Vec2(visibleSize.width / 2 + origin.x + 50, visibleSize.height / 2 + origin.y - 200));
//    this->addChild(x_Win, 10000);
//
//
//    __String* DScore = __String::createWithFormat("%i", s_draw);
//    cocos2d::Label* D_Score = Label::createWithTTF(DScore->getCString(), "fonts/Marker Felt.ttf", visibleSize.height * 0.07);
//    D_Score->setColor(Color3B::BLACK);
//    D_Score->setPosition(Vec2(visibleSize.width / 2 + origin.x + 140, visibleSize.height / 2 + origin.y - 200));
//    this->addChild(D_Score, 10000);
//}