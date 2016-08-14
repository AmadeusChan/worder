#include "WordPickerStrategyByMemoryCurve.h"
#include "MemoryStrategyByMemoryCurveStorage.h"
#include <ctime>

vector<UserWordImpl*> WordPickerStrategyByMemoryCurve::pick_words(User* user)
{
	vector<UserWordImpl*> ans;
	WordBankImpl<UserWordImpl>* user_word_bank = user->get_user_word_bank();
	vector<UserWordImpl*> words = user_word_bank->get_words();
	int current_time = static_cast<int>(time(0));
	for (int i = 0; i < static_cast<int>(words.size()); ++i)
		if (words[i]->get_in_memorizing_wordlist())
		{
			MemoryStrategyByMemoryCurveStorage* storage = (MemoryStrategyByMemoryCurveStorage*)words[i]->get_memory_storage();
			if (storage->next_recite_time_ <= current_time)
				ans.push_back(words[i]);
		} 
	return ans;
}
