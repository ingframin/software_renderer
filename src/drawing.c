#include "drawing.h"
#include <stdbool.h>
#include <stdint.h>
#include <SDL2/SDL.h>
#include "geometry.h"


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

void drawTriangle(SDL_Surface* surface,Triangle2 T, Color color){
    drawLine(surface,T.A.x,T.A.y,T.B.x,T.B.y,color);
    drawLine(surface,T.B.x,T.B.y,T.C.x,T.C.y,color);
    drawLine(surface,T.C.x,T.C.y,T.A.x,T.A.y,color);
    
    double minY = T.A.y;
    if(T.B.y < minY) minY = T.B.y;
    if(T.C.y < minY) minY = T.C.y;
    if(minY < 0) minY = 0;

    double minX = T.A.x;
    if(T.B.x < minX) minX = T.B.x;
    if(T.C.x < minX) minX = T.C.x;
    if(minX < 0) minX = 0;

    double maxY = T.A.y;
    if(T.B.y > maxY) maxY = T.B.y;
    if(T.C.y > maxY) maxY = T.C.y;
    if(maxY > surface->h) maxY = surface->h;

    double maxX = T.A.x;
    if(T.B.x > maxX) maxX = T.B.x;
    if(T.C.x > maxX) maxX = T.C.x;
    if(maxX > surface->w) maxX = surface->w;

    SDL_LockSurface(surface);
    Color* pixels = surface->pixels;
    for(int x = minX; x < maxX; x+=1){
        for(int y = minY; y < maxY; y+=1){
            Vector2 p = {x,y};

            if(inside(p,T)){
                pixels[(x+(surface->h-y)*surface->w)] = color;
            }
        }    
    }
    SDL_UnlockSurface(surface);

    
}