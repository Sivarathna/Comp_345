#pragma once
#include <vector>

// This abstract class implements the Observer Pattern by acting as the superclass Observer

// forward declaration
class Subject;

class Observer
{
public:
	Observer();
	virtual ~Observer();
	virtual void update(Subject* ob) = 0;
};

