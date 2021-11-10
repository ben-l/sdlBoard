#pragma once
#include <SDL.h>

namespace Chess {
    class Board {
        public:
            void Render();
            SDL_Renderer* m_Renderer;
        private:
            SDL_Color m_Dark = {0,0,0,255};
            SDL_Color m_Light = {255,255,255,255};
            SDL_Rect m_Rect;
            int BoardXBoxes = 8;
            int BoardYBoxes = 8;
            int BoxWidthX = 720 / BoardXBoxes;
            int BoxHeightY = 720 / BoardYBoxes;
    };
}
