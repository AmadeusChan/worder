#include "UserWordImpl.h"

UserWordImpl::UserWordImpl(MemoryStrategy* _m_memory_strategy_, string _context_, string _interpretation_) : m_memory_strategy_(_m_memory_strategy_), UserWord(_context_, _interpretation_), memory_storage_(NULL), in_memorizing_wordlist_(false) 
{
	m_memory_strategy_->init_storage(memory_storage_);
}

bool UserWordImpl::get_in_memorizing_wordlist()
{
	return in_memorizing_wordlist_;
}

void UserWordImpl::set_in_memorizing_wordlist(bool _in_memorizing_wordlist)
{
	in_memorizing_wordlist_ = _in_memorizing_wordlist;
}

void* UserWordImpl::get_memory_storage() 
{ 
	return memory_storage_; 
}

vector<string> UserWordImpl::get_sample_sentences() 
{ 
	return sample_sentences_; 
}

void UserWordImpl::add_sample_sentence(string sample_sentence) 
{
	sample_sentences_.push_back(sample_sentence);
}

void UserWordImpl::refresh_storage(bool right) 
{
	m_memory_strategy_->refresh_storage(memory_storage_, right);
}

bool UserWordImpl::skilled()
{
	return m_memory_strategy_->skilled(memory_storage_);
}

string UserWordImpl::convert_data_to_string()
{
	string context = context_ + '\n' + interpretation_ + '\n' + (in_memorizing_wordlist_ ? "1" : "0") + '\n';
	string temp_s = m_memory_strategy_->convert_storage_to_string(memory_storage_);
	context += temp_s + '\n';
	for (int i = 0; i < static_cast<int>(sample_sentences_.size()); i++)
		context += sample_sentences_[i] + '\n';
	return context;
}

void UserWordImpl::convert_string_to_data(string context)
{
	stringstream ss;
	string storage_data;
	string in_memorizing_wordlist_data;
	ss << context;
	ss >> context_;
	ss >> interpretation_;
	ss >> in_memorizing_wordlist_data;
	in_memorizing_wordlist_ = (in_memorizing_wordlist_data == "1");
	getline(ss, storage_data); 
	getline(ss, storage_data); 
	m_memory_strategy_->init_storage(memory_storage_);
	m_memory_strategy_->convert_string_to_storage(memory_storage_, storage_data);
	string temp_s;
	sample_sentences_.clear();
	while (!ss.eof())
	{
		ss >> temp_s;
		if (!ss.eof())
			sample_sentences_.push_back(temp_s);
	}
}
