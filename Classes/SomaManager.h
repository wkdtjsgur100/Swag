#pragma once

#include "cocos2d.h"

/*
	소마 글자들을 보여주는 클래스
*/
class SomaWordViewer : public cocos2d::Node
{
public:
	bool init() override;

	//value 값에 따라 '소' 또는 '마'를 차례대로 출력한다.
	void printWords(const unsigned int value);
	void hideWords();

	CREATE_FUNC(SomaWordViewer);
};

class SomaWordManager : public cocos2d::Ref
{
	unsigned int currentQuestion;
	float wordShowTime;
	float correctWaitTime;
	int wordLength;
public:
	unsigned int getCurrentQuestion() const;
	float getCurrentWordShowTime() const;
	float getCurrentWaitTime() const;

	void levelUp();

	bool init();
	CREATE_FUNC(SomaWordManager);
};