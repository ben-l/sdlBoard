#include "Window.h"

namespace Chess {
    Window::Window()
    {
        m_Window = SDL_CreateWindow("Chess!", 
						SDL_WINDOWPOS_UNDEFINED, 
						SDL_WINDOWPOS_UNDEFINED, 
					    GetWidth(),	
                        GetHeight(),
						SDL_WINDOW_RESIZABLE);
		if(m_Window == nullptr){
			std::cout << SDL_GetError() << std::endl;
		}else{
			std::cout << "Window created" << std::endl;
		}

		Board::m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);

        if(Board::m_Renderer == nullptr){
            std::cout << "Failed to create renderer" << std::endl;
		}
		Board::Render();
    }
    Window::~Window()
    {
		SDL_DestroyRenderer(Board::m_Renderer);
		std::cout << "Renderer destroyed" << std::endl;
		SDL_DestroyWindow(m_Window);
		std::cout << "Window destroyed" << std::endl;
    }
}
