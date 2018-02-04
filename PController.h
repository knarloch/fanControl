#ifndef FANCONTROLER_PCONTROLLER_H
#define FANCONTROLER_PCONTROLLER_H

#include "Controller.h"

class PController : public Controller {
public:
    struct Settings {
        double setPoint;
        double P;
    };

    PController(Settings s) : settings{s} {};

    virtual double getControl(double input);


private:
    Settings settings;
};

#endif //FANCONTROLER_TEST_PCONTROLLER_H
