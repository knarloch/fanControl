#ifndef FANCONTROLER_TEST_FANSPEED_H
#define FANCONTROLER_TEST_FANSPEED_H
#include <string>

class FanSpeed {
public:
    void set(double);

    struct Settings {
        std::string pwmNode = "/sys/class/drm/card0/device/hwmon/hwmon1/pwm1";
        std::string pwmEnableNode = "/sys/class/drm/card0/device/hwmon/hwmon1/pwm1_enable";
        int pwmMax = 255;
        int pwmMin = 0;
    };
private:
    Settings settings;
};

#endif
