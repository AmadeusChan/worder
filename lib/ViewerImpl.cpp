#include "ViewerImpl.h"

ViewerImpl::ViewerImpl(WordBank<WordImpl>* _m_word_bank_, User* _m_user_) 
	: m_word_bank_(_m_word_bank_), m_user_(_m_user_) {}

string ViewerImpl::show()
{
	string page = get_head_page() + "\n";
	if (current_page_ != "")
		page += "\n" + current_page_ + "\n";
	return page;
}
