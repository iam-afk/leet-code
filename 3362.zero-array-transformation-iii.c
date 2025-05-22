// @leet start
#define HEAP_S(type, cmp, field)                                                                   \
  static void heap_swap_##type(type* a, int i, int j)                                              \
  {                                                                                                \
    type t = a[i];                                                                                 \
    a[i] = a[j];                                                                                   \
    a[j] = t;                                                                                      \
  }                                                                                                \
  static void heap_sift_up_##type(type* a, int i)                                                  \
  {                                                                                                \
    while (a[i] field cmp a[(i - 1) / 2] field) {                                                  \
      heap_swap_##type(a, i, (i - 1) / 2);                                                         \
      i = (i - 1) / 2;                                                                             \
    }                                                                                              \
  }                                                                                                \
  static void heap_sift_down_##type(type* a, int n, int i)                                         \
  {                                                                                                \
    while (2 * i + 1 < n) {                                                                        \
      int l = 2 * i + 1, r = 2 * i + 2;                                                            \
      int j = l;                                                                                   \
      if (r < n && a[r] field cmp a[l] field)                                                      \
        j = r;                                                                                     \
      if (a[i] field cmp a[j] field)                                                               \
        break;                                                                                     \
      heap_swap_##type(a, i, j);                                                                   \
      i = j;                                                                                       \
    }                                                                                              \
  }
#define heap_push(type, a, n, ...)                                                                 \
  a[n] = (type){ __VA_ARGS__ };                                                                    \
  heap_sift_up_##type(a, n++);
#define heap_pop(type, a, n)                                                                       \
  ({                                                                                               \
    heap_swap_##type(a, 0, --n);                                                                   \
    heap_sift_down_##type(a, n, 0);                                                                \
    a[n];                                                                                          \
  })
#define HEAP(type, cmp) HEAP_S(type, cmp, )

HEAP(int, >)

static int
compare_queues(void const* lhs, void const* rhs)
{
  int const *a = *(int const* const*)lhs, *b = *(int const* const*)rhs;
  return (*a > *b) - (*a < *b);
}

int
maxRemoval(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize)
{
  qsort(queries, queriesSize, sizeof *queries, compare_queues);
  int d[100001];
  memset(d, 0, numsSize * sizeof *d);
  int a[100000], n = 0;
  int inc = 0;
  for (int i = 0, j = 0; i < numsSize; ++i) {
    inc += d[i];
    while (j < queriesSize && queries[j][0] == i) {
      heap_push(int, a, n, queries[j][1]);
      ++j;
    }
    while (inc < nums[i] && n > 0 && a[0] >= i) {
      ++inc;
      --d[heap_pop(int, a, n) + 1];
    }
    if (inc < nums[i])
      return -1;
  }
  return n;
}
// @leet end