#ifndef USER_WORD_IMPL_H
#define USER_WORD_IMPL_H

#include <string>
#include <vector>
#include "UserWord.h"
#include "MemoryStrategy.h"
using namespace std;

class UserWordImpl : public UserWord
{
	bool in_memorizing_wordlist_;
	void* memory_storage_;
	vector<string> sample_sentences_;
	MemoryStrategy* m_memory_strategy_;

public:
	UserWordImpl(MemoryStrategy* _m_memory_strategy_, string _context_ = "", string _interpretation_ = "");
	bool get_in_memorizing_wordlist();
	void set_in_memorizing_wordlist(bool _in_memorizing_wordlist);
	void* get_memory_storage();
	vector<string> get_sample_sentences();
	void add_sample_sentence(string sample_sentence);
	void refresh_storage(bool right);
	bool skilled();

	string convert_data_to_string();
	void convert_string_to_data(string context);
};

#endif
