#include "GetExamStrategyByRandom.h"

GetExamStrategyByRandom::GetExamStrategyByRandom(WordBank<WordImpl>* _m_word_bank_, User* _m_user_) : m_word_bank_(_m_word_bank_), m_user_(_m_user_) {}

vector<Word*> GetExamStrategyByRandom::get_exam(int problem_number)
{
	vector<UserWordImpl*> temp_wordbank_ = (m_user_->get_user_word_bank())->get_words();
	vector<UserWordImpl*> temp_wordbank;
	for (int i = 0; i < static_cast<int>(temp_wordbank_.size()); ++i)
		if (temp_wordbank_[i]->get_in_memorizing_wordlist())
			temp_wordbank.push_back(temp_wordbank_[i]);

	srand(static_cast<unsigned int>(time(0)));
	for (int i = 1; i < static_cast<int>(temp_wordbank.size()); i++)
	{
		int j = rand() % i;
		swap(temp_wordbank[i], temp_wordbank[j]);
	}
	vector<Word*> examination_paper;
	for (int i = 0; i < min(problem_number, static_cast<int>(temp_wordbank.size())); i++)
		examination_paper.push_back(temp_wordbank[i]);
	return examination_paper;
}
