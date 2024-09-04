// @leet start

#define max(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a > _b ? _a : _b;                                                                             \
  })

static int
compareInts(void const* a, void const* b)
{
  int const* p1 = *(int const* const*)a;
  int const* p2 = *(int const* const*)b;
  return p1[0] != p2[0] ? p1[0] - p2[0] : p1[1] - p2[1];
}

int
robotSim(int* commands, int commandsSize, int** obstacles, int obstaclesSize, int* obstaclesColSize)
{
  qsort(obstacles, obstaclesSize, sizeof(int*), compareInts);
  int x = 0, y = 0;
  int dx = 0, dy = 1;
  int mx = 0;
  for (int i = 0; i < commandsSize; ++i) {
    if (commands[i] == -2) {
      int t = dx;
      dx = -dy;
      dy = t;
    } else if (commands[i] == -1) {
      int t = dx;
      dx = dy;
      dy = -t;
    } else {
      for (int j = 0; j < commands[i]; ++j) {
        int n[] = { x + dx, y + dy };
        int* key = n;
        if (bsearch(&key, obstacles, obstaclesSize, sizeof(int*), compareInts))
          break;
        x = n[0], y = n[1];
      }
    }
    mx = max(mx, x * x + y * y);
  }
  return mx;
}
// @leet end