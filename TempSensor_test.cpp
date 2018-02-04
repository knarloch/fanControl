#include "TempSensor.h"
#include "gtest/gtest.h"

TEST(TempSensor_test, canRead)
{
    EXPECT_TRUE(15.0 <= TempSensor{}.get());
    EXPECT_TRUE(150.0 >= TempSensor{}.get());
}