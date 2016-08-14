#include "MemoryStrategyByMemoryCurve.h"
#include <sstream>
#include <ctime>

const int MemoryStrategyByMemoryCurve::ADD_TIME_NUM = 5;
const int MemoryStrategyByMemoryCurve::ADD_TIME[5] = {1800, 86400, 345600, 1296000, 2592000};
const int MemoryStrategyByMemoryCurve::SKILLED_TIME = 0x7fffffff;

void MemoryStrategyByMemoryCurve::init_storage(void* &storage)
{
	storage = new MemoryStrategyByMemoryCurveStorage(0, 0);
}

void MemoryStrategyByMemoryCurve::refresh_storage(void* &storage, bool right)
{
	MemoryStrategyByMemoryCurveStorage* m_storage = (MemoryStrategyByMemoryCurveStorage*)storage;
	if (right)
	{
		if (m_storage->recite_times_ >= ADD_TIME_NUM)
		{
			m_storage->next_recite_time_ = SKILLED_TIME;
		}
		else
		{
			m_storage->next_recite_time_ = int(time(0)) + ADD_TIME[m_storage->recite_times_];
			m_storage->recite_times_ += 1;
		}
	}
}

bool MemoryStrategyByMemoryCurve::skilled(void* &storage)
{
	return ((MemoryStrategyByMemoryCurveStorage*)storage)->next_recite_time_ >= SKILLED_TIME;
}

void MemoryStrategyByMemoryCurve::to_skilled(void* &storage)
{
	((MemoryStrategyByMemoryCurveStorage*)storage)->next_recite_time_ = SKILLED_TIME;
	((MemoryStrategyByMemoryCurveStorage*)storage)->recite_times_ = ADD_TIME_NUM;
}

string MemoryStrategyByMemoryCurve::convert_storage_to_string(void* &storage)
{
	return ((MemoryStrategyByMemoryCurveStorage*)storage)->convert_data_to_string();
}

void MemoryStrategyByMemoryCurve::convert_string_to_storage(void* &storage, string context)
{
	((MemoryStrategyByMemoryCurveStorage*)storage)->convert_string_to_data(context);
}