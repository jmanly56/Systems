#ifndef UTIL_H
#define UTIL_H

#define PI 3.14159

enum Direction { CW, CCW };

enum Action {
        None,
        Accelerate,
        Decelerate,
        TurnRight,
        TurnLeft,
        Stop,
};

enum EventQueueStatus {
        Empty,
        EventsPending,
};

struct Position {
        float x;
        float y;
};

extern float frametime;

inline double degreesToRadians(double degrees)
{
        return (degrees * PI) / 180;
}

void updateFrametime();
#endif // UTIL_H
