#pragma once
#include <utility>

class Calculator
{
public:
    /**
     * Calculates the total cost to upgrade a unit from one level to another.
     * @param FromLevel - The current level of the unit.
     * @param ToLevel - The desired level of the unit.
     * @return An std::pair containing the total cost in Gold first and total cost in Scrolls second.
     */
	static std::pair<unsigned int, unsigned int> CalculateLevelCost(unsigned int FromLevel, unsigned int ToLevel);
};

