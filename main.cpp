#include "CalculatorStaticLibrary/Calculator.h"
#include <iostream>
#include <limits>
#include <utility>
#include <string>

// Forward declarations
void QueryInput(std::string Query, unsigned int& OutVar);
void ClearInputBuffer();

int main()
{
    unsigned int FromLevel = 0;
    unsigned int ToLevel = 0;

    std::cout << "Stream Raiders Level Cost Calculator (q to exit)" << std::endl;
    std::cout << "Only calculates level costs for non-legendary units." << std::endl << std::endl;

    while (true)
    {
        try
        {
            QueryInput("From Level: ", FromLevel);
            QueryInput("To Level: ", ToLevel);

            std::pair<unsigned int, unsigned int> Cost = Calculator::CalculateLevelCost(FromLevel, ToLevel);
            std::cout << "Cost to go from level " << FromLevel << " to level " << ToLevel << " is " << Cost.first << " Gold and " << Cost.second << " Scrolls." << std::endl << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl << std::endl;
        }
        catch (const std::string& e)
        {
            if (e == "Quit") return 0;
        }
    }

    return 0;
}

/**
 * Query the user for input with a question.
 * @param Query - The question to ask the user.
 * @param OutVar - A reference to the variable to store the user input.
 */
void QueryInput(std::string Query, unsigned int& OutVar)
{
    ClearInputBuffer();

    // Print question and get input.
    std::cout << Query;
    std::cin >> OutVar;

    if (std::cin.fail())
    {
        std::cin.clear(); // Clear the flags so we can properly read from the buffer.
        char* Buffer = new char[1]; // Prepare a char array of length 1 since cin.read() requires an array.
        std::cin.read(Buffer, 1);
        if (Buffer[0] == 'q' || Buffer[0] == 'Q') throw "Quit"; // Throw "Quit" to signal the program to quit.
        else throw std::runtime_error("Invalid input"); // If input fails we throw so we can catch it properly.
    }
}

/** Clears the input buffer to prepare reading user input. */
void ClearInputBuffer()
{
    std::cin.seekg(0, std::cin.end); // Set cin to the end of the buffer. Pretty much equivalent to cin.ignore() but without risking waiting for user input. Will trigger a flag.
    std::cin.clear(); // Clear the flag seekg caused.
}