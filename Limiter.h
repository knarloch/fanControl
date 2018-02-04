#ifndef FANCONTROLER_LIMITER_H
#define FANCONTROLER_LIMITER_H


struct Limiter {
    double applyLimit(double input);
    struct Settings{
        double minInput;
        double minOutput;
        double maxInput;
        double maxOutput;
    };

    Limiter(Settings s) : settings{s}{};
private:
    Settings settings;
};

#endif