#ifndef WORD_SET_BY_MAP_H
#define WORD_SET_BY_MAP_H

#include "WordSet.h"
#include <map>
#include <string>
using namespace std;

template <typename T> class WordSetByMap : public WordSet<T>
{
	map<string, T> words_;
	T creater_;

public:
	WordSetByMap(T _creater_);

	vector<T*> get_words();
	T* find_word_by_context(string context);
	void add_word(T word);
	void remove_word(T* word);//delete memory before remove
	~WordSetByMap();

	string convert_data_to_string(  ) ;
	void convert_string_to_data( string context ) ;

};

template<typename T>
WordSetByMap<T>::WordSetByMap(T _creater_) : creater_(_creater_){};

template<typename T>
WordSetByMap<T>::~WordSetByMap()
{
	//remove everything in word_ by remove_word()
	for ( ; words_.size(  ) ; remove_word( &(words_.begin(  ) -> second) ) ) ;
}

template < typename T > 
vector < T* > WordSetByMap < T > :: get_words(  ) {
	vector < T* > words_in_vector ; 
	words_in_vector.clear(  ) ; 
	for ( auto pt = words_.begin(  ) ; pt != words_.end(  ) ; ++ pt ) {
		words_in_vector.push_back( &(pt -> second) ) ;
	}
	return words_in_vector ;
}

template < typename T > 
T* WordSetByMap < T > :: find_word_by_context( string context ) {
	auto pt = words_.find( context ) ;
	if ( pt == words_.end(  ) ) return NULL ; // which means there's no matching word in the word set
	else return &(pt -> second) ;
}

template < typename T > 
void WordSetByMap < T > :: add_word( T word ) {
	string context = word.get_context(  ) ; 
	auto pt = words_.find(context);
	if (pt == words_.end())
	{
		words_.insert( pair < string , T > ( context , word ) ) ;
	}
}

template < typename T >
void WordSetByMap < T > :: remove_word( T* word ) {
	string context = word -> get_context(  ) ;
	auto pt = words_.find( context ) ;
	if ( pt != words_.end(  ) ) {
		words_.erase( pt ) ;
	}
}

template < typename T >
string WordSetByMap < T > :: convert_data_to_string(  ) {
	string gap( "<Gap@In$Word*Set$By&Map>" ) ;
	string context( "" ) ;
	for ( auto pt = words_.begin(  ) ; pt != words_.end(  ) ; ++ pt ) {
		context += pt -> first ; 
		context += gap ; 
		context += pt -> second.convert_data_to_string(  )  ; 
		context += gap ; 
	}
	return context ;
}

template < typename T >
void WordSetByMap < T > :: convert_string_to_data( string context ) {
	string gap( "<Gap@In$Word*Set$By&Map>" ) ;
	string context_of_word , word ; 
	int left = 0 , right ; 
	for ( ; words_.size(  ) ; remove_word( &(words_.begin(  ) -> second) ) ) ;
	for ( right = context.find( gap , left ) ; right != string :: npos ; right = context.find( gap , left = right + gap.length(  ) ) ) {
		context_of_word = "" , word = "" ;
		for ( int i = left ; i < right ; ++ i ) context_of_word += context[ i ] ;
		right = context.find( gap , left = right + gap.length(  ) ) ;
		for ( int i = left ; i < right ; ++ i ) word += context[ i ] ; 
		T pt = creater_; 
		pt.convert_string_to_data( word ) ; 
		words_.insert( pair < string , T > ( context_of_word , pt ) ) ;
	}
}
#endif
