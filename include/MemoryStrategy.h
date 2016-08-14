#ifndef MEMORY_STRATEGY_H
#define MEMORY_STRATEGY_H

#include <string>

class MemoryStrategy
{
public:
	virtual void init_storage(void* &storage) = 0;
	virtual void refresh_storage(void* &storage, bool right) = 0;
	virtual string convert_storage_to_string(void* &storage) = 0;//in one line (no \n)
	virtual void convert_string_to_storage(void* &storage, string context) = 0;
	virtual bool skilled(void* &storage) = 0;
	virtual void to_skilled(void* &storage) = 0;
};

#endif