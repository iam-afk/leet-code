// @leet start
#define max(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a > _b ? _a : _b;                                                                             \
  })

#define HEAP_S(type, field)                                                                        \
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
#define HEAP(type) HEAP_S(type, )

typedef struct
{
  int t, r, c;
} E;

HEAP_S(E, .t)

int
minTimeToReach(int** moveTime, int moveTimeSize, int* moveTimeColSize)
{
  int n = moveTimeSize, m = moveTimeColSize[0];

  int d[50][50] = { [0 ... 49] = { [0 ... 49] = INT_MAX } };

  E q[50 * 50 * 2];
  int len = 0;

  d[0][0] = 0;
  q[0] = (E){}, ++len;

  while (len > 0) {
    E e = q[0];
    swap_E(q, 0, --len);
    sift_down_E(q, len, 0);
    if (e.r == n - 1 && e.c == m - 1)
      break;
    int dr = 0, dc = -1;
    for (int i = 0; i < 4; ++i) {
      int nr = e.r + dr, nc = e.c + dc;
      if (0 <= nr && nr < n && 0 <= nc && nc < m) {
        int t = max(e.t, moveTime[nr][nc]) + 1;
        if (t < d[nr][nc]) {
          d[nr][nc] = t;
          q[len] = (E){ .t = t, .r = nr, .c = nc };
          sift_up_E(q, len++);
        }
      }

      {
        int t = dr;
        dr = dc, dc = -t;
      }
    }
  }
  return d[n - 1][m - 1];
}
// @leet end