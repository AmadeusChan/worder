#ifndef EXAM_TOOL_H
#define EXAM_TOOL_H

#include "ViewerImpl.h"
#include "WordBank.h"
#include "WordImpl.h"
#include "User.h"
#include "GetExamStrategy.h"

class ExamTool : public ViewerImpl
{
	GetExamStrategy* m_get_exam_strategy_;
	vector<Word*> test_paper_;
	int problem_num_, test_score_;
	bool testing_;
	Word* current_word_;

protected:
	void init_page();
	string get_head_page();

public:
	ExamTool(WordBank<WordImpl>* _m_word_bank_, User* _m_user_, GetExamStrategy* _m_get_exam_strategy_);
	Viewer* submit(string command);

	~ExamTool();
};

#endif