#include "Application.h"

namespace Chess {
		Application::Application(){
				SDL_Init(SDL_INIT_EVERYTHING);
                Board game;
                game.CreateWindow();
				game.PrintAllBoards();
				while(!quit){
                    game.Render();
					while( SDL_WaitEvent( &Event ) ){
    					switch( Event.type ){
                            case SDL_WINDOWEVENT:
                                switch(Event.window.event){
                                    case SDL_WINDOWEVENT_CLOSE:
                                        quit=true;
                                        SDL_Quit();
                                        break;
                                    case SDL_WINDOWEVENT_RESIZED:
										game.Render();
                                        break;
                                }
							case SDL_QUIT:
								quit = true;
								break;
							case SDL_KEYDOWN:
							  switch(Event.key.keysym.sym){
							  	case SDLK_q:
							  		std::cout << "\"Q\" pressed" << std::endl;
							  		quit = true;	
							  		SDL_Quit();
							  		break;
                                case SDLK_r:
                                    game.Render();
                                    break;
							  }
    					}
  					}
				}
		}
		Application::~Application(){
		}
}
