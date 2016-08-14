#ifndef MEMORY_STRATEGY_BY_MEMORY_CURVE_H
#define MEMORY_STRATEGY_BY_MEMORY_CURVE_H
using namespace std;

#include <string>
#include "MemoryStrategy.h"
#include "MemoryStrategyByMemoryCurveStorage.h"

class MemoryStrategyByMemoryCurve : public MemoryStrategy
{
	static const int ADD_TIME_NUM;
	static const int ADD_TIME[5];
	static const int SKILLED_TIME;
public:
	
	void init_storage(void* &storage);
	void refresh_storage(void* &storage, bool right);
	bool skilled(void* &storage);
	void to_skilled(void* &storage);

	string convert_storage_to_string(void* &storage);//in one line (no \n)
	void convert_string_to_storage(void* &storage, string context);
};

#endif