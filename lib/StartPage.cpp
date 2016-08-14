#include "StartPage.h"
#include "MyException.h"
#include <sstream>

using namespace std;

StartPage* StartPage::instance_ = NULL;

StartPage::StartPage(WordBank<WordImpl>* _m_word_bank_, User* _m_user_) : ViewerImpl(_m_word_bank_, _m_user_) { init_page(); }

StartPage* StartPage::get_instance(WordBank<WordImpl>* _m_word_bank_, User* _m_user_)
{
	if (instance_ == NULL)
	{
		instance_ = new StartPage(_m_word_bank_, _m_user_);
	}
	return instance_;
}

StartPage* StartPage::get_instance()
{
	if (instance_ == NULL)
	{
		throw MyException("not constructed.");
	}
	return instance_;
}

void StartPage::init_page()
{
	stringstream ans;
	for (int i = 0; i < static_cast<int>(tools_.size()); ++i)
	{
		ans << i << ". " <<  tools_[i].first;
		if (i < static_cast<int>(tools_.size()) - 1)
			ans << '\n';
	}
	current_page_ = ans.str();
}

void StartPage::add_tool(string tool_name, Viewer* pViewer)
{
	tools_.push_back(make_pair(tool_name, pViewer));
	init_page();
}

string StartPage::get_head_page()
{
	string str;
	str = "Welcome to wordcademy, "; 
	str += m_user_->get_user_name() + "\n\nInput [tool number] to use tool.\n\nThe following two command can be used in any page:\nInput -exit to exit windows.\nInput -home to return this page.\n\n";
	vector<UserWordImpl*> temp_words = (m_user_->get_user_word_bank())->get_words();
	int cnt_words = 0;
	for (int i = 0; i < static_cast<int>(temp_words.size()); ++i) 	
		cnt_words += temp_words[i]->skilled();
	stringstream ss;
	string temp_str;
	ss << (m_word_bank_->get_words()).size();
	ss >> temp_str;
	str += temp_str + ((m_word_bank_->get_words()).size() >= 2 ? " Words" : " Word") + '\n';
	ss.clear();
	ss << cnt_words;
	ss >> temp_str;
	str += temp_str + (cnt_words < 2 ? " Word" : " Words") + " mastered";
	return str;
}

Viewer* StartPage::submit(string _command)
{
	stringstream command;
	command << _command;
	int option;
	if (!(command >> option) || option >= static_cast<int>(tools_.size()) || option < 0)
		throw MyException("illegal tool number");
	return tools_[option].second;
}

StartPage::~StartPage()
{
	delete instance_;
}
