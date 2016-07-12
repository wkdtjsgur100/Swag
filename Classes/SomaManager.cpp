#include "SomaManager.h"

USING_NS_CC;

bool SomaWordViewer::init()
{
	if(!Node::init())
		return false;

	return true;
}

void SomaWordViewer::printWords(const unsigned int value)
{
	unsigned int cpy_value = value;

	this->removeAllChildren();

	Vec2 start_pos = Vec2(50,630);

	for (int i = 0; i < 4;i++)
	{
		for (int j = 0; j < 7; j++)
		{
			Sprite* newSpr;

			if ((cpy_value & 1) == 0)
				newSpr = Sprite::create("font_so.png");
			else
				newSpr = Sprite::create("font_ma.png");

			Size sprSize = newSpr->getContentSize();
			newSpr->setPosition(start_pos.x + j*sprSize.width, start_pos.y - i*sprSize.height);

			addChild(newSpr);
			cpy_value >>= 1; 
			
			if (cpy_value == 0)
				goto outLoop;
		}
	}
outLoop:
	return;
}

void SomaWordViewer::hideWords()
{
	for (const auto& child : _children)
		child->setVisible(false);
}

unsigned int SomaWordManager::getCurrentQuestion() const
{
	return currentQuestion;
}

float SomaWordManager::getCurrentWordShowTime() const
{
	return wordShowTime;
}

float SomaWordManager::getCurrentWaitTime() const
{
	return correctWaitTime;
}

void SomaWordManager::levelUp()
{

}

bool SomaWordManager::init()
{
	wordShowTime = 2.0f;
	correctWaitTime = 20.0f;
	wordLength = 4;
}

