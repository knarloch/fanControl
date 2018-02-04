#include "gtest/gtest.h"
#include "FanSpeed.h"

TEST(FanSpeed_test, canSetPWM)
{
    auto fan = FanSpeed{};
    fan.set(0);
    fan.set(0.4);
}

