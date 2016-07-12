#pragma once

#include "cocos2d.h"

/*
	�Ҹ� ���ڵ��� �����ִ� Ŭ����
*/
class SomaWordViewer : public cocos2d::Node
{
public:
	bool init() override;

	//value ���� ���� '��' �Ǵ� '��'�� ���ʴ�� ����Ѵ�.
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