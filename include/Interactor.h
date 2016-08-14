#ifndef INTERACTOR_H
#define INTERACTOR_H

#include "ViewerDisplayer.h"
#include "Viewer.h"
#include "WordBank.h"
#include "WordImpl.h"
#include "User.h"
#include <cstdlib>

class Interactor
{
	ViewerDisplayer* m_viewer_displayer_;
	WordBank<WordImpl>* m_word_bank_;
	User* m_user_;

public:
	Interactor(ViewerDisplayer* _m_viewer_displayer_, WordBank<WordImpl>* _m_word_bank_, User* _m_user_);
	void start();
};

#endif
