#include <graphics.h>

char* p = _vp + (y*_width + x)*2;


#define POS(x, y) (_vp + ((y)*_width + (x))*2)

#define HIBYTE(x) (((x) >> 8) & 0x0F)

#define LOBYTE(x) ((x) & 0x0F)

#define SetTextAttribute(ptr, bg, fg) (*(ptr) = (((bg) << 4) | (fg)))