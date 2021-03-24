#include "drawing.h"
#include <stdbool.h>
#include <stdint.h>
#include <SDL2/SDL.h>



void drawLine(SDL_Surface* surface,int x0, int y0, int x1, int y1, Color color){
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
    Color* pixels = surface->pixels;
    for (int x=x0; x<=x1; x++) { 
        float t = (x-x0)/(float)(x1-x0); 
        int y = y0*(1.-t) + y1*t; 
        if (steep) { 
            pixels[(y+(surface->h-x)*surface->w)] = color;// if transposed, de−transpose 
        } else { 
            pixels[(x+(surface->h-y)*surface->w)] = color;
        } 
        
    } 

    SDL_UnlockSurface(surface);

}