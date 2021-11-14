#pragma once
#include <SDL2/SDL.h>
#include "Window.h"

namespace Chess {
    class Board : public Window {
        public:
            void Render();
            void Resize();
            int GetBoardHeight(){ return BoardYBoxes * BoxHeightY; }
            int GetBoardWidth(){ return BoardXBoxes * BoxWidthX; }
        private:
            SDL_Color m_Dark = {93, 50, 49, 1};
            SDL_Color m_Light = {121,72,57,1};
            SDL_Rect m_Rect;
            int BoardXBoxes = 8;
            int BoardYBoxes = 8;
            int BoxWidthX = Window::Width / BoardXBoxes;
            int BoxHeightY = Window::Height / BoardYBoxes;
    };
}
