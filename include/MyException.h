#ifndef MY_EXCEPTION_H
#define MY_EXCEPTION_H

#include <string>
using namespace std;

class MyException
{
	string message_;
public:
	MyException(string _message_);
	string what();
};

#endif
