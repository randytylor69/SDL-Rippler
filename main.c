#include <SDL2/SDL.h>
#include <stdio.h>

int is_running = 1;

int main(){
    /* Declare program type */
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Event event;

    /* Init window */
    SDL_Window* pWindow = SDL_CreateWindow(
	    "The Rippler", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
	    1000, 1000, 0
    );
    SDL_Surface* pSurface = SDL_GetWindowSurface(pWindow);

    /* Draw Rect */
    SDL_Rect rect = {200, 200, 100, 100}; // x, y, w, h
    SDL_FillRect(pSurface, &rect, 0xffffff);
    
    /* ______________________________________________________________________ */

    while(is_running){
	SDL_UpdateWindowSurface(pWindow);

	/* detect keypress */
	while(SDL_PollEvent(&event)){
	    switch(event.type){
		case SDL_KEYDOWN:

		    /* check which key is pressed */
		    switch(event.key.keysym.sym){
			case SDLK_q:
			    is_running = 0;
			    break;
		    }
	    }
	}


	SDL_Delay(20);
    }

    return 0;
}
