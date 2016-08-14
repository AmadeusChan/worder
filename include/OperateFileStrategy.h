#ifndef OPERATE_FILE_STRATEGY_H
#define OPERATE_FILE_STRATEGY_H

#include <string>
using namespace std;

class OperateFileStrategy
{
public:
	virtual string read_file(string file_name) = 0;
	virtual void write_file(string file_name, string context) = 0;
};

#endif