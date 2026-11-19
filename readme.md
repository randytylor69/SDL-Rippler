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
                case SDLK_q:
                    /* do something? */
            }
    }
}
```
