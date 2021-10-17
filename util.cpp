#include "util.h"
#include <chrono>
#include <cmath>

float frametime = 0.0;
static std::chrono::high_resolution_clock frame_clock;
static std::chrono::time_point<std::chrono::high_resolution_clock> prevtime = frame_clock.now();

void updateFrametime()
{
        auto curTime = frame_clock.now();
        frametime
                = std::chrono::duration_cast<std::chrono::microseconds>(curTime - prevtime).count()
                  * 0.000001;
        prevtime = curTime;
}
