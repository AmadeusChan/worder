#ifndef WORD_PICKER_STRATEGY
#define WORD_PICKER_STRATEGY

#include <vector>
#include "User.h"
#include "UserWordImpl.h"
using namespace std;

class WordPickerStrategy
{
public:
	virtual vector<UserWordImpl*> pick_words(User* user) = 0;
};

#endif