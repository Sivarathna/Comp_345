#include "mapView.h"
#include "Map.h"
#include <Windows.h>
#include <string>

mapView::mapView()
{
	numberOfPurchases = 0;
}

mapView::~mapView()
{
}

void mapView::update(Subject * s)
{
	numberOfPurchases++;
	cout << "Total number of purchases were: " << numberOfPurchases << endl;
}

