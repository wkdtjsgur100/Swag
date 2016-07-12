#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "SomaManager.h"

class HelloWorld : public cocos2d::Layer
{
	SomaWordViewer* somaWordViewer;
	int score;
	cocos2d::Label* score_label;
	cocos2d::ProgressTimer* timer;
	float fTime;
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
	void addScore(int delta);
    void menuCloseCallback(cocos2d::Ref* pSender);
	void setTimerPercent(float percent);
	void refreshQuestion();

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
