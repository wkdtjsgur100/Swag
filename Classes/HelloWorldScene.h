#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "SomaManager.h"

class HelloWorld : public cocos2d::Layer
{
	SomaWordViewer* somaWordViewer;
	SomaWordManager* swagManager;
	int score;
	cocos2d::Label* score_label;
	cocos2d::ProgressTimer* timer;
	float fTime;

	cocos2d::ui::Button* btn_so;
	cocos2d::ui::Button* btn_ma;
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
	void addScore(int delta);
    void menuCloseCallback(cocos2d::Ref* pSender);
	void setTimerPercent(float percent);

	//timerType : 0 이면 보여주는 상태, 1이면 맞추는 상태
	void changeTimerType(int timerType);

	void refreshQuestion();
	void update(float dt);
	void gameOver();

	void correctCheck(int type);
	void correctWord();
	void uncorrectWord();

	void imgEffect(std::string path);
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
