#ifndef FANCONTROLER_TEMPSENSOR_H
#define FANCONTROLER_TEMPSENSOR_H
#include <string>


class TempSensor {
public:
    double get();

    struct Settings {
        std::string tempInputPath;
        double inputToDegreesC;
    };

    TempSensor(Settings s = {"/sys/class/drm/card0/device/hwmon/hwmon1/temp1_input", 0.001}) : settings{s} {};
private:
    Settings settings;
};


#endif
