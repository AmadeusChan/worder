#ifndef USER_IMPL_H
#define USER_IMPL_H

#include <string>
#include "User.h"
#include "DatabaseImpl.h"
#include "UserWordImpl.h"
#include "WordBankImpl.h"
#include "WordSetByMap.h"
#include "MemoryStrategy.h"

class UserImpl : public User
{
	WordBankImpl<UserWordImpl> word_bank_;
	string user_name_;
	vector<string> search_history_list_;
	MemoryStrategy* m_memory_strategy_;

public:
	UserImpl(MemoryStrategy* _m_memory_strategy_, OperateFileStrategy* _m_operate_file_strategy_, string _path_, string _user_name_);

	string convert_data_to_string();
	void convert_string_to_data(string context);
	
	void put_search_history(string search_history);
	vector<string> get_search_history(int start, int num);
	string get_user_name();

	WordBankImpl<UserWordImpl>* get_user_word_bank();
};

#endif