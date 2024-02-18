// @leet start
#define HEAP(type, field)                                                                          \
  static void swap_##type(type* a, int i, int j)                                                   \
  {                                                                                                \
    type t = a[i];                                                                                 \
    a[i] = a[j];                                                                                   \
    a[j] = t;                                                                                      \
  }                                                                                                \
  static void sift_up_##type(type* a, int i)                                                       \
  {                                                                                                \
    while (a[i] field < a[(i - 1) / 2] field) {                                                    \
      swap_##type(a, i, (i - 1) / 2);                                                              \
      i = (i - 1) / 2;                                                                             \
    }                                                                                              \
  }                                                                                                \
  static void sift_down_##type(type* a, int n, int i)                                              \
  {                                                                                                \
    while (2 * i + 1 < n) {                                                                        \
      int l = 2 * i + 1, r = 2 * i + 2;                                                            \
      int j = l;                                                                                   \
      if (r < n && a[r] field < a[l] field)                                                        \
        j = r;                                                                                     \
      if (a[i] field < a[j] field)                                                                 \
        break;                                                                                     \
      swap_##type(a, i, j);                                                                        \
      i = j;                                                                                       \
    }                                                                                              \
  }

HEAP(int, )

HEAP(uint64_t, )

static int
compare_by_start(void const* a, void const* b)
{
  return (*(int* const*)a)[0] - (*(int* const*)b)[0];
}

int
mostBooked(int n, int** meetings, int meetings_size, int* meetings_col_size)
{
  qsort(meetings, meetings_size, sizeof *meetings, compare_by_start);

  int d[100] = { [0 ... 99] = 0 };

  int free[100], free_n = n;
  for (int i = 0; i < n; ++i)
    free[i] = i;

  uint64_t busy[100];
  int busy_n = 0;

  for (int i = 0; i < meetings_size; ++i) {
    while (busy_n > 0 && busy[0] >> 8 <= meetings[i][0]) {
      swap_uint64_t(busy, 0, --busy_n);
      sift_down_uint64_t(busy, busy_n, 0);
      free[free_n] = busy[busy_n] & 0xff;
      sift_up_int(free, free_n++);
    }

    uint64_t delay = 0;
    if (free_n == 0) {
      swap_uint64_t(busy, 0, --busy_n);
      sift_down_uint64_t(busy, busy_n, 0);
      delay = (busy[busy_n] >> 8) - meetings[i][0];
      free[free_n] = busy[busy_n] & 0xff;
      sift_up_int(free, free_n++);
    }
    swap_int(free, 0, --free_n);
    sift_down_int(free, free_n, 0);
    int r = free[free_n];
    busy[busy_n] = ((delay + meetings[i][1]) << 8) + r;
    sift_up_uint64_t(busy, busy_n++);
    ++d[r];
  }
  int r = 0, mx = 0;
  for (int i = 0; i < n; ++i) {
    if (mx < d[i])
      mx = d[i], r = i;
  }
  return r;
}
// @leet end