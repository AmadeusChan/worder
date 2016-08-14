#ifndef WORD_H
#define WORD_H

#include <string>
#include "DatabaseImpl.h"
using namespace std;

class Word : public DatabaseImpl 
{
public:
	virtual string get_context() = 0;
	virtual string get_interpretation() = 0;
};

#endif
