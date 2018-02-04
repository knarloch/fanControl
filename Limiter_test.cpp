#include "gtest/gtest.h"
#include "Limiter.h"

TEST(Limiter_test, whenInRange_outputIsNotChanged){
    auto inputs = {0.0, 1.0, 0.5};
    auto limiter = Limiter{{0.0, 0.0, 1.0, 1.0}};
    for(const auto &input : inputs){
        EXPECT_EQ(input, limiter.applyLimit(input));
    }
}

TEST(Limiter_test, whenLowerThanMinInput_outputIsMinOutput){
    auto settings = std::vector<Limiter::Settings>{
            {0.2, 0.0, 1.0, 1.0},
            {0.2, 0.1, 1.0, 1.0},
            {99, 0.1, 1.0, 1.0},
            {99, 11, 1.0, 1.0}};

    for(const auto &s : settings){
        EXPECT_EQ(s.minOutput, Limiter{s}.applyLimit(s.minInput - 0.01));
    }
}

TEST(Limiter_test, whenHigherThanMaxInput_outputIsMaxOutput){
    auto settings = std::vector<Limiter::Settings>{
            {0.0, 0.0, 1.0, 1.0},
            {0.0, 0.0, 1.0, 0.4},
            {0.0, 0.0, 99, 10}};

    for(const auto &s : settings){
        EXPECT_EQ(s.maxOutput, Limiter{s}.applyLimit(s.maxInput + 0.01));
    }
}