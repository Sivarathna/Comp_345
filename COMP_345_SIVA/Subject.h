#pragma once
#include <vector>
#include "Observer.h"
using namespace std;

class Observer;


//This abstract class is the superclass of all observaeable objects.
//It contains a list of observers, and populates the list using the attach and detach functions

class Subject
{
protected:
	vector<Observer*> observers;
public:
	Subject();
	virtual ~Subject();
	virtual void attach(Observer *a);
	virtual void detach(Observer *a);
	virtual void notify(int j);
	virtual void notifyAll();
};