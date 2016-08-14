#ifndef USERNAME_READER
#define USERNAME_READER

#include <string>
using namespace std;

class UsernameReader
{
	bool check_c(char c);
	bool check(string username);
public:
	string read();
};

#endif