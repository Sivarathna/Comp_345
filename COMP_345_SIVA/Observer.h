#pragma once
#include <vector>
#include "Subject.h"

// forward declaration
class Subject;

class Observer
{
public:
	Observer();
	virtual ~Observer();
	virtual void update(Subject* ob) = 0;
};