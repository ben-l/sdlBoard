#pragma once
#include <SDL.h>
#include <iostream>
#include "Window.h"

namespace Chess {
    class Application : public Window {
        private:
            bool quit = false;
        public:
            Application();
            ~Application();
    };
}
