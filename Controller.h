#ifndef FANCONTROL_CONTROLLER_H

struct Controller
{
    virtual double getControl(double temperature) = 0;
    virtual ~Controller() = default;
};
#define FANCONTROL_CONTROLLER_H

#endif //FANCONTROL_CONTROLLER_H
