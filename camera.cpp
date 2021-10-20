#include "camera.h"

Camera::Camera()
{
        rect = {0, 0, 0, 0};
        target_w = 0;
        target_h = 0;
}

void Camera::setCameraSize(int w, int h)
{
#ifdef DEBUG
        if (w <= 0 || h <= 0)
                std::cerr << "Invalid camera size.\n";
#endif
        rect.h = h > 0 ? h : 0;
        rect.w = w > 0 ? w : 0;
}

void Camera::setTargetSize(int w, int h)
{
#ifdef DEBUG
        if (w <= 0 || h <= 0)
                std::cerr << "Invalid camera  target size.\n";
#endif
        target_h = h > 0 ? h : 0;
        target_w = w > 0 ? w : 0;
}

void Camera::updateCamera(float playerX, float playerY)
{
        rect.x = (playerX + (target_w / 2)) - (rect.w / 2);
        rect.y = (playerY + (target_h / 2)) - (rect.h / 2);
}
