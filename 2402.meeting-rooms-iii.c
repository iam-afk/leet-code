// @leet start
#define HEAP_S(type, less)                                                    \
  static void swap_##type(type* a, int i, int j)                              \
  {                                                                           \
    type t = a[i];                                                            \
    a[i] = a[j];                                                              \
    a[j] = t;                                                                 \
  }                                                                           \
  static void sift_up_##type(type* a, int i)                                  \
  {                                                                           \
    while (less(a + i, a + (i - 1) / 2)) {                                    \
      swap_##type(a, i, (i - 1) / 2);                                         \
      i = (i - 1) / 2;                                                        \
    }                                                                         \
  }                                                                           \
  static void sift_down_##type(type* a, int n, int i)                         \
  {                                                                           \
    while (2 * i + 1 < n) {                                                   \
      int l = 2 * i + 1, r = 2 * i + 2;                                       \
      int j = l;                                                              \
      if (r < n && less(a + r, a + l))                                        \
        j = r;                                                                \
      if (less(a + i, a + j))                                                 \
        break;                                                                \
      swap_##type(a, i, j);                                                   \
      i = j;                                                                  \
    }                                                                         \
  }
#define HEAP(type) HEAP_S(type, less_##type)

static bool
less_int(int const* a, int const* b)
{
  return *a < *b;
}

typedef struct
{
  int room;
  int64_t end;
} meeting_t;

static bool
less_meeting_t(meeting_t const* a, meeting_t const* b)
{
  if (a->end == b->end)
    return a->room < b->room;
  return a->end < b->end;
}

HEAP(int)
HEAP(meeting_t)

static int
compare_by_start(void const* a, void const* b)
{
  return *(*(int* const*)a) - *(*(int* const*)b);
}

int
mostBooked(int n, int** meetings, int meetings_size, int* meetings_col_size)
{
  qsort(meetings, meetings_size, sizeof *meetings, compare_by_start);

  int d[100] = { [0 ... 99] = 0 };

  int free[100], free_n = n;
  for (int i = 0; i < n; ++i)
    free[i] = i;

  meeting_t busy[100];
  int busy_n = 0;

  for (int i = 0; i < meetings_size; ++i) {
    while (busy_n > 0 && busy[0].end <= meetings[i][0]) {
      swap_meeting_t(busy, 0, --busy_n);
      sift_down_meeting_t(busy, busy_n, 0);
      free[free_n] = busy[busy_n].room;
      sift_up_int(free, free_n++);
    }

    int64_t delay = 0;
    if (free_n == 0) {
      swap_meeting_t(busy, 0, --busy_n);
      sift_down_meeting_t(busy, busy_n, 0);
      delay = busy[busy_n].end - meetings[i][0];
      free[free_n] = busy[busy_n].room;
      sift_up_int(free, free_n++);
    }
    swap_int(free, 0, --free_n);
    sift_down_int(free, free_n, 0);
    int room = free[free_n];
    busy[busy_n] = (meeting_t){ .room = room, .end = delay + meetings[i][1] };
    sift_up_meeting_t(busy, busy_n++);
    ++d[room];
  }
  int r = 0, mx = 0;
  for (int i = 0; i < n; ++i)
    if (mx < d[i])
      mx = d[i], r = i;
  return r;
}
// @leet end