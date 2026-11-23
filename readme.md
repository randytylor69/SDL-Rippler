# Notes

This tiny project is soly purposed to practice the basics of SDL2. 

It emulates a rippling orb that follows between mouse clicks.

### 1. Render a Window

We only need the `SDL_Window` & `SDL_Renderer` pointers, **excluding** the `SDL_Surface` pointer (spent lotta time debugging ts):

```c

SDL_Window* pWindow = SDL_CreateWindow(/* whatever specs */);
SDL_Renderer* pRenderer = SDL_CreateRenderer(pWindow, -1,0);

/* Configure renderer (background) */
SDL_SetRenderDrawColor(pRenderer, 255,0,0,255); // red background
SDL_RenderClear(pRenderer);   // clear screen 
SDL_RenderPresent(pRenderer); // show target color 

```

### 2. Detect Keyboard Events

First instantiate an `event` object:

```c
SDL_Event event;
```

Then go through 2 levels of switches to obtain keypresses; for example, `SDLK_q` is for key `q`.

```c
while(SDL_PollEvent(&event)){
    switch(event.type){
        case SDL_KEYDOWN:

            /* check which key is pressed */
            switch(event.key.keysym.sym){
                case SDLK_q: /* do something? */
            }
        break;
    }
}
```

### 3. Detect mouse press

This one is straightforward, it also uses the previously defined `SDL_Event event` instance. First define the global mouse position variables outside the gameloop:

```c
int mouse_x, mouse_y;
```

Then, inside the loop, feed it the current mouse position per mouse click:

```c
while(SDL_PollEvent(&event)){
    switch(event.type){
        /* detect mousepress */
        case SDL_MOUSEBUTTONDOWN:
            SDL_GetMouseState(&mouse_x, &mouse_y);
    }
}
```

### 4. Drawing a filled circle

```c

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
```

It's important that we call `SDL_RenderPresent()` after getting all required points; else the points will stay in the buffer and not render on the screen.
