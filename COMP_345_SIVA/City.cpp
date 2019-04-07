#include "City.h"
#include "Map.h"
#include <string>

City::City()
{
	cityName = "";
}

City::City(string cityName)
{
	this->cityName = cityName;

	for (int i = 0; i < Color::COLOR_COUNT; i++) {
		this->house[i] = 0;
	}
}

City::City(string cityName, Player * player)
{
	this->cityName=cityName,
	this->owner = player;
}


City::~City()
{
	
}

void City::setCityName(const string cityName)
{
	this->cityName = cityName;
}

string City::getCityName() const
{

	return this->cityName;
}

string City::getCityStatus() {
	return ("\n" + cityName + " | red house: " + std::to_string(house[Color::Red]) + " | green house: " + std::to_string(house[Color::Green]) + " | blue house: " + std::to_string(house[Color::Blue])
		+ " | Purple House: " + std::to_string(house[Color::Purple]) + " | Orange House: " + std::to_string(house[Color::Orange]) + " | Yellow House: " + std::to_string(house[Color::Yellow]));
}

void City::placeHouse(Color c)
{
	this->house[c] = 1;
	auto map = Map::Instance();
	map->SetAvailableHouses(c, map->GetAvailableHouses(c) - 1);
}

int City::GetHouse(Color c)
{
	if (c == Color::COLOR_COUNT) {
		throw;
	}
	return this->house[c];
}

void City::addAdjacentCity(City* city)
{
	adjacentCities.push_back(city);
}

vector<City*> City::getAdjacentCities() const
{
	return this->adjacentCities;
}

void City::removeAdjacentCity(City * city)
{
	for (unsigned int i = 0; i < adjacentCities.size(); i++) {
		if (adjacentCities.at(i) == city) {
			adjacentCities.erase(adjacentCities.begin() + i);
		}
	}
}

void City::setOwner(Player* player)
{
	this->owner = player;
}

Player * City::getOwner() const
{
	return this->owner;
}
