#include "Market.h"
#include <map>

// Default constructor
Market::Market()
{
	resourceBank[0] = 24;
	resourceBank[1] = 24;
	resourceBank[2] = 24;
	resourceBank[3] = 12;
	coal[0] = -1;
	oil[0] = -1;
	garbage[0] = -1;
	uranium[0] = -1;
	for (int i = 1; i < 9; i++)
	{
		coal[i] = 0;
		oil[i] = 0;
		garbage[i] = 0;
		uranium[i] = 0;
	}
	uranium[9] = -2;
	uranium[10] = 0;
	uranium[11] = -2;
	uranium[12] = 0;
	uranium[13] = -2;
	uranium[14] = 0;
	uranium[15] = -2;
	uranium[16] = 0;
}

// Parameterized constructor
Market::Market(int c, int o, int g, int u)
{
	resourceBank[0] = c;
	resourceBank[1] = o;
	resourceBank[2] = g;
	resourceBank[3] = u;
	coal[0] = -1;
	oil[0] = -1;
	garbage[0] = -1;
	uranium[0] = -1;
	for (int i = 1; i < 9; i++)
	{
		coal[i] = 0;
		oil[i] = 0;
		garbage[i] = 0;
		uranium[i] = 0;
	}
	uranium[9] = -2;
	uranium[10] = 0;
	uranium[11] = -2;
	uranium[12] = 0;
	uranium[13] = -2;
	uranium[14] = 0;
	uranium[15] = -2;
	uranium[16] = 0;
}

///  Added for map: getMarket
Market::Market(const Market& m) {
	resourceBank[0] = m.resourceBank[0];
	resourceBank[1] = m.resourceBank[1];
	resourceBank[2] = m.resourceBank[2];
	resourceBank[3] = m.resourceBank[3];
	for (int i = 0; i < 18; i++) {
		if (i < 9) {
			coal[i] = m.coal[i];
			oil[i] = m.oil[i];
			garbage[i] = m.garbage[i];
			uranium[i] = m.uranium[i];
		}
		if (i >= 9)
			uranium[i] = m.uranium[i];
	}
}

// Destructor
Market::~Market() {}


// Get any resource from Bank
int Market::getBankResource(int slot)
{
	return resourceBank[slot];
}

// Set any resource to Bank
void Market::setBankResource(int slot, int quantity)
{
	resourceBank[slot] = quantity;
}


// Get Coal
int Market::getCoal(int slot)
{
	if (slot < 0 || slot > 8) // Does the market slot hold that specific resource?
		return 0;
	else
		return coal[slot];
}

// Set Coal
void Market::setCoal(int slot, int quantity)
{
	if (slot < 0 || slot > 8) // Does the market slot hold that specific resource?
		cout << "This market slot cannot hold coal!";
	else if (quantity > 3) // Can the market slot carry this much?
		cout << "Not enough storage in market slot!";
	else
		coal[slot] = quantity;
}

// Add Coal
void Market::addCoal(int quantity)
{
	if (resourceBank[0] == 0) // Does the bank have enough to give?
		cout << "\nNot enough coal in the bank";
	else if (resourceBank[0] < quantity) {
		quantity = resourceBank[0];
		resourceBank[0] = 0;
	}
	else
	{
		resourceBank[0] -= quantity;
		while (quantity > 0) {
			for (int i = 8; i > 0; i--) {
				if (coal[i] < 3) {
					if (coal[i] + quantity >= 3) {
						quantity = quantity - (3 - coal[i]);
						std::cout << "\nAdding " << quantity << " coal to market slot " << i;
						coal[i] = 3;
						break;
					}
					else if (coal[i] + quantity < 3) {
						std::cout << "\nAdding " << quantity << " coal to market slot " << i;
						coal[i] = coal[i] + quantity;
						quantity = 0;
						break;
					}
				}
			}
		}
	}
}

// Remove coal
void Market::removeCoal(int slot, int quantity)
{
	if (slot < 0 || slot > 8) // Does the market slot hold that specific resource?
		cout << "This market slot doesn't carry coal!";
	else if (quantity > coal[slot]) // Does the market slot have enough to give?
		cout << "Not enough coal in the market!";
	else
		coal[slot] -= quantity;
}


// Get Oil
int Market::getOil(int slot)
{
	if (slot < 0 || slot > 8) // Does the market slot hold that specific resource?
		return 0;
	else
		return oil[slot];
}

// Set Oil
void Market::setOil(int slot, int quantity)
{
	if (slot < 0 || slot > 8) // Does the market slot hold that specific resource?
		cout << "This market slot cannot hold oil!";
	else if (quantity > 3) // Can the market slot carry this much?
		cout << "Not enough storage in market slot!";
	else
		oil[slot] = quantity;
}

