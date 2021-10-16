#ifndef UTIL_H
#define UTIL_H

struct Position {
        float x;
        float y;
};

extern float frametime;

float displacement(float v, float a, float d_t);

float updateVelocity(float v, float a, float d_t);

void updateFrametime();
#endif // UTIL_H