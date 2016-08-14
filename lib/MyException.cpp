#include "MyException.h"

MyException::MyException(string _message_) : message_(_message_) {}

string MyException::what()
{
	return message_;
}