// Add Oil
void Market::addOil(int quantity)
{
	if (resourceBank[1] == 0) // Does the bank have enough to give?
		cout << "\nNot enough oil in the bank";
	else if (resourceBank[1] < quantity) {
		quantity = resourceBank[1];
		resourceBank[1] = 0;
	}
	else
	{
		resourceBank[1] -= quantity;
		while (quantity > 0) {
			for (int i = 8; i > 0; i--) {
				if (oil[i] < 3) {
					if (oil[i] + quantity >= 3) {
						quantity = quantity - (3 - oil[i]);
						std::cout << "\nAdding " << quantity << " oil to market slot " << i;
						oil[i] = 3;
						break;
					}
					else if (oil[i] + quantity < 3) {
						std::cout << "\nAdding " << quantity << " oil to market slot " << i;
						oil[i] = oil[i] + quantity;
						quantity = 0;
						break;
					}
				}
			}
		}
	}
}

// Remove Oil
void Market::removeOil(int slot, int quantity)
{
	if (slot < 0 || slot > 8) // Does the market slot hold that specific resource?
		cout << "This market slot doesn't carry oil!";
	else if (quantity > oil[slot]) // Does the market slot have enough to give?
		cout << "Not enough oil in the market!";
	else
		oil[slot] -= quantity;
}


// Get Garbage
int Market::getGarbage(int slot)
{
	if (slot < 0 || slot > 8) // Does the market slot hold that specific resource?
		return 0;
	else
		return garbage[slot];
}

// Set Garbage
void Market::setGarbage(int slot, int quantity)
{
	if (slot < 0 || slot > 8) // Does the market slot hold that specific resource?
		cout << "This market slot cannot hold garbage!";
	else if (quantity > 3) // Can the market slot carry this much?
		cout << "Not enough storage in market slot!";
	else
		garbage[slot] = quantity;
}

// Add Garbage
void Market::addGarbage(int quantity)
{
	if (resourceBank[2] == 0) // Does the bank have enough to give?
		cout << "\nNot enough garbage in the bank";
	else if (resourceBank[2] < quantity) {
		quantity = resourceBank[2];
		resourceBank[2] = 0;
	}
	else
	{
		resourceBank[2] -= quantity;
		while (quantity > 0) {
			for (int i = 8; i > 0; i--) {
				if (garbage[i] < 3) {
					if (garbage[i] + quantity >= 3) {
						quantity = quantity - (3 - garbage[i]);
						std::cout << "\nAdding " << quantity << " garbage to market slot " << i;
						garbage[i] = 3;
						break;
					}
					else if (garbage[i] + quantity < 3) {
						std::cout << "\nAdding " << quantity << " garbage to market slot " << i;
						garbage[i] = garbage[i] + quantity;
						quantity = 0;
						break;
					}
				}
			}
		}
	}
}

// Remove Garbage
void Market::removeGarbage(int slot, int quantity)
{
	if (slot < 0 || slot > 8) // Does the market slot hold that specific resource?
		cout << "This market slot doesn't carry garbage!";
	else if (quantity > garbage[slot]) // Does the market slot have enough to give?
		cout << "Not enough garbage in the market!";
	else
		garbage[slot] -= quantity;
}


// Get Uranium
int Market::getUranium(int slot)
{
	if (slot < 0 || slot > 16) // Does the market slot hold that specific resource?
		return 0;
	else
		return uranium[slot];
}

// Set Uranium
void Market::setUranium(int slot, int quantity)
{
	if (slot < 0 || slot > 16) // Does the market slot hold that specific resource?
		cout << "This market slot cannot hold uranium!";
	else if (quantity > 1) // Can the market slot carry this much?
		cout << "Not enough storage in market slot!";
	else
		uranium[slot] = quantity;
}

// Add Uranium
void Market::addUranium(int quantity)
{
	if (resourceBank[3] == 0) // Does the bank have enough to give?
		cout << "\nNot enough coal in the bank";
	else if (resourceBank[3] < quantity) {
		quantity = resourceBank[3];
		resourceBank[3] = 0;
	}
	else
	{
		resourceBank[3] -= quantity;
		while (quantity > 0) {
			for (int i = 16; i > 0; i--) {
				if (i != 15 && i != 13 && i != 11 && i != 9) {
					if (uranium[i] < 1) {
						quantity = quantity - 1;
						std::cout << "\nAdding 1 uranium to market slot " << i;
						uranium[i] = 1;
						break;
					}
				}
			}
		}
	}
}

