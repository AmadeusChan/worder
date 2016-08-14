#include "User.h"

User::User(OperateFileStrategy* _m_operate_file_strategy_, string _path_) : DatabaseImpl(_m_operate_file_strategy_, _path_) {}