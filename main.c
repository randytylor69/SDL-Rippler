#include <SDL2/SDL.h>
#include <stdio.h>

#define SCREEN_W 640
#define SCREEN_H 480

int is_running = 1;

int main(){
    SDL_Init(SDL_INIT_VIDEO);

    /* Init necessary pointers */
    SDL_Event event;
    SDL_Window* pWindow = SDL_CreateWindow(
	    "The Rippler", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
	    SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN
    );
    SDL_Surface* pSurface = SDL_GetWindowSurface(pWindow);
    SDL_Renderer* pRenderer = SDL_CreateRenderer(pWindow, -1,0);

    /* Configure renderer (background) */
    SDL_SetRenderDrawColor(pRenderer, 255,0,0,255);
    SDL_RenderClear(pRenderer);   // clear screen to target color
    SDL_RenderPresent(pRenderer); // show target color 

    /* _________________________________________________________________ */
    
    while(is_running){
	SDL_UpdateWindowSurface(pWindow);

	/* detect keypress */
	while(SDL_PollEvent(&event)){
	    switch(event.type){
		case SDL_KEYDOWN:

		    /* check which key is pressed */
		    switch(event.key.keysym.sym){
			case SDLK_q:
			    is_running = 0; // quit program on 'q'
			    break;
		    }
	    }
	}


	SDL_Delay(20);
    }

    return 0;
}
