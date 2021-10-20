#ifndef CAMERA_H
#define CAMERA_H

#include <SDL2/SDL.h>

class Camera
{
    public:
        Camera();
        ~Camera() = default;
        void setCameraSize(int w, int h);
        void setTargetSize(int w, int h);
        void updateCamera(float playerX, float playerY);

    private:
        friend class Graphics;
        SDL_Rect rect;
        int target_w;
        int target_h;
};

#endif // CAMERA_H
