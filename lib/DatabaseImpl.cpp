#include "DatabaseImpl.h"
using namespace std;

DatabaseImpl::DatabaseImpl(OperateFileStrategy* _m_operate_file_strategy_, string _path_) : m_operate_file_strategy_(_m_operate_file_strategy_), path_(_path_), OPERATEABLE_(true) {}
DatabaseImpl::DatabaseImpl() : m_operate_file_strategy_(NULL), path_(""), OPERATEABLE_(false) {}

void DatabaseImpl::save()
{
	if (!OPERATEABLE_) return;
	m_operate_file_strategy_->write_file(path_, convert_data_to_string());
}

void DatabaseImpl::load()
{
	if (!OPERATEABLE_) return;
	convert_string_to_data(m_operate_file_strategy_->read_file(path_));
}
