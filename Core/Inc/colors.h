#pragma once

#define TRANSPARENT	0

#define RGB(r, b, g) (((r & 0b11111000)<<8) + ((g & 0b11111100)<<3)+(b>>3))

#define GRAY      RGB(127, 127, 127)
#define DARKGRAY  RGB(64, 64, 64)
#define LIGHTGRAY RGB(220, 220, 220)

#define RED	      RGB(255,0,0)
#define GREEN     RGB(0, 100, 0)
#define BLUE      RGB(0, 0, 255)

#define ORANGE    RGB(255,140,0)
#define BLACK 	  RGB(0,0,0)
#define WHITE	  RGB(255,255,255)
