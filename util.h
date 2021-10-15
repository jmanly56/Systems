#ifndef PHYSICS_H
#define PHYSICS_H

extern float frametime;

float displacement(float v_x, float a_x, float d_t);

void updateFrametime();
#endif // PHYSICS_H