#pragma once
#include <string>

enum Color : int
{
	Red = 0,
	Blue,
	Green,
	Purple,
	Orange,
	Yellow,
	COLOR_COUNT
};

std::string GetColorName(Color c);