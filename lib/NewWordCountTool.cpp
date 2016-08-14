#include "NewWordCountTool.h"
#include "MyException.h"

NewWordCountTool::NewWordCountTool(WordBank<WordImpl>* _m_word_bank_, User* _m_user_, OperateFileStrategy* _m_operate_file_strategy_) : ViewerImpl(_m_word_bank_, _m_user_), m_operate_file_strategy_(_m_operate_file_strategy_)
{ 
	init_page();
	m_user_word_bank_ = _m_user_->get_user_word_bank();
}

void NewWordCountTool::init_page() 
{
	current_page_ = "";
	read_file_ = false;
	write_file_ = false;
}

string NewWordCountTool::get_head_page()
{
	string page = "*New Word Count*\n\n";
	if (!read_file_)
		page += "Input [filename] to count new words in this article.";
	else
		page += "Input -text or -file [filename] to decide the output mode.";
	return page;
}

bool NewWordCountTool::judge_alphabet(char ch) 
{
	if(ch >= 'A' && ch <= 'Z') return true;
	if(ch >= 'a' && ch <= 'z') return true;
	if(ch == '-') return true;
	return false;
}

bool NewWordCountTool::judge_word_bank(string str)
{
	return (m_user_word_bank_->find_word_by_context(str) == NULL || (m_user_word_bank_->find_word_by_context(str))->skilled() == false) && map_new_word_.find(str) == map_new_word_.end() && m_word_bank_->find_word_by_context(str) != NULL;
}

Viewer* NewWordCountTool::submit(string command)
{
	if (command == "-home") 
	{
		init_page();
		return NULL;
	}
	if(!read_file_)
	{
		string text = m_operate_file_strategy_->read_file(command) + '\n';
		int word_begin = 0;
		string word_to_be_find;
		bool find_initial = true;
		for (int i = 0; i < static_cast<int>(text.length()); i++)
		{
			if(!find_initial)
			{
				if(judge_alphabet(text[i]))
				{
					word_begin = i;
					find_initial = true;
				}
				continue;
			}
			if (!judge_alphabet(text[i]))
			{
				find_initial = false;
				word_to_be_find = text.substr(word_begin, i - word_begin);
				if(judge_word_bank(word_to_be_find))
				{	
					map_new_word_.insert( pair<string,string> (word_to_be_find, (m_word_bank_->find_word_by_context(word_to_be_find))->get_interpretation()) );
					continue;
				}
				word_to_be_find[0] = tolower(word_to_be_find[0]);
				if(judge_word_bank(word_to_be_find))
					map_new_word_.insert( pair<string,string> (word_to_be_find, (m_word_bank_->find_word_by_context(word_to_be_find))->get_interpretation()) );
			}
		}
		current_page_ = "";
		read_file_ = true;
		return this;
	}
	if(command == "-text")
		write_file_ = false;
	else if(command.substr(0,5) == "-file") 
	{
		if(command.length() > 6)
			write_file_ = true;
		else
			throw MyException("please input the [filename] for output after -file");
	}
	else
		throw MyException("unknown command");
	stringstream ss;
	ss << map_new_word_.size();
	ss >> current_page_;
	current_page_ += " new word(s) in all:\n\n";
	for (auto i = map_new_word_.begin(); i != map_new_word_.end(); i++)
		current_page_ += i->first + '\n' + i->second + '\n';
	map_new_word_.clear();
	if(write_file_)
	{
		m_operate_file_strategy_->write_file(command.substr(6), current_page_);
		current_page_ = "Success!";
	}
	read_file_ = false;
	return this;
}
