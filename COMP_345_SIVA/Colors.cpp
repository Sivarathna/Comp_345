#include "Colors.h"

std::string GetColorName(Color c)
{
	switch (c) {
		case Color::Red:
			return "Red";
		case Color::Blue:
			return "Blue";
		case Color::Green:
			return "Green";
		case Color::Purple:
			return "Purple";
		case Color::Orange:
			return "Orange";
		case Color::Yellow:
			return "Yellow";
		default:
			throw;
	}
}