#include "MemoryStrategyByMemoryCurveStorage.h"
#include <sstream>

MemoryStrategyByMemoryCurveStorage::MemoryStrategyByMemoryCurveStorage(int _next_recite_time, int _recite_times) : next_recite_time_(_next_recite_time), recite_times_(_recite_times) {}

string MemoryStrategyByMemoryCurveStorage::convert_data_to_string()
{
	stringstream ss;
	string gap( "<Gap&MemoryStrategyByMemoryCurveStorage>" ) ;
	ss << next_recite_time_ << gap << recite_times_;
	string ans;
	getline(ss, ans);
	return ans;
}

void MemoryStrategyByMemoryCurveStorage::convert_string_to_data(string context)
{
	string gap( "<Gap&MemoryStrategyByMemoryCurveStorage>" ) ;
	int pos = context.find(gap);
	stringstream ss;
	ss << context.substr(0, pos);
	ss >> next_recite_time_;
	ss.clear();
	ss << context.substr(pos + gap.length(), context.length());
	ss >> recite_times_;
}
