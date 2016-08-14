#ifndef WORD_BANK_IMPL_H
#define WORD_BANK_IMPL_H

#include <vector>
#include "WordBank.h"
#include "WordSet.h"

template <typename T> class WordBankImpl : public WordBank<T>
{
	WordSet<T>* m_word_set_;

public:
	WordBankImpl(OperateFileStrategy* _m_operate_file_strategy_, string _path_, WordSet<T>* _m_word_set_);
	WordBankImpl(WordSet<T>* _m_word_set_);

	string convert_data_to_string();
	void convert_string_to_data(string context);

	vector<T*> get_words();
	T* find_word_by_context(string context);
	void add_word(T word);
	void remove_word(T* word);
	~WordBankImpl();
};

template<typename T>
WordBankImpl<T>::WordBankImpl(OperateFileStrategy* _m_operate_file_strategy_, string _path_, WordSet<T>* _m_word_set_) : WordBank<T>(_m_operate_file_strategy_, _path_), m_word_set_(_m_word_set_){}

template<typename T>
WordBankImpl<T>::WordBankImpl(WordSet<T>* _m_word_set_) : WordBank<T>(), m_word_set_(_m_word_set_){}

template<typename T>
WordBankImpl<T>::~WordBankImpl()
{
	//delete m_word_set_;
}

template < typename T > 
string WordBankImpl < T > :: convert_data_to_string(  ) {
	return m_word_set_ -> convert_data_to_string(  ) ; 
}

template < typename T > 
void WordBankImpl < T > :: convert_string_to_data( string context ) {
	m_word_set_ -> convert_string_to_data( context ) ; 
}

template < typename T >
vector < T* > WordBankImpl < T > :: get_words(  ) {
	return m_word_set_ -> get_words(  ) ; 
}

template < typename T >
T* WordBankImpl < T > :: find_word_by_context( string context ) {
	return m_word_set_ -> find_word_by_context( context ) ;
}

template < typename T >
void WordBankImpl < T > :: add_word( T word ) {
	m_word_set_ -> add_word( word ) ; 
}

template < typename T >
void WordBankImpl < T > :: remove_word( T* word ) {
	m_word_set_ -> remove_word( word ) ; 
}

#endif