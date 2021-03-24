#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include "SDL2/SDL.h"
#include "geometry.h"
#include "drawing.h"

bool running = true;
SDL_Window* wnd;
SDL_Surface* screen;
Vector2 v1 = {100.0,100.0};
Vector2 v2 = {300.0,10.0};
Vector2 v3 = {500.0,600.0};



int main(int argc, char** argv){
    SDL_Init(SDL_INIT_EVERYTHING);
    wnd = SDL_CreateWindow("SW Renderer",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1280,720,SDL_WINDOW_SHOWN);
    screen = SDL_GetWindowSurface(wnd);
    SDL_Surface *surface;
    Uint32 rmask, gmask, bmask, amask;
    rmask = 0x000000ff;
    gmask = 0x0000ff00;
    bmask = 0x00ff0000;
    amask = 0xff000000;
    surface = SDL_CreateRGBSurface(0, 1280, 720, 32, rmask, gmask, bmask, amask);
    
    Color red;
    red.color.r = 0xff;
    red.color.g = 0x00;
    red.color.b = 0x00;
    red.color.a = 0xff;
    Color green;
    green.color.r = 0x00;
    green.color.g = 0xff;
    green.color.b = 0;
    green.color.a = 0xff;

    SDL_Event evt;

    Triangle2 triangle;
    triangle.A = v1;
    triangle.B = v2;
    triangle.C = v3;

    while(running){
         while(SDL_PollEvent(&evt)){
            
            if(evt.type == SDL_QUIT){
                running = false;
            }
        }

        drawLine(surface,20, 20, 180, 200,red);
        drawLine(surface,20, 200, 180, 100,green);
        drawTriangle(surface,triangle,green);
        SDL_BlitSurface(surface,NULL,screen,NULL);
    
        SDL_UpdateWindowSurface(wnd);
    }
    SDL_Quit();
    return 0;
}