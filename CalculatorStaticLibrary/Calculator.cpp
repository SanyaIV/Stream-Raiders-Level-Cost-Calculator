#include "Calculator.h"
#include <stdexcept>
#include <vector>

std::pair<unsigned int, unsigned int> Calculator::CalculateLevelCost(unsigned int FromLevel, unsigned int ToLevel)
{
    // Pair of cost to upgrade from that level to the next level <Gold, Scrolls>. Index in vector represents the level. Costs taken from https://streamraiders.fandom.com/wiki/Unit_Leveling at 2020-04-05.
    static const std::vector<std::pair<unsigned int, unsigned int>> LevelCosts{
        std::make_pair(10, 5),
        std::make_pair(25, 15),
        std::make_pair(35, 20),
        std::make_pair(50, 25),
        std::make_pair(100, 50),
        std::make_pair(120, 60),
        std::make_pair(140, 70),
        std::make_pair(160, 80),
        std::make_pair(180, 90),
        std::make_pair(200, 100),
        std::make_pair(220, 110),
        std::make_pair(240, 120),
        std::make_pair(260, 130),
        std::make_pair(280, 140),
        std::make_pair(300, 150),
        std::make_pair(320, 160),
        std::make_pair(340, 170),
        std::make_pair(360, 180),
        std::make_pair(380, 190),
        std::make_pair(400, 200),
        std::make_pair(450, 220),
        std::make_pair(500, 240),
        std::make_pair(550, 260),
        std::make_pair(600, 280),
        std::make_pair(675, 300),
        std::make_pair(750, 320),
        std::make_pair(825, 340),
        std::make_pair(900, 360),
        std::make_pair(1000, 380),
        std::make_pair(1200, 400)
    };

    std::pair<unsigned int, unsigned int> LevelCostSum{ 0, 0 };

    if (FromLevel >= ToLevel || FromLevel >= LevelCosts.size() || ToLevel > LevelCosts.size()) throw std::runtime_error("Invalid levels");

    for (unsigned int Level = FromLevel; Level < ToLevel; ++Level)
    {
        LevelCostSum.first += LevelCosts[Level].first;
        LevelCostSum.second += LevelCosts[Level].second;
    }

    return LevelCostSum;
}