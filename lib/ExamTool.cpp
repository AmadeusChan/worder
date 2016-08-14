#include "ExamTool.h"
#include "MyException.h"

ExamTool::ExamTool(WordBank<WordImpl>* _m_word_bank_, User* _m_user_, GetExamStrategy* _m_get_exam_strategy_) : ViewerImpl(_m_word_bank_, _m_user_), m_get_exam_strategy_(_m_get_exam_strategy_) 
{ 
	init_page();
}

void ExamTool::init_page()
{
	current_page_ = "";
	problem_num_ = 0;
	test_score_ = 0; 
	testing_ = false;
	current_word_ = NULL;
	if (!test_paper_.empty()) test_paper_.clear();
}

string ExamTool::get_head_page()
{
	string page = "*Exam*\n\n";
	if (!testing_)
		page += "Input -start [number of problem] to start exam.\n";
	page += "Input y when you remembers the word, otherwise input n.\n";
	page += "Input s to show the word's meaning if you are not sure.";
	return page;
}

Viewer* ExamTool::submit(string command)
{
	if (command == "-home") 
	{
		init_page();
		return NULL;
	}
	else
	{
		if (testing_)
		{
			if (command == "y" || command == "n")
			{
				if (command == "y")
					test_score_++;
				test_paper_.pop_back();	
				if (test_paper_.empty())
				{
					current_word_ = NULL;
					stringstream ss;
					string exam_score, exam_num;
					ss << test_score_;
					ss >> exam_score;
					ss.clear();
					ss << problem_num_;
					ss >> exam_num;
					current_page_ = "You have finished the exam, and your score is " + exam_score + "/" + exam_num;
					testing_ = false;
				}
				else
				{
					current_word_ = test_paper_.back();
				}
			}
			else
			if (command == "s")
			{
				current_page_ = "Word: " + current_word_->get_context() + '\n' + "Interpretation: " + current_word_->get_interpretation();
			}
			else
			{
				throw MyException("unknown command");
			}
		}
		else
		{
			if (command.substr(0, 6) == "-start")
			{
				init_page();

				if (command.length() < 7)
					throw MyException("please input [number of problem] after -start");

				stringstream ss;
				ss << command.substr(7, command.length());

				if (!(ss >> problem_num_) || problem_num_ <= 0)
					throw MyException("illegal problem number");

				test_paper_ = m_get_exam_strategy_->get_exam(problem_num_);
				problem_num_ = static_cast<int>(test_paper_.size());
				if (problem_num_ == 0)
					throw MyException("Empty problem set");
				testing_ = true;
				current_word_ = test_paper_.back();
			}
			else
			{
				throw MyException("unknown command");
			}
		}
		if (current_word_ != NULL && command != "s")
		{
			current_page_ = "Word: " + current_word_->get_context();
		}
	}
	return this;
}

ExamTool::~ExamTool()
{
	delete m_get_exam_strategy_;
}