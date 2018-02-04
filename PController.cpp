#include "PController.h"

double PController::getControl(double input) {
    return (settings.setPoint - input) * settings.P;
}
