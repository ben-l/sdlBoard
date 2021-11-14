#pragma once 
#include <iostream>
#include <SDL2/SDL.h>

namespace Chess {
    class Piece {
        public:
            Piece(std::string color, SDL_Texture* texture, float posx, float posy);
            ~Piece();
        private:
            std::string m_Color;
            SDL_Texture* m_Texture;
            int m_Height;
            int m_Width;
            float m_PosX;
            float m_PosY;
    };
}
