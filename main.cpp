#include <chrono>
#include <thread>
#include "TempSensor.h"
#include "PController.h"
#include "Limiter.h"
#include "FanSpeed.h"

int main()
{
    auto sensor = TempSensor{};
    auto pController = PController{{40, -0.02}};
    auto limiter = Limiter{{0.2, 0.0, 1.0, 1.0}};
    auto fanSpeed = FanSpeed{};

    while(true){
        auto now = std::chrono::steady_clock::now();
        fanSpeed.set(limiter.applyLimit(pController.getControl(sensor.get())));
        std::this_thread::sleep_until(now + std::chrono::seconds{1});
    }
    return 0;

}