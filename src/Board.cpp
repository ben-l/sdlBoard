#include <iostream>
#include "Board.h"

namespace Chess {
	void Board::Render()
	{
        m_Rect.w = BoxWidthX;
        m_Rect.h = BoxHeightY;
        for(int x = 0; x < BoardXBoxes; x++){
            for(int y = 0; y < BoardYBoxes; y++){
                SDL_Color Color = (x + y) % 2 == 0 ? m_Dark : m_Light;
				m_Rect.x = x * BoxWidthX; 
				m_Rect.y = y * BoxHeightY;
                SDL_SetRenderDrawColor(Window::Renderer, Color.r, Color.g, Color.b, Color.a);
				SDL_RenderFillRect(Window::Renderer, &m_Rect);
                Window::LoadTextureImage("assets/textures/r256.png");
                SDL_RenderCopy(Window::Renderer, Window::Texture, NULL, &m_Rect);
            }
        }
        SDL_RenderPresent(Window::Renderer);
	}
}
