#include <SDL2/SDL.h>
#include <stdio.h>

#define SCREEN_W 640
#define SCREEN_H 480

int quit = 0;
int travelling = 0; // is the ball travelling between 2 mouse clicks?


void draw_filled_circle(SDL_Renderer *renderer, int32_t centre_x, int32_t centre_y, int32_t r){
    
    /* circle colour */ 
    SDL_SetRenderDrawColor(renderer, 110, 181, 158, 255);
    int32_t d = r*2;

    for (int32_t w = 0; w <= d; w++){
	for (int32_t h = 0; h <= d; h++){
	    /* the tuple (w,h) will iterate overall all positions of the square that encapsulates
	     * the circle we're trying to draw */
	    int32_t dx = r-w;
	    int32_t dy = r-h;
	    if (dx*dx + dy*dy <= r*r){
		SDL_RenderDrawPoint(renderer, centre_x + dx, centre_y + dy);
	    }
	}
    }
    /* until now the points are only at a buffer; we need to flush it */
    SDL_RenderPresent(renderer); // flushes the points to screen
    /* reset renderer color to bg color */
    SDL_SetRenderDrawColor(renderer, 51,51,51,255);
    
}

void update_centres(int *mouseX, int *mouseY, int new_mouseX, int new_mouseY, int *circle_size, int d){
    /* d is the distance between each small updates */
    if (*mouseX != new_mouseX || *mouseY != new_mouseY){
	if (*mouseX > new_mouseX) *mouseX -= d;
	else *mouseX += d;
	if (*mouseY > new_mouseY) *mouseY -= d;
	else *mouseY +=d;
	printf("Updated: %d, %d, %d, %d\n", *mouseX, *mouseY, new_mouseX, new_mouseY);
    }
}

int main(){
    SDL_Init(SDL_INIT_VIDEO);

    /* Init necessary pointers */
    SDL_Event event;
    SDL_Window* pWindow = SDL_CreateWindow(
	    "The Rippler", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
	    SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN
    );
    SDL_Renderer* pRenderer = SDL_CreateRenderer(pWindow, -1,0);

    /* Configure renderer (background) */
    SDL_SetRenderDrawColor(pRenderer, 51,51,51,255);
    SDL_RenderClear(pRenderer);   // clear screen to target color
    SDL_RenderPresent(pRenderer); // show target color 
    
    int mouseX = SCREEN_W / 2;
    int mouseY = SCREEN_H / 2;
    int new_mouseX = mouseX;
    int new_mouseY = mouseY;
    int circle_size = 30;

    /* _________________________________________________________________ */
    
    while(!quit){

	while(SDL_PollEvent(&event)){
	    switch(event.type){

		/* detect keypress */
		case SDL_KEYDOWN:

		    /* check which key is pressed */
		    switch(event.key.keysym.sym){
			case SDLK_q:
			    quit = 1;
			    break;
		    }
		    break;

		/* detect mousepress */
		case SDL_MOUSEBUTTONDOWN:

		    /* onclick -> get new mouse positions */
		    SDL_GetMouseState(&new_mouseX, &new_mouseY);
		    break;
	    }
	}
	update_centres(&mouseX, &mouseY, new_mouseX, new_mouseY, &circle_size, 10);
	draw_filled_circle(pRenderer, mouseX, mouseY, circle_size); 
	SDL_RenderClear(pRenderer);
	SDL_Delay(400);
    }

    return 0;
}
