#include "Application.h"

namespace Chess {
		Application::Application(){
				SDL_Init(SDL_INIT_EVERYTHING);
				while(!quit){
					while( SDL_WaitEvent( &m_Event ) ){
    					switch( m_Event.type ){
							case SDL_QUIT:
								quit = true;
								break;
							case SDL_KEYDOWN:
							  switch(m_Event.key.keysym.sym){
							  	case SDLK_q:
							  		std::cout << "\"Q\" pressed" << std::endl;
							  		quit = true;	
							  		SDL_Quit();
							  		break;
							  }
    					}
  					}
					// still in while(!quit) loop
					// Renderer AKA draw to the screen
					//SDL_RenderClear(m_Renderer);
					// Do drawing
					//SDL_RenderPresent(m_Renderer);
				}
		}
		Application::~Application(){
		}
}
