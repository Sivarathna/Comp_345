#include "ResourceTable.h"

int GetResourceCost(Resource r, int phase, int numberOfPlayers)
{
	// We assume number of players is not 0 based. Neither is phase.
	phase -= 1;
	numberOfPlayers -= 1;

	int table[60] = {
		3, 4, 3, 4, 5, 3, 5, 6, 4, 5, 7, 5, 7, 9, 6,
		2, 2, 4, 2, 3, 4, 3, 4, 5, 4, 5, 6, 5, 6, 7,
		1, 2, 3, 1, 2, 3, 2, 3, 4, 3, 3, 5, 3, 5, 6,
		1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 3, 2, 2, 3, 3
	};

	return table[15 * r + 3 * (numberOfPlayers - 1) + phase];
}
