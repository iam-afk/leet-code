// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define max(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = (a);                                                   \
    __typeof__(b) _b = (b);                                                   \
    _a > _b ? _a : _b;                                                        \
  })

static int
dfs(int v, int p, int (*t)[1000], int i, int k)
{
  int r = 1;
  if (i == k)
    return r;
  for (int j = 1; j <= t[v][0]; ++j)
    if (t[v][j] != p)
      r += dfs(t[v][j], v, t, i + 1, k);
  return r;
}

int t[1000][1000];

int*
maxTargetNodes(int** edges1,
               int edges1Size,
               int* edges1ColSize,
               int** edges2,
               int edges2Size,
               int* edges2ColSize,
               int k,
               int* returnSize)
{
  int c2 = 0;
  for (int i = 0; i <= edges2Size; ++i)
    t[i][0] = 0;
  for (int i = 0; i < edges2Size; ++i) {
    int a = edges2[i][0], b = edges2[i][1];
    t[a][++t[a][0]] = b;
    t[b][++t[b][0]] = a;
  }

  if (k > 0)
    for (int i = 0; i <= edges2Size; ++i)
      c2 = max(c2, dfs(i, -1, t, 0, k - 1));

  for (int i = 0; i <= edges1Size; ++i)
    t[i][0] = 0;
  for (int i = 0; i < edges1Size; ++i) {
    int a = edges1[i][0], b = edges1[i][1];
    t[a][++t[a][0]] = b;
    t[b][++t[b][0]] = a;
  }
  *returnSize = edges1Size + 1;
  int* ret = calloc(*returnSize, sizeof *ret);
  for (int i = 0; i <= edges1Size; ++i)
    ret[i] = dfs(i, -1, t, 0, k) + c2;
  return ret;
}
// @leet end