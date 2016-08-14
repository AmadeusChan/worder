#ifndef GET_EXAM_STRATEGY_H
#define GET_EXAM_STRATEGY_H

#include <vector>
#include "Word.h"
using namespace std;

class GetExamStrategy
{
public:
	virtual vector<Word*> get_exam(int problem_number) = 0;
};

#endif