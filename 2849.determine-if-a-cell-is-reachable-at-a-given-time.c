#include <stdlib.h>
#define max(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = a;                                                     \
    __typeof__(b) _b = b;                                                     \
    _a > _b ? _a : _b;                                                        \
  })

bool
isReachableAtTime(int sx, int sy, int fx, int fy, int t)
{
  if (sx == fx && sy == fy)
    return t != 1;
  return t >= max(abs(sx - fx), abs(sy - fy));
}