#include "UserImpl.h"
#include "User.h"
#include <iostream>
using namespace std;

UserImpl::UserImpl(MemoryStrategy* _m_memory_strategy_, OperateFileStrategy* _m_operate_file_strategy_, string _path_, string _user_name_) : User(_m_operate_file_strategy_, _path_), m_memory_strategy_(_m_memory_strategy_), user_name_(_user_name_), word_bank_(new WordSetByMap<UserWordImpl>(UserWordImpl(_m_memory_strategy_))) {}

// a function to convert data into string 

string UserImpl :: convert_data_to_string(  ) {
	string context( user_name_ ) ;
	string gap( "<Gap&In_User#Impl>" ) ;
	context += gap ; 
	context += word_bank_.convert_data_to_string(  ) ;
	context += gap ; 
	for ( auto pt = search_history_list_.begin(  ) ; pt != search_history_list_.end(  ) ; ++ pt ) {
		context += *pt ; 
		context += gap ; 
	}
	return context ; 
}

void UserImpl :: convert_string_to_data( string context ) {
	string gap( "<Gap&In_User#Impl>" ) ;
	int left = 0 , right = context.find( gap , 0 ) ;

	user_name_.clear(  ) ;
	for ( int i = 0 ; i < right ; ++ i ) user_name_ += context[ i ] ;

	left = right + gap.length(  ) ;
	right = context.find( gap , left ) ;
	string context_of_word_bank("") ;
	for ( int i = left ; i < right ; ++ i ) context_of_word_bank += context[ i ] ;
	word_bank_.convert_string_to_data( context_of_word_bank ) ;

	left = right + gap.length(  ) ;
	string temp ; 
	search_history_list_.clear(  ) ;
	for ( right = context.find( gap , left ) ; right != string :: npos ; right = context.find( gap , left = right + gap.length(  ) ) ) {
		temp.clear(  ) ;
		for ( int i = left ; i < right ; ++ i ) temp += context[ i ] ;
		search_history_list_.push_back( temp ) ;
	}
} 

void UserImpl :: put_search_history(string search_command)
{
	search_history_list_.push_back(search_command);	
}

vector<string> UserImpl :: get_search_history(int start, int num)
{
	vector<string> ans;
	for (int i = start; i < min(start + num, static_cast<int>(search_history_list_.size())); ++i)
	{
		ans.push_back(search_history_list_[i]);
	}
	return ans;
}

WordBankImpl < UserWordImpl > * UserImpl :: get_user_word_bank(  ) {
	return &word_bank_ ; 
}

string UserImpl::get_user_name()
{
	return user_name_;
}
