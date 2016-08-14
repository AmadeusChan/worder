#ifndef MEMORY_STRATEGY_BY_MEMORY_CURVE_STORAGE
#define MEMORY_STRATEGY_BY_MEMORY_CURVE_STORAGE

#include "DatabaseImpl.h"

struct MemoryStrategyByMemoryCurveStorage : public DatabaseImpl
{
	int next_recite_time_, recite_times_;

	MemoryStrategyByMemoryCurveStorage(int _next_recite_time = 0, int _recite_times = 0);

	string convert_data_to_string();
	void convert_string_to_data(string context);
};

#endif