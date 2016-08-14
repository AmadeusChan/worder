#ifndef WORD_PICKER_STRATEGY_BY_MEMORY_CURVE
#define WORD_PICKER_STRATEGY_BY_MEMORY_CURVE

#include "WordPickerStrategy.h"

class WordPickerStrategyByMemoryCurve : public WordPickerStrategy
{
public:
	vector<UserWordImpl*> pick_words(User* user);
};

#endif