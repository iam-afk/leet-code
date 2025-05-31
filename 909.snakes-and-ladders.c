// @leet start
typedef struct state
{
  int k;
  int l;
  int r, c;
} state;

#define queue_push(type, q, t, ...) q[t++] = (type){ __VA_ARGS__ };
#define queue_pop(type, q, h) q[h++]

static void
label_to_row_col(int label, int n, int* row, int* col)
{
  *row = label / n;
  *col = label % n;
  if (*row & 1)
    *col = n - 1 - *col;
  *row = n - 1 - *row;
}

#define min(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = (a);                                                   \
    __typeof__(b) _b = (b);                                                   \
    _a < _b ? _a : _b;                                                        \
  })

int
snakesAndLadders(int** board, int boardSize, int* boardColSize)
{
#define N 20
  const int n = boardSize;
  state q[N * N];
  int h = 0, t = 0;
  int u[N * N] = {};
  queue_push(state, q, t, .k = 0, .l = 0, .r = n - 1, .c = 0);
  u[0] = true;

  int tr, tc;
  label_to_row_col(n * n - 1, n, &tr, &tc);

  while (h < t) {
    state s = queue_pop(state, q, h);
    if (s.r == tr && s.c == tc)
      return s.k;
    for (int i = s.l + 1; i <= min(s.l + 6, n * n - 1); ++i) {
      int r, c, l = i;
      label_to_row_col(l, n, &r, &c);
      if (board[r][c] > 0)
        label_to_row_col(l = board[r][c] - 1, n, &r, &c);
      if (!u[l]) {
        queue_push(state, q, t, .k = s.k + 1, .l = l, .r = r, .c = c);
        u[l] = true;
      }
    }
  }

  return -1;
}
// @leet end