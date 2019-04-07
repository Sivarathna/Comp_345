#include "PowerPlant.h"
#include "Player.h"
#include <iostream>


PowerPlant::PowerPlant()
{
	plantNumber = 0;
	powersCities = 0;
	coalRequired = 0;
	oilRequired = 0;
	garbageRequired = 0;
	uraniumRequired = 0;
	hybridRequired = 0;
	plantStatus = 0;
}

PowerPlant::PowerPlant(int plantNumber)
{
	this->plantNumber = plantNumber;
}

PowerPlant::PowerPlant(int plantNumber, int powersCities, int coalRequired, int oilRequired, int garbageRequired, int uraniumRequired, int hybridRequired, int plantStatus)
{
	this->plantNumber = plantNumber;
	this->powersCities = powersCities;
	this->coalRequired = coalRequired;
	this->oilRequired = oilRequired;
	this->garbageRequired = garbageRequired;
	this->uraniumRequired = uraniumRequired;
	this->hybridRequired = hybridRequired;
	this->plantStatus = plantStatus;
}

PowerPlant::~PowerPlant()
{
}

int PowerPlant::getPlantNumber() const
{
	return plantNumber;
}

void PowerPlant::setOwner(Player* name) {
	this->owner = name;
}

Player* PowerPlant::getOwner() {
	return this->owner;
}

void PowerPlant::setPlantNumber(int v) {
	this->plantNumber = v;
}

int PowerPlant::getPlantStatus() {
	return plantStatus;
}

void PowerPlant::changePlantStatus() {
	if (plantStatus == 0)
		plantStatus = 1;
	else if (plantStatus == 1)
		plantStatus = -1;
}