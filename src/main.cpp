#ifdef _WIN32
	#define FUN_PREFIX __declspec(dllexport)
#else 
	#define FUN_PREFIX /**/
#endif

#include "StartPage.h"
#include "ViewerDisplayerImpl.h"
#include "SearchWordTool.h"
#include "OperateFileStrategyImpl.h"
#include "WordSetByMap.h"
#include "WordBankImpl.h"
#include "UserImpl.h"
#include "UserWordImpl.h"
#include "NewWordCountTool.h"
#include "AddWordTool.h"
#include "ExamTool.h"
#include "GetExamStrategyByRandom.h"
#include "MemoryStrategyByMemoryCurve.h"
#include "WordReciteTool.h"
#include "WordPickerStrategyByMemoryCurve.h"
#include "Interactor.h"
#include "MyException.h"
#include "UsernameReader.h"
#include <iostream>
using namespace std;

int main()
{
	UsernameReader username_reader;
	string username = username_reader.read();
	
	MemoryStrategyByMemoryCurve memory_strategy_by_memory_curve;
	OperateFileStrategyImpl operate_file_strategy;

	string user_path = "user_word_bank_" + username;
	string word_bank_path = "word_bank";

	UserImpl user(&memory_strategy_by_memory_curve, &operate_file_strategy, user_path, username);
	try
	{
		user.load();
	}
	catch (MyException exception)
	{
		cout << "rebuilding...";
	}
	WordBankImpl<WordImpl> word_bank(&operate_file_strategy, word_bank_path, new WordSetByMap<WordImpl>(WordImpl()));
	try
	{
		word_bank.load();
	}
	catch (MyException exception)
	{
		cout << "rebuilding...";
	}
	SearchWordTool search_word_tool(&word_bank, &user, &memory_strategy_by_memory_curve);
	NewWordCountTool new_word_count_tool(&word_bank, &user, &operate_file_strategy);
	AddWordTool add_word_tool(&word_bank, &user);
	ExamTool exam_tool(&word_bank, &user, new GetExamStrategyByRandom(&word_bank, &user));
	WordReciteTool word_recite_tool(new WordPickerStrategyByMemoryCurve(),  &memory_strategy_by_memory_curve, &word_bank, &user);

	StartPage* start_page = StartPage::get_instance(&word_bank, &user);
	start_page->add_tool("Add Word Tool", &add_word_tool);
	start_page->add_tool("Search Word Tool", &search_word_tool);
	start_page->add_tool("New Word Count Tool", &new_word_count_tool);
	start_page->add_tool("Word Recite Tool", &word_recite_tool);
	start_page->add_tool("Exam", &exam_tool);

	ViewerDisplayerImpl viewer_displayer(start_page);
	Interactor interactor(&viewer_displayer, &word_bank, &user);
	
	interactor.start();

	return 0;
}
