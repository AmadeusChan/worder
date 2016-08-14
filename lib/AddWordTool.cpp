#include "AddWordTool.h"
#include "MyException.h"

void AddWordTool :: init_page()
{
	current_page_ = "";
}

string AddWordTool::get_head_page()
{
	string page = "*Add Word Tool*\n\n";
	page += "Input '-add [word] [interpretation]' to add word.\n";
	page +=	"Input '-file [file path]' to add words by file.\n";
	page += "TIPS:If you'd like to add words by file, your file should be:\n[word] [interpretation]\n[word] [interpretation]\n..." ;
	return page;
}

void AddWordTool :: add_word( string word_in_string ) {
	stringstream word_in_stream ; 
	word_in_stream << word_in_string ; 
	string single_word , interpretation_of_word ; 
	word_in_stream >> single_word ; 
	getline( word_in_stream , interpretation_of_word ) ; 
	if (interpretation_of_word.length() == 0)
		throw MyException("word/interpretation can't be empty");
	WordImpl word_in_WordImpl( single_word , interpretation_of_word ) ; 
	m_word_bank_ -> add_word( word_in_WordImpl ) ; 
}

AddWordTool::AddWordTool(WordBank<WordImpl>* _m_word_bank_, User* _m_user_) :  ViewerImpl(_m_word_bank_, _m_user_) 
{
	init_page( );
}

Viewer* AddWordTool :: submit( string command ) {

	if ( command == "-home" ) {
		init_page(  ) ;
		return NULL ; 
	}
	current_page_ = "";

	stringstream str ; 
	str << command ; 
	string operate_option , word_in_string ; 
	str >> operate_option ;

	if ( operate_option == "-add" ) { 
		getline( str , word_in_string ) ; 
		add_word( word_in_string ) ; 
	} else if ( operate_option == "-file" ) {

		string path_of_file ; 
		str >> path_of_file ; 

		OperateFileStrategyImpl file_strategy ; 
		string all_word_in_string = file_strategy.read_file( path_of_file ) ;

		stringstream all_word_in_stream ; 
		all_word_in_stream << all_word_in_string ; 
		while ( ! all_word_in_stream.eof(  ) ) {
			getline( all_word_in_stream , word_in_string ) ; 
			add_word( word_in_string ) ; 
		}
	}
	else
		throw MyException("unknown command");
	current_page_ = "Success!";
	return this;
}
