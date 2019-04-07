#pragma once
#include<iostream>
#include "Colors.h"
#include "Resources.h"
using std::string;

class Player
{
private:
	string name;
	Color color;
	int area;
	int elektro;
	int resources[Resource::RESOURCE_COUNT];

public:
	Player(string name, Color houseColor);
	Color getHouseColor();
	~Player();
	string getName() const;
	int getArea();
	void setArea(int a);
	
	int getResource(Resource r);
	void setResource(Resource r, int num);

	void getPlayerInfo();
};

