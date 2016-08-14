#ifndef USER_H
#define USER_H

#include <string>
#include "DatabaseImpl.h"
#include "UserWordImpl.h"
#include "WordBankImpl.h"

class User : public DatabaseImpl
{
public:
	User(OperateFileStrategy* _m_operate_file_strategy_, string _path_);
	virtual WordBankImpl<UserWordImpl>* get_user_word_bank() = 0;

	virtual void put_search_history(string search_command) = 0;
	virtual vector<string> get_search_history(int start, int num) = 0;
	virtual string get_user_name() = 0;
};

#endif