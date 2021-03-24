#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include "SDL2/SDL.h"

bool running = true;
SDL_Window* wnd;
SDL_Surface* screen;

void drawLine(SDL_Surface* surface,int x0, int y0, int x1, int y1, uint32_t color){
    bool steep = false; 
    if (abs(x0-x1) < abs(y0-y1)) { // if the line is steep, we transpose the image 
        int t = x0;
        x0 = y0;
        y0 = t;
        t = x1;
        x1 = y1;
        y1 = t;
        steep = true; 
    } 

    if (x0>x1) { // make it left−to−right 
        int t = x0;
        x0 = x1;
        x1 = t;
        t = y0;
        y0 = y1;
        y1 = t;
         
    } 
    
        
    SDL_LockSurface(surface);

    /* Surface is locked */
    /* Direct pixel access on surface here */
    uint32_t* pixels = surface->pixels;
    for (int x=x0; x<=x1; x++) { 
        float t = (x-x0)/(float)(x1-x0); 
        int y = y0*(1.-t) + y1*t; 
        if (steep) { 
            pixels[(y+(surface->h-x)*surface->w)]=color;// if transposed, de−transpose 
        } else { 
            pixels[(x+(surface->h-y)*surface->w)]=color;
        } 
        
    } 

    SDL_UnlockSurface(surface);

}

int main(int argc, char** argv){
    SDL_Init(SDL_INIT_EVERYTHING);
    wnd = SDL_CreateWindow("SW Renderer",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1280,720,SDL_WINDOW_SHOWN);
    screen = SDL_GetWindowSurface(wnd);
    SDL_Surface *surface;
    Uint32 rmask, gmask, bmask, amask;
    rmask = 0xff000000;
    gmask = 0x00ff0000;
    bmask = 0x0000ff00;
    amask = 0x000000ff;
    surface = SDL_CreateRGBSurface(0, 1280, 720, 32, rmask, gmask, bmask, amask);


    SDL_Event evt;

    while(running){
         while(SDL_PollEvent(&evt)){
            
            if(evt.type == SDL_QUIT){
                running = false;
            }
        }

       drawLine(surface,20, 20, 180, 200,0x0000ffff);
       drawLine(surface,20, 200, 180, 100,0x00ff00ff);

        SDL_BlitSurface(surface,NULL,screen,NULL);
    
        SDL_UpdateWindowSurface(wnd);
    }
    SDL_Quit();
    return 0;
}