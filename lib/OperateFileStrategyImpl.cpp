#include "OperateFileStrategyImpl.h"
#include "MyException.h"

string OperateFileStrategyImpl::read_file(string file_name)
{
	ifstream in(file_name, ios::in);
	if (!in)
		throw MyException("open input file failed");
	string temp_word, load_word = "";
	while (getline(in, temp_word))
		load_word += temp_word + '\n';
	load_word = load_word.substr(0, load_word.length() - 1);
	in.close();
	return load_word;
}

void OperateFileStrategyImpl::write_file(string file_name, string context)
{
	ofstream out(file_name, ios::out);
	if (!out)
		throw MyException("open output file failed");
	out << context << endl;
	out.close();
}
