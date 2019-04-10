#ifndef OBSERVER_H
#define OBSERVER_H
#include <vector>

// Implementation of the Observer Pattern

// forward declaration
class Observable;

class Observer
{
public:
	Observer();
	virtual ~Observer();
	// observers hold and define an update function with an observable object and an integer
	// All observers hold and define an update function that takes an observable object and an integer
	virtual void update(Observable* ob, int i) = 0;
};

#endif