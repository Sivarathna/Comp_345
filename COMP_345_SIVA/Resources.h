#pragma once
#include <string>

enum Resource : int 
{
	Coal = 0,
	Oil,
	Garbage,
	Uranium,
	Elektro,
	RESOURCE_COUNT
};

std::string GetResourceName(Resource r);