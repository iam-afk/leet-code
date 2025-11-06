/*
 * @lc app=leetcode id=3607 lang=c
 *
 * [3607] Power Grid Maintenance
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define HEAP_S(type, cmp, field)                                              \
  static void heap_swap_##type(type* a, int i, int j)                         \
  {                                                                           \
    type t = a[i];                                                            \
    a[i] = a[j];                                                              \
    a[j] = t;                                                                 \
  }                                                                           \
  static void heap_sift_up_##type(type* a, int i)                             \
  {                                                                           \
    while (a[i] field cmp a[(i - 1) / 2] field) {                             \
      heap_swap_##type(a, i, (i - 1) / 2);                                    \
      i = (i - 1) / 2;                                                        \
    }                                                                         \
  }                                                                           \
  static void heap_sift_down_##type(type* a, int n, int i)                    \
  {                                                                           \
    while (2 * i + 1 < n) {                                                   \
      int l = 2 * i + 1, r = 2 * i + 2;                                       \
      int j = l;                                                              \
      if (r < n && a[r] field cmp a[l] field)                                 \
        j = r;                                                                \
      if (a[i] field cmp a[j] field)                                          \
        break;                                                                \
      heap_swap_##type(a, i, j);                                              \
      i = j;                                                                  \
    }                                                                         \
  }
#define heap_push(type, a, n, ...)                                            \
  a[n] = (type){ __VA_ARGS__ };                                               \
  heap_sift_up_##type(a, n++);
#define heap_pop(type, a, n)                                                  \
  ({                                                                          \
    heap_swap_##type(a, 0, --n);                                              \
    heap_sift_down_##type(a, n, 0);                                           \
    a[n];                                                                     \
  })
#define HEAP(type, cmp) HEAP_S(type, cmp, )

HEAP(int, <)

int *parent, *rank;

static int
dsu_find(int v)
{
  if (v != parent[v])
    parent[v] = dsu_find(parent[v]);
  return parent[v];
}

static void
dsu_union(int v, int u)
{
  int root_v = dsu_find(v), root_u = dsu_find(u);
  if (root_v != root_u) {
    if (rank[root_v] < rank[root_u])
      parent[root_v] = root_u;
    else if (rank[root_v] > rank[root_u])
      parent[root_u] = root_v;
    else {
      parent[root_v] = root_u;
      ++rank[root_u];
    }
  }
}

int*
processQueries(int c,
               int** connections,
               int connectionsSize,
               int* connectionsColSize,
               int** queries,
               int queriesSize,
               int* queriesColSize,
               int* returnSize)
{
  parent = calloc(c + 1, sizeof *parent);
  rank = calloc(c + 1, sizeof *rank);
  for (int i = 1; i <= c; ++i) {
    parent[i] = i;
    rank[i] = 0;
  }
  for (int i = 0; i < connectionsSize; ++i) {
    int v = connections[i][0], u = connections[i][1];
    dsu_union(v, u);
  }

  struct
  {
    int *q, n;
  }* grids = calloc(c + 1, sizeof *grids);
  memset(grids, 0, c * sizeof *grids);
  for (int i = 1; i <= c; ++i)
    ++grids[dsu_find(i)].n;
  for (int i = 1; i <= c; ++i)
    if (grids[i].n > 0) {
      grids[i].q = calloc(grids[i].n, sizeof(int));
      grids[i].n = 0;
    }
  for (int i = 1; i <= c; ++i) {
    int root = parent[i];
    heap_push(int, grids[root].q, grids[root].n, i);
  }

  int* ret = calloc(queriesSize, sizeof *ret);
  *returnSize = 0;

  bool* offline = calloc(c + 1, sizeof *offline);
  memset(offline, 0, c * sizeof *offline);
  for (int i = 0; i < queriesSize; ++i) {
    int t = queries[i][0], x = queries[i][1];
    switch (t) {
      case 1: {
        int a = x;
        if (offline[x]) {
          int j = dsu_find(x);
          while (grids[j].n > 0 && offline[grids[j].q[0]])
            heap_pop(int, grids[j].q, grids[j].n);
          a = grids[j].n > 0 ? grids[j].q[0] : -1;
        }
        ret[(*returnSize)++] = a;
      } break;
      case 2:
        offline[x] = true;
        break;
    }
  }

  return ret;
}
// @lc code=end
