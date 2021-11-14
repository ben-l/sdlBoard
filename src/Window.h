#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

namespace Chess {
    class Window {
        public:
            SDL_Event Event;
            SDL_Window* Window = NULL;
            SDL_Surface* Surface;
            SDL_Renderer* Renderer = NULL;
            SDL_Texture* Texture = NULL;
            int Height = 728;
            int Width = 728;
            //const int GetHeight() { return m_Height; }
            //const int GetWidth() { return m_Width; }
            void CreateWindow();
            SDL_Texture* LoadTexture(std::string path);
            bool LoadTextureImage(std::string path);
            void ResizeWindow(int newWidth, int newHeight);
            ~Window();
        private:
            int SetRGBA(int r, int g, int b, int a)
            {
                return SDL_MapRGBA(Surface->format, r, g, b, a); 
            }
    };
}
