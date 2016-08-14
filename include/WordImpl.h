#ifndef WORD_IMPL_H
#define WORD_IMPL_H

#include <string>
#include <sstream>
#include "Word.h"
using namespace std;

class WordImpl : public Word
{
protected:
	string context_;
	string interpretation_;

public:
	WordImpl(string _context_ = "", string _interpretation_ = "");
	string get_context();
	string get_interpretation();

	string convert_data_to_string();
	void convert_string_to_data(string context);
};

#endif
