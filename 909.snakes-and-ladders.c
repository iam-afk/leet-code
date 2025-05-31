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
  {                                                                                                \
    a[n] = (type){ __VA_ARGS__ };                                                                  \
    heap_sift_up_##type(a, n++);                                                                   \
  }
#define heap_pop(type, a, n)                                                                       \
  ({                                                                                               \
    heap_swap_##type(a, 0, --n);                                                                   \
    heap_sift_down_##type(a, n, 0);                                                                \
    a[n];                                                                                          \
  })
#define HEAP(type, cmp) HEAP_S(type, cmp, )

typedef struct state
{
  int k;
  int l;
  int r, c;
  int p;
} state;

HEAP_S(state, <, .k)

static void
label_to_row_col(int label, int n, int* row, int* col)
{
  *row = label / n;
  *col = label % n;
  if (*row & 1)
    *col = n - 1 - *col;
  *row = n - 1 - *row;
}

#define min(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a < _b ? _a : _b;                                                                             \
  })

int
snakesAndLadders(int** board, int boardSize, int* boardColSize)
{
  state a[20 * 20];
  int n = 0;
  int u[20 * 20] = {};
  heap_push(state, a, n, .k = 0, .l = 0, .r = boardSize - 1, .c = 0, .p = -1);
  u[0] = true;

  int tr, tc;
  label_to_row_col(boardSize * boardSize - 1, boardSize, &tr, &tc);

  while (n > 0) {
    state s = heap_pop(state, a, n);
    if (s.r == tr && s.c == tc)
      return s.k;
    for (int i = s.l + 1; i <= min(s.l + 6, boardSize * boardSize - 1); ++i) {
      int r, c, l = i;
      label_to_row_col(l, boardSize, &r, &c);
      if (board[r][c] > 0)
        label_to_row_col(l = board[r][c] - 1, boardSize, &r, &c);
      if (!u[l]) {
        heap_push(state, a, n, .k = s.k + 1, .l = l, .r = r, .c = c, .p = s.l);
        u[l] = true;
      }
    }
  }

  return -1;
}
// @leet end