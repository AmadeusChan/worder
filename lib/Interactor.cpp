#include "Interactor.h"
#include "MyException.h"
#include <iostream>

using namespace std;

Interactor::Interactor(ViewerDisplayer* _m_viewer_displayer, WordBank<WordImpl>* _m_word_bank_, User* _m_user_) : m_viewer_displayer_(_m_viewer_displayer), m_word_bank_(_m_word_bank_), m_user_(_m_user_) {}

void Interactor::start()
{
		while(1)
	{
#ifdef _WIN32
		system("cls");
#else
		system("clear");
#endif
		cout << m_viewer_displayer_->show() << endl;
		string command;
		getline(cin, command);
		if (command == "-exit")
		{
			try
			{
				m_user_->save();
				m_word_bank_->save();
			}
			catch (MyException exception)
			{
				cout << exception.what() << endl;
			}
			break;
		}
		m_viewer_displayer_->submit(command);
	}
}