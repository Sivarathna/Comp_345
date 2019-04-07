#include "Resources.h"

std::string GetResourceName(Resource r)
{
	switch (r) {
		case Resource::Coal:
			return "Coal";
		case Resource::Elektro:
			return "Elektro";
		case Resource::Garbage:
			return "Garbage";
		case Resource::Oil:
			return "Oil";
		case Resource::Uranium:
			return "Uranium";
		default:
			throw;
	}
}
