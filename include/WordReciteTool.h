#ifndef WORD_RECITE_TOOL
#define WORD_RECITE_TOOL

#include "ViewerImpl.h"
#include "WordBank.h"
#include "WordImpl.h"
#include "User.h"
#include "WordPickerStrategy.h"

class WordReciteTool : public ViewerImpl
{
	UserWordImpl* current_word_;
	MemoryStrategy* m_memory_strategy_;
	WordPickerStrategy* m_word_picker_strategy_;

	bool reciting_;
	int problem_num_;
	vector<UserWordImpl*> recite_paper_;

	void start_new_round();

protected:
	void init_page();
	string get_head_page();

public:
	WordReciteTool(WordPickerStrategy* _m_word_picker_strategy_, MemoryStrategy* _m_memory_strategy_, WordBank<WordImpl>* _m_word_bank_, User* _m_user_);
	Viewer* submit(string command);
};

#endif