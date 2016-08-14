#ifndef START_PAGE_H
#define START_PAGE_H

#include "ViewerImpl.h"
#include "WordBank.h"
#include "WordImpl.h"
#include "User.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class StartPage : public ViewerImpl
{
	vector<pair<string, Viewer*>> tools_;
	static StartPage* instance_;

protected:
	StartPage(WordBank<WordImpl>* _m_word_bank_, User* _m_user_);
	void init_page();
	string get_head_page();

public:
	static StartPage* get_instance(WordBank<WordImpl>* _m_word_bank_, User* _m_user_);
	static StartPage* get_instance();

	void add_tool(string tool_name, Viewer* pViewer);
	Viewer* submit(string command);

	~StartPage();
};

#endif