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
	void printWords(const unsigned int value,int length);
	void hideAllWords();
	//맨 뒤의 한개의 word를 visible로 바꾼다.
	void showWord();

	CREATE_FUNC(SomaWordViewer);
};

class SomaWordManager : public cocos2d::Ref
{
	unsigned int currentQuestion;
	float wordShowTime;
	float correctWaitTime;
	int wordLength;
	int level;

	//맞춘개수
	int numberOfCorrect;
public:
	unsigned int getCurrentQuestion() const;
	float getCurrentWordShowTime() const;
	float getCurrentWaitTime() const;
	float getCurrentLength() const;

	bool isCorrect(const int value);
	//다 맞췃니?
	bool isAllCorrect();

	void refresh();

	bool init();
	CREATE_FUNC(SomaWordManager);
};