//
// Created by hypys on 2/4/18.
//

#include "Limiter.h"

double Limiter::applyLimit(double input) {
    if(input < settings.minInput)
        return settings.minOutput;
    if(input > settings.maxInput)
        return settings.maxOutput;
    return input;
}
