#include "Window.h"

namespace Chess {
    void Window::CreateWindow()
    {
        Window = SDL_CreateWindow("Chess!", 
						SDL_WINDOWPOS_UNDEFINED, 
						SDL_WINDOWPOS_UNDEFINED, 
					    Width,	
                        Height,
						SDL_WINDOW_RESIZABLE);
		if(Window == nullptr){
			std::cout << SDL_GetError() << std::endl;
		}else{
			std::cout << "Window created" << std::endl;
		}

        if(IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG){
            std::cout << "Failed to initialize SDL_Image" << std::endl;
        }

		Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);

        if(Renderer == nullptr){
            std::cout << "Failed to create Renderer" << std::endl;
		}else{
			std::cout << "Renderer created" << std::endl;
        }
    }

    SDL_Texture* Window::LoadTexture(std::string path){
        SDL_Texture* texture = NULL;
        SDL_Surface* surface = IMG_Load(path.c_str());
        if(surface == NULL){
            printf("Failed to load image, %s\n", IMG_GetError());
        } 
        else 
        { // create texture
            SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
            texture = SDL_CreateTextureFromSurface(Renderer, surface);
            if(texture == NULL)
            {
                std::cout << "Failed to load texture" << std::endl;
            }
            SDL_FreeSurface(surface);
        }
        return texture;
    }

    bool Window::LoadTextureImage(std::string path){
        bool success = true;
        Texture = LoadTexture(path);
        if(Texture == NULL){
            std::cout << "Failed to load texture Image" << std::endl;
            success = false;
        }
        return success;
    }

	void Window::ResizeWindow(int newWidth, int newHeight)
	{
        Width = newWidth;
        Height = newHeight;
	}

    Window::~Window()
    {
		SDL_DestroyRenderer(Renderer);
		std::cout << "Renderer destroyed" << std::endl;
		SDL_DestroyWindow(Window);
		std::cout << "Window destroyed" << std::endl;
        IMG_Quit();
    }
}
