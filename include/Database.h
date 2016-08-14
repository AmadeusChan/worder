#ifndef DATABASE_H
#define DATABASE_H

#include <string>
using namespace std;

class Database
{
public:
	virtual void save() = 0;
	virtual void load() = 0;
};

#endif