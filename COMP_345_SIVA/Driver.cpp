#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>    // std::random_shuffle for shuffling the deck (Part 5)
#include <ctime>		// used for shuffling
#include <map>
using namespace std;

#include"City.h"
#include"Map.h"
#include"Player.h"
#include"PowerPlant.h"
#include"OverviewCard.h"

vector<PowerPlant*> deck; //Vector where all the powerplant and 'Step 3' card will be (Part 5)


//Shuffling the deck (Part 5)
void Shuffle() {
	random_shuffle(deck.begin(), deck.end());
}

// Printing the deck (Part 5)
void printDeck()
{
	/*for (std::vector<PowerPlant*>::iterator i = deck.begin(); i != deck.end(); ++i) {
		cout << *i << ' ';
	}*/

	for (int i = 0; i < deck.size(); i++) {
		cout << deck[i]->getPlantNumber() << ' ';
	}

}

bool readMapFromFile(Map* map, string file)
{
	ifstream myFile;

	vector<string> cities;

	myFile.open(file);

	string line;
	if (myFile.is_open())
	{
		while (myFile >> line && line != "####")
		{
			cities.push_back(line);
		}
	}
	else {
		cout << "ERROR: could not open file" << endl;
	}

	myFile.close();

	for (unsigned int i = 0; i < cities.size(); i = i + 2)
	{
		cout << cities[i] << " -> " << cities[i + 1] << endl;

		City* firstCity = new City(cities[i]);
		City* secondCity = new City(cities[i + 1]);

		map->addCity(firstCity);
		map->addCity(secondCity);

		map->connectCity(firstCity, secondCity);

	}

	map->printAllCities();

	if (map->allCitiesConnected())
	{
		cout << "Yes, everything is connected." << endl;
		return true;
	}
	else
	{
		cout << "Nope, map is not connected" << endl;
		return false;
	}
}

void printPlayerNetwork(Player player, vector<City*> cityList) {
	cout << "\n\nPlayer " + player.getName() + " has in his network:";

	if (player.getHouseColor() == "red") {
		for (int i = 0; i < cityList.size(); i++) {
			if (cityList[i]->redHouse == 1) {
				cout << "\n-" + cityList[i]->getCityName();
			}
		}
	}
	if (player.getHouseColor() == "blue") {
		for (int i = 0; i < cityList.size(); i++) {
			if (cityList[i]->blueHouse == 1) {
				cout << "\n-" + cityList[i]->getCityName();
			}
		}
	}
	if (player.getHouseColor() == "green") {
		for (int i = 0; i < cityList.size(); i++) {
			if (cityList[i]->greenHouse == 1) {
				cout << "\n-" + cityList[i]->getCityName();
			}
		}
	}
	if (player.getHouseColor() == "purple") {
		for (int i = 0; i < cityList.size(); i++) {
			if (cityList[i]->purpleHouse == 1) {
				cout << "\n-" + cityList[i]->getCityName();
			}
		}
	}
	if (player.getHouseColor() == "orange") {
		for (int i = 0; i < cityList.size(); i++) {
			if (cityList[i]->orangeHouse == 1) {
				cout << "\n-" + cityList[i]->getCityName();
			}
		}
	}
	if (player.getHouseColor() == "yellow") {
		for (int i = 0; i < cityList.size(); i++) {
			if (cityList[i]->yellowHouse == 1) {
				cout << "\n-" + cityList[i]->getCityName();
			}
		}
	}
}



int main()
{
	
	string map_name;
	int number_of_players = 0;
	int player_area;
	string player_name;
	vector<Player> players;

	// creating a Map
	//Map map = Map();
	Map* map = Map::Instance();
	//Select and load a map from list of files in a directory
	cout << "Enter the name of the map to use for the game (.txt file): " << endl;
	cin >> map_name;

	readMapFromFile(map, map_name);

	//Get the number of players (2-6 players)
	while (number_of_players < 2 || number_of_players >6) {
		cout << "\n\nEnter the number of players for this game (2-6 players): " << endl;
		cin >> number_of_players;
	}

	for (int i = 0; i < number_of_players; i++) {
		cout << "Enter a name for player:" << i + 1 << endl;
		cin >> player_name;
		players.push_back(Player(player_name));
	}

	//Each player chooses which area they will play in. 
	cout << "Choose an area to play in. There are a total number of 6 areas to choose from.\n";
	for (int i = 0; i < players.size(); i++) {
		cout << players.at(i).getName() << " , choose your area: "<<endl;
		cin >> player_area;
		players.at(i).setArea(player_area);
	}


	cout << "\n\nPlayers get ready to play!!!\n";
	cout << "--------- THE PLAYERS ARE --------" << endl;
	for (int i = 0; i < players.size(); i++) {
		cout << "Player: " << players.at(i).getName();
		cout << ">>> Area: " << players.at(i).getArea() << endl;
	}
	cout << "-----------------------------------" << endl;
	cout << endl;

	cout << endl;
	system("PAUSE");
	return 0;
}