#ifndef NEW_WORD_COUNT_TOOL_H
#define NEW_WORD_COUNT_TOOL_H

#include "ViewerImpl.h"
#include "WordBank.h"
#include "WordImpl.h"
#include "User.h"
#include <map>
using namespace std;

class NewWordCountTool : public ViewerImpl
{
	WordBankImpl<UserWordImpl>* m_user_word_bank_;
	OperateFileStrategy* m_operate_file_strategy_;
	map<string, string> map_new_word_;
	bool judge_alphabet(char ch);
	bool judge_word_bank(string str);
	bool read_file_;
	bool write_file_;

protected:
	void init_page();
	string get_head_page();

public:
	NewWordCountTool(WordBank<WordImpl>* _m_word_bank_, User* _m_user_, OperateFileStrategy* _m_operate_file_strategy_);
	Viewer* submit(string command);
};

#endif