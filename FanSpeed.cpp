#include "FanSpeed.h"
#include <fstream>
#include <algorithm>

void FanSpeed::set(double x) {
    std::ofstream{settings.pwmEnableNode} << "1";

    int pwm = static_cast<int>(x * settings.pwmMax);
    pwm = std::min(pwm, settings.pwmMax);
    pwm = std::max(pwm, settings.pwmMin);

    std::ofstream{settings.pwmNode} << pwm;
}
