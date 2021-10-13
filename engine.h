#ifndef ENGINE_H
#define ENGINE_H

#include <memory>

class Graphics;
class Input;

class Engine
{
    public:
        Engine();
        void run();

    private:
        std::shared_ptr<Graphics> graphics;
        std::shared_ptr<Input> input;
    protected:
};

#endif // ENGINE_H