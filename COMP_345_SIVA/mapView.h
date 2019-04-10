#ifndef MAP_V_H
#define MAP_V_H
#include "Observer.h"
#include "City.h"
#include "Map.h"
#include "Player.h"
#include "PowerPlant.h"

#include <vector>
#include <iostream>
#include <string>

// Observer object for observing Maps
// mapView inherits from the Observer class.
//if notify() is called, will call the update function

class mapView : public Observer
{
public:
	mapView();
	~mapView();

};

#endif