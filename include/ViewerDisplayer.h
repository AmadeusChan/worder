#ifndef VEIWER_DISPLAYER_H
#define VEIWER_DISPLAYER_H

#include "Viewer.h"
#include <string>
using namespace std;

class ViewerDisplayer
{
public:
	virtual string show() = 0;
	virtual void submit(string command) = 0;
};

#endif
