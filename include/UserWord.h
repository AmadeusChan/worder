#ifndef USER_WORD_H
#define USER_WORD_H

#include <string>
#include <vector>
#include "WordImpl.h"
using namespace std;

class UserWord : public WordImpl
{
public:
	UserWord(string _context_, string _interpretation_);
	virtual bool get_in_memorizing_wordlist() = 0;
	virtual void set_in_memorizing_wordlist(bool _in_memorizing_wordlist) = 0;
	virtual void* get_memory_storage() = 0;
	virtual vector<string> get_sample_sentences() = 0;
	virtual void add_sample_sentence(string sample_sentence) = 0;
	virtual void refresh_storage(bool right) = 0;
	virtual bool skilled() = 0;
};

#endif