// Remove Uranium
void Market::removeUranium(int slot, int quantity)
{
	if (slot < 0 || slot > 16) // Does the market slot hold that specific resource?
		cout << "This market slot doesn't carry uranium!";
	else if (quantity > uranium[slot]) // Does the market slot have enough to give?
		cout << "Not enough uranium in the market!";
	else
		uranium[slot] -= quantity;
}

void Market::purchasePowerPlant(Player & player, int index, int cost) {
	player.setResource(Resource::Elektro, player.getResource(Resource::Elektro) - cost);
	availablePowerPlants[index].owner = &player;
	availablePowerPlants.erase(availablePowerPlants.begin() + index);
}

void Market::replenishPowerPlants(vector<PowerPlant> & remainingPOwerPlants) {
	this->availablePowerPlants = remainingPOwerPlants;
}

vector<PowerPlant>& Market::getAvailablePowerPlants() {
	return availablePowerPlants;
}

void Market::BidPowerPlants(vector<Player> & players) {

	// Controls whether or not we're in the bidding phase.
	bool biddingPhase = true;

	while (biddingPhase) {
		cout << "Starting a new round of bidding." << endl;

		// Display all power plants.
		for (int i = 0; i < 8; i++) {
			auto plant = availablePowerPlants[i];

			// TODO: Add more plant information here.
			cout << "[" << i + 1 << "] Power Plant #" << plant.plantNumber << endl;
		}
		cout << endl;

		// Ask each player if they want to bid.
		bool wasThereABidThisRound = false;

		// Ask each player if they want to bid.
		for (int playerIndex = 0; playerIndex < players.size(); playerIndex++) {
			auto player = players[playerIndex];
			cout << "Player " << player.getName() << ", would you like to bid? (1 = yes, 0 = no): ";
			int response;
			cin >> response;

			// The player wants to bid.
			if (response == 1) {

				// re-use the response variable.
				response = -1;

				// While the response is not valid, ask the player what plant they want to make an auction on.
				while (response < 1 || response > 8) {
					cout << "What plant do you want to bid on? (enter a number between 1 and 8):";
					cin >> response;
				}

				int powerPlantForBid_Index = response - 1;
				auto powerPlantForBid = availablePowerPlants[powerPlantForBid_Index];

				// Figure out who wants to bid.
				int numberOfPlayersBidding = players.size();
				map<int, bool> isPlayerBidding;
				for (int i = 0; i < players.size(); i++) {
					response = -1;
					auto biddingPlayer = players[i];

					// Make sure we don't ask the same person who started the bid.
					if (i == playerIndex) {
						response = 1;
					}

					while (response != 0 && response != 1) {
						cout << "Player " << biddingPlayer.getName() << ", do you want to bid for this powerplant? (1 = yes, 0 = no):";
						cin >> response;
					}

					if (response == 1) {
						isPlayerBidding[i] = true;
					}
					else {
						numberOfPlayersBidding--;
						isPlayerBidding[i] = false;
					}
				}

				int highestBid = availablePowerPlants[powerPlantForBid_Index].getPlantNumber();
				int highestBid_PlayerIndex = playerIndex;
				while (numberOfPlayersBidding > 1) {
					for (int i = 0; i < players.size(); i++) {

						if (numberOfPlayersBidding == 1) {
							break;
						}

						// Ignore players who are not bidding.
						if (isPlayerBidding[i] == false) {
							continue;
						}

						auto biddingPlayer = players[i];

						int bid = -1;
						int playerMoney = biddingPlayer.getResource(Resource::Elektro);

						cout << "Current bid is: " << highestBid << endl;


						while (bid == -1) {
							cout << "Player " << biddingPlayer.getName() << ", how much do you want to bid?: ";
							cin >> bid;

							if (playerMoney < bid) {
								cout << "You only have " << playerMoney << " elektro." << endl;
								bid = -1;
							}
						}

						// If the bid is higher, consider them as the highest bid.
						// Otherwise, kick them out of the bid.
						if (bid > highestBid) {
							highestBid = bid;
							highestBid_PlayerIndex = i;
						}
						else {
							cout << "Bid is lower than the current highest." << endl;
							cout << biddingPlayer.getName() << " drops out of the bid." << endl;
							isPlayerBidding[i] = false;
							numberOfPlayersBidding--;
						}
					}
				}

				cout << "Bidding process has ended!" << endl;
				cout << "Sold for " << highestBid << endl;

				purchasePowerPlant(players[highestBid_PlayerIndex], powerPlantForBid_Index, highestBid);
				wasThereABidThisRound = true;
				break;
			}
		}

		// If there was no bid this round, stop bidding phase.
		if (!wasThereABidThisRound) {
			biddingPhase = false;
		}
	}
}