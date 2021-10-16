#include "util.h"
#include <chrono>
#include <math.h>

float frametime = 0.0;
static std::chrono::high_resolution_clock frame_clock;
static std::chrono::time_point<std::chrono::high_resolution_clock> prevtime = frame_clock.now();

float displacement(float v, float a, float d_t)
{
        return (v * d_t) + ((0.5) * pow(d_t, 2.0) * a);
}

float adjust_velocity(float v, float a, float d_t)
{
        return v + (a * d_t);
}

void updateFrametime()
{
        auto curTime = frame_clock.now();
        frametime
                = std::chrono::duration_cast<std::chrono::microseconds>(curTime - prevtime).count()
                  * 0.000001;
        prevtime = curTime;
}
