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
#include "ResourceTable.h"
#include "Market.h"

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

	for (auto city : cityList) {
		if (city->GetHouse(player.getHouseColor())) {
			cout << "\n-" + city->getCityName();
		}
	}
}


vector<Player> GetStepOnePlayerOrder(Map& map, vector<Player>& players) {
	// Determine player order.
	auto cities = map.getCityList();
	// Keeps track of the number of cities that we saw for each color.
	// Map of Color -> int
	// example, counters[RED] would store the number of red cities we saw.
	auto counters = std::map<int, int>();

	for (int i = 0; i < Color::COLOR_COUNT; i++) {
		counters[i] = 0;
	}

	// Count the nunmber of houses in each city by their color.
	for (auto city : cities) {
		for (int i = 0; i < Color::COLOR_COUNT; i++) {
			counters[i] += city->GetHouse((Color)i);
		}
	}

	vector<Player> order;
	for (auto player : players) {
		order.push_back(player);
	}

	// Ampersand means that the outside variables are copied by reference.
	// We need this because we need access to the COUNTERS variable.
	auto sortingFunction = [&](Player a, Player b) {
		return counters[a.getHouseColor()] > counters[b.getHouseColor()];
	};

	std::sort(order.begin(), order.end(), sortingFunction);
	return order;
}

int main()
{
	string map_name;
	int number_of_players = 0;
	int player_area;
	string player_name;
	vector<Player> players;
	Market market;
	vector<PowerPlant> allPowerPlantCards;

	// Initialize power plant cards.
	for (int i = 0; i < 43; i++) {
		PowerPlant p;
		p.setPlantNumber(i + 1);
		allPowerPlantCards.push_back(p);
	}

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

	// Keep track of which colors are available.
	std::map<int, bool> availableColors;
	for (int i = 0; i < Color::COLOR_COUNT; i++) {
		// They are all available to begin with.
		availableColors[i] = true;
	}

	// Pick a name and a color for EACH player.
	for (int i = 0; i < number_of_players; i++) {
		cout << "Enter a name for player:" << i + 1 << endl;
		cin >> player_name;

		// -1 means invalid choice.
		int playerColor = -1;
		while (playerColor == -1) {
			cout << "Enter a color for player:" << i + 1 << " Your options are:" << endl;
			for (int ii = 0; ii < Color::COLOR_COUNT; ii++) {
				if (availableColors[ii]) {
					cout << " " << ii << ":" << GetColorName((Color)ii) << endl;
				}
			}
			cin >> playerColor;

			// If it's available, mark it as taken and exit.
			if (availableColors[playerColor]) {
				availableColors[playerColor] = false;
				// Break out of the while.
				break;
			}
			playerColor = -1;
		}

		players.push_back(Player(player_name, (Color)playerColor));
	}

	//Each player chooses which area they will play in. 
	cout << "Choose an area to play in. There are a total number of 6 areas to choose from.\n";
	for (int i = 0; i < players.size(); i++) {
		cout << players.at(i).getName() << " , choose your area: " << endl;
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

	int currentRound = 0;

	// While the game is running.
	while (true) {
		//Determine round number
		currentRound++;
		cout << "Entering new round. Round:" << currentRound << endl;

		// Determine player order.
		players = GetStepOnePlayerOrder(*map, players);

		// PHASE 2:  Auction power plants.
		//		a) pass (not available in round 1 of the game, player needs to buy a powerplant in the first round)
		//		b) select plant for auction
		market.replenishPowerPlants(allPowerPlantCards);
		market.BidPowerPlants(players);

		// Buying phase.
		cout << "THE TIME TO BUY IS NOW" << endl;
		for (auto player : players) {
			cout << player.getName() << "'s turn to buy" << endl;


			while (true) {
				// Print all the resources the player has.
				cout << endl;
				cout << "You have: " << endl;
				for (int i = 0; i < Resource::RESOURCE_COUNT; i++) {
					cout << "  " << player.getResource((Resource)i) << " of " << GetResourceName((Resource)i) << endl;
				}
				cout << endl;

				// Show what they can do.
				cout << "OPTIONS" << endl;
				cout << " -1 - Done" << endl;
				for (int i = 0; i < Resource::Elektro; i++) {
					cout << " " << i << " - " << GetResourceName((Resource)i) << ": " << map->GetAvailableResource((Resource)i) << " for a cost of " << GetResourceCost((Resource)i, 1, number_of_players) << " each." << endl;
				}
				cout << endl;

				cout << "Select the (number) resource that you want to buy, and then the quantity (choiceNumber quantity): ";
				int choice;
				int quantity;
				cin >> choice;

				if (choice < -1 || choice >= (int)Resource::Elektro) {
					cout << "That's not a valid resource" << endl;
					continue;
				}
				Resource r = (Resource)choice;

				if (choice != -1) {
					cin >> quantity;
					if (map->GetAvailableResource(r) >= quantity) {
						int cost = GetResourceCost(r, 1, number_of_players) * quantity;

						if (player.getResource(Resource::Elektro) < cost) {
							cout << "You can't buy that much." << endl;
							continue;
						}

						player.setResource(r, quantity);
						player.setResource(Resource::Elektro, player.getResource(Resource::Elektro) - cost);
						map->SetAvailableResource(r, map->GetAvailableResource(r) - quantity);

						cout << "Purchased " << quantity << " of " << GetResourceName(r) << " for " << cost << " Elektro." << endl;
					}
					else {
						cout << "You can only buy " << map->GetAvailableResource(r) << " much." << endl;
					}

					continue;
				}
				cout << "Done" << endl;
				break;
			}

		}
	}

	system("PAUSE");
	return 0;
}