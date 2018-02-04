#include "TempSensor.h"
#include <iostream>
#include <fstream>

double TempSensor::get() {
    std::filebuf fb;
    std::ifstream ifstream{settings.tempInputPath};
    double tempRaw;
    ifstream >> tempRaw;
    return tempRaw * settings.inputToDegreesC;
}
