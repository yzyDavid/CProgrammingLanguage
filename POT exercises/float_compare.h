#inclue <float.h>
#define FLT_EQUAL(x, y) (((x) - (y)) < 1E-6 && (x) - (y) > -1E-6) ? 1 : 0
