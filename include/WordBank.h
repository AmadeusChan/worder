#ifndef WORD_BANK_H
#define WORD_BANK_H

#include <vector>
#include "DatabaseImpl.h"

template <typename T> class WordBank : public DatabaseImpl
{
public:
	WordBank(OperateFileStrategy* _m_operate_file_strategy_, string _path_);
	WordBank();
	virtual vector<T*> get_words() = 0;
	virtual T* find_word_by_context(string context) = 0;
	virtual void add_word(T word) = 0;
	virtual void remove_word(T* word) = 0;
	virtual ~WordBank() = 0;
};

template<typename T>
WordBank<T>::WordBank(OperateFileStrategy* _m_operate_file_strategy_, string _path_) : DatabaseImpl(_m_operate_file_strategy_, _path_){}

template<typename T>
WordBank<T>::WordBank() : DatabaseImpl() {}

template<typename T>
WordBank<T>::~WordBank() {}

#endif