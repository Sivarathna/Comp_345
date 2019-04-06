#include "Player.h"
#include"Map.h"

#include<string>


Player::Player()
{
	name = "";
	elektro = 0;
	coal = 0;
	garbage = 0;
	oil = 0;
	uranium = 0;

}

Player::Player(string playerName)
{

	name = playerName;
	elektro = 0;
	coal = 0;
	garbage = 0;
	oil = 0;
	uranium = 0;
}

Player::Player(string playerName, string houseColor)
{

	name = playerName;
	color = houseColor;
	elektro = 0;
	coal = 0;
	garbage = 0;
	oil = 0;
	uranium = 0;
}

string Player::getHouseColor() {
	return this->color;
}

Player::~Player()
{
}

string Player::getName() const
{
	return name;
}

int Player::getArea() {
	return area;
}

void Player::setArea(int player_area) {
	area = player_area;
}


int Player::getElektro()
{
	return this->elektro;
}





int Player::getCoal()
{
	return this->coal;
}



int Player::getGarbage()
{
	return this->garbage;
}


int Player::getOil()
{
	return this->oil;
}



int Player::getUranium()
{
	return this->uranium;
}


void Player::getPlayerInfo()
{
	std::cout << "Player Name: " << name << "\nColor: " << color << "\nElektro: " << elektro << "\nCoal: " << coal << "\nGarbage: " << garbage << "\nOil: " << oil << "\nUranium: " << uranium << std::endl;
}

void Player::assignOil(int num) {
	this->oil = oil + num;
	Map::Instance()->availableOil = Map::Instance()->availableOil - num;
}

void Player::assignGarbage(int num) {
	this->garbage = garbage + num;
	Map::Instance()->availableGarbage = Map::Instance()->availableGarbage - num;
}

void Player::assignCoal(int num) {
	this->coal = coal + num;
	Map::Instance()->availableCoal = Map::Instance()->availableCoal - num;
}

void Player::assignUranium(int num) {
	this->uranium = uranium + num;
	Map::Instance()->availableUranium = Map::Instance()->availableUranium - num;
}

void Player::assignElektro(int num) {
	this->elektro = elektro + num;
	Map::Instance()->availableElektro = Map::Instance()->availableElektro - num;
}

