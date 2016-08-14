#ifndef DATABASE_IMPL_H
#define DATABASE_IMPL_H

#include <string>
#include "Database.h"
#include "OperateFileStrategy.h"

class DatabaseImpl : public Database
{
	string path_;
	const bool OPERATEABLE_;
	OperateFileStrategy* m_operate_file_strategy_;

public:
	DatabaseImpl(OperateFileStrategy* _m_operate_file_strategy_, string _path_);
	DatabaseImpl();

	virtual string convert_data_to_string() = 0;
	virtual void convert_string_to_data(string context) = 0;

	void save();
	void load();
};

#endif