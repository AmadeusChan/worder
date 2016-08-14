#include "WordReciteTool.h"
#include "MyException.h"

WordReciteTool::WordReciteTool(WordPickerStrategy* _m_word_picker_strategy_, MemoryStrategy* _m_memory_strategy_, WordBank<WordImpl>* _m_word_bank_, User* _m_user_) : m_word_picker_strategy_(_m_word_picker_strategy_), m_memory_strategy_(_m_memory_strategy_), ViewerImpl(_m_word_bank_, _m_user_) 
{ 
	init_page();
}

void WordReciteTool::init_page()
{
	current_page_ = "";
	reciting_ = false;
	problem_num_ = 0;
	current_word_ = NULL;
}

string WordReciteTool::get_head_page()
{
	string page = "*Word Recite Tool*\n\n";
	if (!reciting_)
		page += "Input -start to start reciting.\n";
	page += "Input y when you remembers the word, otherwise input n.\n";
	page += "Input s to show the word's meaning if you are not sure.";
	return page;
}

Viewer* WordReciteTool::submit(string command)
{
	if (command == "-home") 
	{
		init_page();
		return NULL;
	}
	else
	{
		if (reciting_)
		{
			if (command == "y" || command == "n")
			{
				if (command == "y")
					current_word_->refresh_storage(true);
				else
					current_word_->refresh_storage(false);
				problem_num_ += 1;
				if (problem_num_ == static_cast<int>(recite_paper_.size()))
				{
					recite_paper_ = m_word_picker_strategy_->pick_words(m_user_);
					if (static_cast<int>(recite_paper_.size()) == 0)
					{
						current_word_ = NULL;
						current_page_ = "You have finished the recitation, congratulations!";
						reciting_ = false;
					}
					else
					{
						problem_num_ = 0;
						current_word_ = recite_paper_[0];
					}
				}
				else
				{
					current_word_ = recite_paper_[problem_num_];
				}
			}
			else
			if (command == "s")
			{
				current_page_ = "Word: " + current_word_->get_context() + '\n' + "Interpretation: " + current_word_->get_interpretation();
			}
			else
			{
				throw MyException("unknown command");
			}
		}
		else
		{
			if (command == "-start")
			{
				init_page();
				recite_paper_ = m_word_picker_strategy_->pick_words(m_user_);
				if (static_cast<int>(recite_paper_.size()) == 0)
					throw MyException("no word needed to recite.");
				reciting_ = true;
				problem_num_ = 0;
				current_word_ = recite_paper_[0];
			}
			else
			{
				throw MyException("unknown command");
			}
		}
		if (current_word_ != NULL && command != "s")
		{
			current_page_ = "Word: " + current_word_->get_context();
		}
	}
	return this;
}
