#ifndef PHYSICS_H
#define PHYSICS_H

extern float frametime;

float displacement(float v, float a, float d_t);

float updateVelocity(float v, float a, float d_t);

void updateFrametime();
#endif // PHYSICS_H