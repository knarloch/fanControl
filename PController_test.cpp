#include "gtest/gtest.h"
#include "PController.h"

TEST(Pcontroller_test, whenSetPoint_noControl) {
    auto settings = std::vector<PController::Settings>{
            {0.0,  0.0},
            {0.0,  9.0},
            {9.0,  0.0},
            {45.0, -12.0}};
    for (const auto &s : settings) {
        ASSERT_EQ(0.0, PController{s}.getControl(s.setPoint));
    }
}

TEST(Pcontroller_test, whenNotInSetPoint_usesP) {
    auto settings = std::vector<PController::Settings>{
            {0.0,  0.0},
            {0.0,  9.0},
            {9.0,  0.0},
            {45.0, -12.0}};
    auto inputs = {1.0, 0.0, 3.14, 100000.1};
    for (const auto &input : inputs) {
        for (const auto &s : settings) {
            ASSERT_EQ((s.setPoint - input) * s.P, PController{s}.getControl(input));
        }
    }
}