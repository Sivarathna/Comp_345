#include "playerView.h"
#include "Player.h"
#include <Windows.h>
#include <string>


playerView::playerView()
{
}


playerView::~playerView()
{
}


// Update, when called with an object and integer indicating the type of update to perform
// Sets a string to form a message indicating all the most updated information 
// Viewer object uses the Windows API to display updated information to the screen in the form of a popup
// Any time information is changed and the appropriate notify function is called, this function will execute
void playerView::update(Subject* ob)
{
	Player* player = (Player*)ob;

	cout << "Player Name: " << player->getName() << endl;
	cout << "Player House Colour: " << GetColorName(player->getHouseColor()) << endl;
	cout <<"Player Resource: "<< player->getResource(Resource::Elektro) << endl;
	
}