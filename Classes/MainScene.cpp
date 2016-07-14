#include "MainScene.h"
#include "SimpleAudioEngine.h"
#include "HelloWorldScene.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "platform/android/jni/JniHelper.h"
#endif

USING_NS_CC;
using namespace ui;
using namespace CocosDenshion;

Scene* MainScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MainScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto sprite = Sprite::create("main/background.png");

	// position the sprite on the center of the screen
	sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);

	auto gameStartLabel = Label::createWithTTF("GAME START", "fonts/font.ttf", 40.0f);
	gameStartLabel->setColor(Color3B::BLACK);

	auto gameStartMenuitem = MenuItemLabel::create(gameStartLabel, [&](Ref* sender) {
		auto scene = TransitionPageTurn::create(1.0f, HelloWorld::createScene(), false);
		Director::getInstance()->replaceScene(scene);
	});

	auto rankingLabel = Label::createWithTTF("RANK", "fonts/font.ttf", 40.0f);
	rankingLabel->setColor(Color3B::BLACK);

	auto rankingMenuitem = MenuItemLabel::create(rankingLabel);

	auto fbLoginMenuitem = MenuItemImage::create("main/facebook_connect_button.png", "main/facebook_connect_button.png",
		[](Ref* sender) {
		/*
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
				JniMethodInfo t;

				if (JniHelper::getStaticMethodInfo(t
					, "org/cocos2dx/cpp/AppActivity"       //com/ext/AdGame <-까지가 패키지 명이고 그 뒤가 자바 파일 이름
					, "facebookLogin"    //<- 함수이름
					, "()V"))
				{
					// 함수 호출
					t.env->CallStaticVoidMethod(t.classID, t.methodID);
					// Release
					t.env->DeleteLocalRef(t.classID);
				}
#endif
		*/

	});

	fbLoginMenuitem->setScale(0.7f);
	auto main_menu = Menu::create(gameStartMenuitem, rankingMenuitem, fbLoginMenuitem, nullptr);

	main_menu->setPosition(visibleSize.width / 2, visibleSize.height / 2 - 200);

	main_menu->alignItemsVerticallyWithPadding(10);

	addChild(main_menu);

    return true;
}
