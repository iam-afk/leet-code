// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define max(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a > _b ? _a : _b;                                                                             \
  })

static void
dfs(int v, int p, int** t, int i, int* even, int* odd, int* c)
{
  if (c)
    c[v] = i & 1;
  *even = 1, *odd = 0;
  for (int j = 1; j <= t[v][0]; ++j)
    if (t[v][j] != p) {
      int child_even = 0, child_odd = 0;
      dfs(t[v][j], v, t, i + 1, &child_even, &child_odd, c);
      *even += child_odd;
      *odd += child_even;
    }
}

static int**
build(int** edges, int edges_size)
{
  int* tc = calloc(edges_size + 1, sizeof *tc);
  memset(tc, 0, (edges_size + 1) * sizeof *tc);
  for (int i = 0; i < edges_size; ++i) {
    int a = edges[i][0], b = edges[i][1];
    ++tc[a], ++tc[b];
  }
  int** t = calloc(edges_size + 1, sizeof *t);
  for (int i = 0; i <= edges_size; ++i) {
    t[i] = calloc(tc[i] + 1, sizeof *t[i]);
    t[i][0] = 0;
  }
  for (int i = 0; i < edges_size; ++i) {
    int a = edges[i][0], b = edges[i][1];
    t[a][++t[a][0]] = b;
    t[b][++t[b][0]] = a;
  }
  free(tc);
  return t;
}

int*
maxTargetNodes(int** edges1,
               int edges1Size,
               int* edges1ColSize,
               int** edges2,
               int edges2Size,
               int* edges2ColSize,
               int* returnSize)
{
  int** t2 = build(edges2, edges2Size);
  int mx, even, odd;
  dfs(0, -1, t2, 0, &even, &odd, 0);
  mx = max(even, odd);
  for (int i = 0; i <= edges2Size; ++i)
    free(t2[i]);
  free(t2);

  int** t1 = build(edges1, edges1Size);

  int* t = calloc(edges1Size + 1, sizeof *t);
  dfs(0, -1, t1, 0, &even, &odd, t);

  *returnSize = edges1Size + 1;
  int* ret = calloc(*returnSize, sizeof *ret);
  for (int i = 0; i <= edges1Size; ++i)
    ret[i] = (t[i] ? odd : even) + mx;

  free(t);
  for (int i = 0; i <= edges1Size; ++i)
    free(t1[i]);
  free(t1);

  return ret;
}
// @leet end