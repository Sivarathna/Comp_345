#include "Subject.h"

Subject::Subject()
{
}

Subject::~Subject()
{
}

void Subject::attach(Observer *a)
{
	//adds to vector of observers
	observers.push_back(a);
}



void Subject::detach(Observer *a)
{
	// iterates the observers vector and finds any discrepancy which results in erasing the object pointer
	for (auto it = this->observers.begin(); it < this->observers.end(); it++) {

		if (*it == a) {
			this->observers.erase(it);
			break;
		}
	}
}


void Subject::notify(int j)
{
	// This wil call thye update function for each observer (view)
	for (int i = 0; i < observers.size(); i++)
		observers[i]->update(this);
}

void Subject::notifyAll()
{
	for (auto i : observers) {
		i->update(this);
	}
}
