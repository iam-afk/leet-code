// @leet start
static int
compare_points(void const* lhs, void const* rhs)
{
  int const* a = *(int const* const*)lhs;
  int const* b = *(int const* const*)rhs;
  return a[0] != b[0] ? (a[0] < b[0] ? -1 : 1)
                      : (a[1] == b[1]  ? 0
                         : a[1] < b[1] ? -1
                                       : 1);
}

#define min(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = (a);                                                   \
    __typeof__(b) _b = (b);                                                   \
    _a < _b ? _a : _b;                                                        \
  })

int
findMinArrowShots(int** points, int points_size, int* points_col_size)
{
  qsort(points, points_size, sizeof(int*), compare_points);
  int n = 0, ans = 0, mn = INT_MAX;
  for (int i = 0; i < points_size; ++i) {
    if (mn < points[i][0])
      ++ans, mn = INT_MAX;
    mn = min(mn, points[i][1]);
  }
  return ans + 1;
}
// @leet end