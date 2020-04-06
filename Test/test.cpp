#include "pch.h"
#include "../CalculatorStaticLibrary/Calculator.h"

TEST(Calculator, HandlesOutOfBounds) {
    ASSERT_THROW(Calculator::CalculateLevelCost(0, 31), std::runtime_error);
}