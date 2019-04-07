#ifndef MARKET_V_H
#define MARKET_V_H
#include "Observer.h"
#include "Map.h"
#include "PowerPlant.h"
#include "City.h"
#include "Player.h"
#include "Market.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

// Observer object for observing Markets
// The Observer, upon notification, will call the update function
// The update function takes a map and integer as parameters. The integer indicates the type of update to perform
// If the appropriate integer is sent to this class, it will perform update and display updated information appropriate for this Observer

class marketView : public Observer
{
public:
	marketView();
	~marketView();
	//void update(Observable* ob, int j);
};

#endif