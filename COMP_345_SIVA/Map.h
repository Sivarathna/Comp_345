#pragma once
#include<iostream>
#include<vector>
#include"City.h"
using std::string;
using std::vector;

//The Map class is made singleton and observaeble
class Map: public Subject
{
private:
	int availableResource[Resource::RESOURCE_COUNT];
	int availableHouses[Color::COLOR_COUNT];
	vector<City*> cityList;
	City* firstCity;
	Map();

	static Map* m_pInstance;
public:
	int GetAvailableHouses(Color c);
	void SetAvailableHouses(Color c, int amount);

	int GetAvailableResource(Resource r);
	void SetAvailableResource(Resource r, int num);

	void buyResource(Resource r, int qty, Player& p, int c);

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

