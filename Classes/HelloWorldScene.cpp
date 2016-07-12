#include "HelloWorldScene.h"

USING_NS_CC;
using namespace ui;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();

    auto sprite = Sprite::create("game_background.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
	auto btn_so = Button::create("btn_so.png");
	btn_so->setPosition(Vec2(130, 150));
	btn_so->setZoomScale(0.7f);
	addChild(btn_so);

	auto btn_ma = Button::create("btn_ma.png");
	btn_ma->setPosition(Vec2(350, 150));
	btn_ma->setZoomScale(0.7f); 
	addChild(btn_ma);

	timer = ProgressTimer::create(Sprite::create("timer.png"));

	timer->setType(ProgressTimer::Type::BAR);
	timer->setBarChangeRate(Vec2(1, 0));
	timer->setMidpoint(Vec2(0, 1));
	timer->setPosition(visibleSize.width*0.5, 700);

	fTime = 20.0f;			//제한시간 20초

	timer->stopAllActions();

	setTimerPercent(100.0f);

	addChild(timer, 5);

	//score view
	score_label = Label::createWithTTF("0", "fonts/font.ttf", 50.0f,Size::ZERO);

	score_label->setColor(Color3B::BLACK);
	score_label->setPosition(visibleSize.width / 2+70, 750);

	addChild(score_label);

	score = 0;

	somaWordViewer = SomaWordViewer::create();
	
	addChild(somaWordViewer);

	somaWordViewer->printWords(1251025);

    return true;
}

void HelloWorld::setTimerPercent(float percent)
{
	timer->stopAllActions();

	timer->setPercentage(percent);

	auto *progressToZero = ProgressFromTo::create(fTime*(percent / 100.0f), percent, 0);

	timer->runAction(progressToZero);
}

void HelloWorld::refreshQuestion()
{

}

void HelloWorld::addScore(int delta)
{
	score += delta;
	score_label->setString(StringUtils::format("%d", score));
}
void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
