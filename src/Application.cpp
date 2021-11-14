#include "Application.h"

namespace Chess {
		Application::Application(){
				SDL_Init(SDL_INIT_EVERYTHING);
                Board game;
                game.CreateWindow();
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
                                        int w = game.GetBoardWidth();
                                        int h = game.GetBoardHeight();
                                        int screen_w = game.Width;
                                        int screen_h = game.Height;
                                        std::cout << "board size, w: " << w << " x h: " << h << std::endl;
                                        std::cout << "screen size, w: " << screen_w << " x h: " << screen_h << std::endl;
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
