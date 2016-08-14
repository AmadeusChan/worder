#ifndef ADD_WORD_TOOL_H
#define ADD_WORD_TOOL_H

#include "ViewerImpl.h"
#include "WordBank.h"
#include "WordImpl.h"
#include "OperateFileStrategyImpl.h"
#include <sstream>

using namespace std ; 

class AddWordTool : public ViewerImpl 
{
protected:
	void init_page(); 
	string get_head_page();
	void add_word(string word_in_string) ;

public :
	AddWordTool(WordBank<WordImpl>* _m_word_bank_, User* _m_user_);
	Viewer* submit(string command); 
};
#endif
