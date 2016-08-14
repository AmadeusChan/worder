#include "SearchWordTool.h"
#include "MyException.h"

SearchWordTool::SearchWordTool(WordBank<WordImpl>* _m_word_bank_, User* _m_user_, MemoryStrategy* _m_memory_strategy_) 
	: ViewerImpl(_m_word_bank_, _m_user_), m_memory_strategy_(_m_memory_strategy_) 
{ 
	init_page(); 
}

void SearchWordTool::init_page()
{
	current_word_ = NULL;
	current_page_ = "";
}

string SearchWordTool::get_head_page()
{
	string page = "*Search Word Tool*\n\nInput [word] to search this word\nInput -history to watch search history.";
	if (current_word_ != NULL)
	{
		page += "\n";
		page += "Input \'-add [sentence]\' to add sample sentence for this word.\n";
		page += "Input \'-recite\' to add this word to memorizing wordlist.";
	}
	return page;
}

Viewer* SearchWordTool::submit(string command)
{
	if (command == "-home") 
	{
		init_page();
		return NULL;
	}
	else
	if (command == "-history")
	{
		current_page_ = "Search history for latest 10 words:\n";
		vector<string> temp_histories = m_user_->get_search_history(0, 10);
		for (int i = 0; i < static_cast<int>(temp_histories.size()); ++i)
		{
			current_page_ += temp_histories[i];
			if (i < static_cast<int>(temp_histories.size()) - 1)
				current_page_ += '\n';
		}
	}
	else
	if (command == "-recite")
	{
		if (current_word_ == NULL)
		{
			throw MyException("search a word first please");
		}
		else
		{
			UserWord* user_word = m_user_->get_user_word_bank()->find_word_by_context(current_word_->get_context());
			if (user_word == NULL)
			{
				m_user_->get_user_word_bank()->add_word(UserWordImpl(m_memory_strategy_, current_word_->get_context(), current_word_->get_interpretation()));
				user_word = m_user_->get_user_word_bank()->find_word_by_context(current_word_->get_context());
			}
			user_word->set_in_memorizing_wordlist(true);
			
			submit(current_word_->get_context());
			current_page_ += "\n\nSuccess!";
		}
	}
	else
	if ((command.substr(0, 5)) == "-add ")
	{
		if (current_word_ == NULL)
		{
			throw MyException("search a word first please");
		}
		else
		{
			UserWord* user_word = m_user_->get_user_word_bank()->find_word_by_context(current_word_->get_context());
			if (user_word == NULL)
			{
				m_user_->get_user_word_bank()->add_word(UserWordImpl(m_memory_strategy_, current_word_->get_context(), current_word_->get_interpretation()));
				user_word = m_user_->get_user_word_bank()->find_word_by_context(current_word_->get_context());
			}
			string temp_sentence = command.substr(5, command.length());
			user_word->add_sample_sentence(temp_sentence);
			submit(current_word_->get_context());
			current_page_ += "\n\nSuccess!";
		}
	}
	else
	{
		current_page_ = "";
		m_user_->put_search_history(command);
		current_word_ = m_word_bank_->find_word_by_context(command);
		if (current_word_ == NULL)
			throw MyException("word not found");
		else
		{
			current_page_ = "Word: " + current_word_->get_context() + '\n'
						 + "Interpretation: " + current_word_->get_interpretation() + '\n';
			UserWord* user_word = m_user_->get_user_word_bank()->find_word_by_context(command);
			if (user_word != NULL)
			{
				vector<string> temp_sample_sentences = user_word->get_sample_sentences();
				if (static_cast<int>(temp_sample_sentences.size()) > 0)
				{
					current_page_ += "Sample Sentences:\n";
					for (int i = 0; i < static_cast<int>(temp_sample_sentences.size()); ++i)
					{
						current_page_ += temp_sample_sentences[i];
						if (i < static_cast<int>(temp_sample_sentences.size()) - 1)
							current_page_ += '\n';
					}
				}
			}
		}
	}
	return this;
}
