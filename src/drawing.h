#ifndef DRAWING_H
#define DRAWING_H
#include <SDL2/SDL.h>

typedef union CC{
    uint32_t value;
    struct color{
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
    } color;
    
} Color;

void drawLine(SDL_Surface* surface,int x0, int y0, int x1, int y1, Color color);



#endif