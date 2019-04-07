#pragma once
#include<iostream>
#include<vector>
#include"Player.h"

using std::string;
using std::vector;

class City
{
private:
	int house[Color::COLOR_COUNT];

public:
	string cityName;
	vector<City*> adjacentCities;
	Player* owner;

	City();
	City(string cityName);
	City(string cityName, Player* player);
	~City();
	
	void setCityName(string cityName);
	string getCityName() const;
	string getCityStatus();

	void placeHouse(Color c);
	int GetHouse(Color c);

	void addAdjacentCity(City* city);
	vector<City*> getAdjacentCities() const;

	void removeAdjacentCity(City* city);

	void setOwner(Player * player);
	Player* getOwner() const;

};

