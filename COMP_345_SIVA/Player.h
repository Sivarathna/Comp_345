#pragma once
#include<iostream>
#include "Colors.h"
#include "Resources.h"
#include "Subject.h"

using std::string;

class Player : public Subject
{
private:
	string name;
	Color color;
	int area;
	int elektro;
	int resources[Resource::RESOURCE_COUNT];
	bool isPlaying;

public:
	Player(string name, Color houseColor);
	Color getHouseColor();

	~Player();

	string getName() const;
	int getArea();
	void getPlayerInfo();
	int getResource(Resource r);
	bool getIsPlaying();

	void setIsPlaying(bool a);
	void setArea(int a);
	void setResource(Resource r, int num);


};

