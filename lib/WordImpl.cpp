#include "WordImpl.h"

WordImpl::WordImpl(string _context_, string _interpretation_) : context_(_context_), interpretation_(_interpretation_) {}

string WordImpl::get_context()
{
	return context_;
}

string WordImpl::get_interpretation()
{
	return interpretation_;
}

string WordImpl::convert_data_to_string()
{
	string context = "";
	context += context_ + '\n';
	context += interpretation_ + '\n';
	return context;
}

void WordImpl::convert_string_to_data(string context)
{
	stringstream ss;
	ss << context;
	ss >> context_;
	ss >> interpretation_;
}
