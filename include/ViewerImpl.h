#ifndef VIEWER_IMPL_H
#define VIEWER_IMPL_H

#include "Viewer.h"
#include "WordBank.h"
#include "WordImpl.h"
#include "User.h"


class ViewerImpl : public Viewer
{
protected:
	virtual string get_head_page() = 0;

	WordBank<WordImpl>* m_word_bank_;
	User* m_user_;
	string current_page_;
    virtual void init_page() = 0;

public:
	virtual string show();
	ViewerImpl(WordBank<WordImpl>* _m_word_bank_, User* _m_user_);
};

#endif