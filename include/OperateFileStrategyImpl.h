#ifndef OPERATE_FILE_STRATEGY_IMPL_H
#define OPERATE_FILE_STRATEGY_IMPL_H

#include <string>
#include <iostream>
#include <fstream>
#include "OperateFileStrategy.h"
using namespace std;

class OperateFileStrategyImpl : public OperateFileStrategy
{
public:
	string read_file(string file_name);
	void write_file(string file_name, string context);
};

#endif