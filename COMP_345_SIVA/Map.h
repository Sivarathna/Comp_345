#pragma once

#include<iostream>
#include<vector>
#include"City.h"
using std::string;
using std::vector;

// TODO: Make this singleton
class Map
{
private:
	vector<City*> cityList;
	City* firstCity;
	Map();



	static Map* m_pInstance;
public:

	int availableRedHouses = 22;
	int availableGreenHouses = 22;
	int availableBlueHouses = 22;
	int availablePurpleHouses = 22;
	int availableOrangeHouses = 22;
	int availableYellowHouses = 22;
	int availableCoal = 24;
	int availableOil = 24;
	int availableGarbage = 24;
	int availableUranium = 12;
	int availableElektro = 100000;

	~Map();
	static Map* Instance();

	void addCity(City* city);
	void removeCity(City* city);
	const void connectCity(City* city1, City* city2);
	const bool allCitiesConnected() const;
	const void printAllCities() const;
	City* getCity(const string cityName);
	vector<City*> getCityList();
};

