#pragma once
#include <chrono>

namespace Utility
{
    class TimeService
    {
    public:
        TimeService();
        ~TimeService();

        void initialize();
        void update();
        float getDeltaTime();

    private:
        std::chrono::steady_clock::time_point previous_time;
        float delta_time;

        void updateDeltaTime();
        float calculateDeltaTime();
        void updatePreviousTime();
    };
}
