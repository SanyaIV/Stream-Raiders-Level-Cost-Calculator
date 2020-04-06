#include "CalculatorStaticLibrary/Calculator.h"
#include <iostream>
#include <limits>
#include <utility>

int main()
{
    unsigned int FromLevel, ToLevel;

    while (true)
    {
        std::cout << "Input current level and desired level (0, 0 to exit): ";

        try
        {
            std::cin >> FromLevel >> ToLevel;
            if (std::cin.fail()) throw std::runtime_error("Invalid input"); // If input fails we throw so we can catch it properly.
            if (FromLevel == 0 && ToLevel == 0) return 0; // Input to exit.

            std::pair<unsigned int, unsigned int> Cost = Calculator::CalculateLevelCost(FromLevel, ToLevel);
            std::cout << "Cost to go from level " << FromLevel << " to level " << ToLevel << " is " << Cost.first << " Gold and " << Cost.second << " Scrolls." << std::endl << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return 0;
}