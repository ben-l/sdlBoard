#pragma once
#include <SDL.h>
#include <iostream>
#include "Board.h"

namespace Chess {
    class Window : public Board {
        public:
            SDL_Event m_Event;
            SDL_Window* m_Window;
            SDL_Surface* m_Screen;
            const int GetHeight() { return m_Height; }
            const int GetWidth() { return m_Width; }
            Window();
            ~Window();
        private:
            int m_Height = 720;
            int m_Width = 720;
            int SetRGBA(int r, int g, int b, int a)
            {
                return SDL_MapRGBA(m_Screen->format, r, g, b, a); 
            }
    };
}
