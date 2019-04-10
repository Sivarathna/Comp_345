#include "Player.h"
#include"Map.h"
#include<string>

Player::Player(string playerName, Color houseColor)
{

	name = playerName;
	color = houseColor;

	for (int i = 0; i < Resource::RESOURCE_COUNT; i++) {
		this->resources[i] = 0;
	}
	this->setResource(Resource::Elektro, 100);
}

Color Player::getHouseColor() {
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

void Player::setIsPlaying(bool a)
{
	isPlaying = a;
	//notify all the observers for the player 
	notifyAll();
}

void Player::setArea(int player_area) {
	area = player_area;
}

void Player::getPlayerInfo()
{
	std::cout << "Player Name: " << name
		<< "\nColor: " << color
		<< "\nElektro: " << this->getResource(Resource::Elektro)
		<< "\nCoal: " << this->getResource(Resource::Coal)
		<< "\nGarbage: " << this->getResource(Resource::Garbage)
		<< "\nOil: " << this->getResource(Resource::Oil)
		<< "\nUranium: " << this->getResource(Resource::Uranium)
		<< std::endl;
}

void Player::setResource(Resource r, int num) {
	if (r == Resource::RESOURCE_COUNT) {
		throw;
	}
	this->resources[r] = num;
}

int Player::getResource(Resource r) {
	if (r == Resource::RESOURCE_COUNT) {
		throw;
	}
	return this->resources[r];
}

bool Player::getIsPlaying()
{
	return isPlaying;
}
