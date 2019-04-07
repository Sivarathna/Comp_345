#pragma once
#include"Player.h"
#include <iostream>

class PowerPlant
{
private:

	
public:
	int plantNumber;
	int powersCities;
	int coalRequired;
	int oilRequired;
	int garbageRequired;
	int uraniumRequired;
	int hybridRequired;
	Player* owner;
	int plantStatus = 0;

	PowerPlant();
	PowerPlant(int plantNumber);
	PowerPlant(int plantNumber, int powersCities, int coalRequired, int oilRequired, int garbageRequired, int uraniumRequired, int hybridRequired, int plantStatus);
	~PowerPlant();
	
	int getPlantNumber() const;
	int getPlantStatus();
	Player* getOwner();

	void changePlantStatus();
	void setOwner(Player* name);
	void setPlantNumber(int v);
};