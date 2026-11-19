# Notes

This tiny project is soly purposed to practice the basics of SDL2. 

It emulates a rippling orb that follows between mouse clicks.

### Detect Keyboard Events

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
                    is_running = 0; // quit program on 'q'
                    break;
            }
    }
}
```
