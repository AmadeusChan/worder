#include "UsernameReader.h"
#include "iostream"

bool UsernameReader::check_c(char c)
{
	return ((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')) || ((c >= '0') && (c <= '9')) || c == '_';
}

bool UsernameReader::check(string username)
{
	for (int i = 0; i < static_cast<int>(username.length()); ++i)
		if (!check_c(username[i]))
			return false;
	return true;
}

string UsernameReader::read()
{
	while (true)
	{	
		cout << "Input your username please:" << endl;
		string username;
		getline(cin, username);
		if (check(username)) 
		{
			return username;
		}
#ifdef _WIN32
		system("cls");
#else
		system("clear");
#endif
		cout << "[username can only consist alphabet, number or underline]" << endl;
	}
}