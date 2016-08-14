#ifndef VEIWER_H
#define VEIWER_H

#include <string>
using namespace std;

class Viewer
{
public:
	virtual string show() = 0;
	virtual Viewer* submit(string command) = 0;
	virtual ~Viewer();
};

#endif