#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include "Board.h"

namespace Chess {
    class Application : public Window {
        private:
            bool quit = false;
        public:
            Application();
            ~Application();
    };
}
