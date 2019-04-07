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

#define PSE std::pair<std::string, int>


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


std::vector<PSE> GetStepOnePlayerOrder(Map& map, vector<Player>& players) {
	// Determine player order.
	auto cities = map.getCityList();
	auto counters = std::map<string, int>();
	counters.insert(PSE("red", 0));
	counters.insert(PSE("blue", 0));
	counters.insert(PSE("green", 0));
	counters.insert(PSE("purple", 0));
	counters.insert(PSE("orange", 0));
	counters.insert(PSE("yellow", 0));

	for (auto city : cities) {
		counters.at("red") = counters.at("red") + city->redHouse;
		counters.at("blue") = counters.at("blue") + city->blueHouse;
		counters.at("green") = counters.at("green") + city->greenHouse;
		counters.at("purple") = counters.at("purple") + city->purpleHouse;
		counters.at("orange") = counters.at("orange") + city->orangeHouse;
		counters.at("yellow") = counters.at("yellow") + city->yellowHouse;
	}

	vector<PSE> order;
	for (auto pair : counters) {
		order.push_back(PSE(pair.first, pair.second));
	}
	std::sort(order.begin(), order.end(), [&](const PSE a, const PSE b) {
		return a.second > b.second;
	});
	return order;
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
		auto order = GetStepOnePlayerOrder(*map, players);
		for (auto pair : order) {
			cout << pair.first << " " << pair.second << std::endl;
		}

		// PHASE 2:  Auction power plants.
		//		a) pass (not available in round 1 of the game, player needs to buy a powerplant in the first round)
		//		b) select plant for auction

		char choice = ' ';
		int powerPlantNum, bid, highestBid, currBidder;
		bool chosenPlant, bid_1, bid_2, wonBid;

		vector<Player> availablePlayers;
		vector<Player> biddingPlayers;

		for (auto player : players) {

			if (currentRound > 1) {
				//Keep asking player to auction if not in the first round
				cout << "\n" << player.getName();
				cout << ", would you like to auction a power plant? Y/N" << endl;
				while (toupper(choice) != 'Y' || toupper(choice) != 'N') {
					//get user input
					cin >> choice;
					if (cin.fail()) {
						cin.clear();
						cin.ignore();
						choice = ' ';
					}

					if (toupper(choice) == 'Y') {
						//add to available players vector if player is placing a power plant
						availablePlayers.push_back(player);
						for (int i = 0; i < availablePlayers.size(); i++) {
							cout << "available Players are " << availablePlayers.at(i).getName() << endl;
						}
						break;
					}

					else if (toupper(choice) == 'N')
						break;

					else
						cout << "Please try again..." << endl;
					break;
				}

			}
			else
				availablePlayers.push_back(player);
		}

	



		////Loop for each player's turn to play
		//int iterator_1 = 0;
		//int i;

		//while (availablePlayers.size() > 0) {
		//	iterator_1 % players.size();
		//}

		////need to check if player is available for auctionning
		//for (int a = 0; a < availablePlayers.size(); a++) {
		//	if (availablePlayers[a].getName() == players.at(i).getName()) {

		//		//TODO: display the power plant market
		//		cout << "Power Plant Market:" << endl;

		//		//TODO: display current player name and colour


		//		chosenPlant = false;
		//		//player chooses what power plant to auction
		//		cout << "\nEnter the power plant do you want to auction: " << endl;
		//		while (!chosenPlant) {
		//			cin >> powerPlantNum;

		//			//check if current player has enough electros in order to bid on the selected power plant
		//			if (powerPlantNum > players.at(i).getElektro()) {
		//				cout << "Unable to place that bid. You do not have enough electros.";
		//				cout << "You currently have:" << players.at(i).getElektro() << " electros. Please try again!" << endl;
		//			}

		//			//TODO: check if input exists in current power plant and if it is in the actual market
		//			//else if () {

		//			//}
		//			else
		//				cout << "Wrong option. Try again" << endl;
		//			
		//		}
		//		

		//	}
		//}





















		//PHASE 3. Buy resources
	}

	system("PAUSE");
	return 0;
}