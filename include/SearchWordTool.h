#ifndef SEARCH_WORD_TOOL_H
#define SEARCH_WORD_TOOL_H

#include "ViewerImpl.h"
#include "WordBank.h"
#include "WordImpl.h"
#include "User.h"

class SearchWordTool : public ViewerImpl
{
	WordImpl* current_word_;
	MemoryStrategy* m_memory_strategy_;

protected:
	void init_page();
	string get_head_page();

public:
	SearchWordTool(WordBank<WordImpl>* _m_word_bank_, User* _m_user_, MemoryStrategy* _m_memory_strategy_);
	Viewer* submit(string command);
};

#endif