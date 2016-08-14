#ifndef GET_EXAM_STRATEGY_BY_RANDOM_H
#define GET_EXAM_STRATEGY_BY_RANDOM_H

#include "GetExamStrategy.h"
#include "WordBank.h"
#include "WordImpl.h"
#include "User.h"
#include <ctime>
#include <cstdlib>

class GetExamStrategyByRandom : public GetExamStrategy
{
	WordBank<WordImpl>* m_word_bank_;
	User* m_user_;

public:
	GetExamStrategyByRandom(WordBank<WordImpl>* _m_word_bank_, User* _m_user_);
	virtual vector<Word*> get_exam(int problem_number);
};

#endif
