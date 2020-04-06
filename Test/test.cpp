#include "pch.h"
#include "../CalculatorStaticLibrary/Calculator.h"

TEST(Calculator, HandlesOutOfBounds) {
    ASSERT_THROW(Calculator::CalculateLevelCost(0, 31), std::runtime_error);
}

TEST(Calculator, HandlesIncorrectOrder)
{
    ASSERT_THROW(Calculator::CalculateLevelCost(10, 9), std::runtime_error);
}

TEST(Calculator, HandlesSameLevel)
{
    ASSERT_THROW(Calculator::CalculateLevelCost(10, 10), std::runtime_error);
}

TEST(Calculator, HandlesCalculatingLevel0To1)
{
    auto Cost = Calculator::CalculateLevelCost(0, 1);
    EXPECT_EQ(Cost.first, 10);
    EXPECT_EQ(Cost.second, 5);
}

TEST(Calculator, HandlesCalculatingLevel0To30)
{
    auto Cost = Calculator::CalculateLevelCost(0, 30);
    EXPECT_EQ(Cost.first, 11570);
    EXPECT_EQ(Cost.second, 5165);
}