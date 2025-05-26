// @leet start
static int
compare_edges(void const* lhs, void const* rhs)
{
  int *a = *(int* const*)lhs, *b = *(int* const*)rhs;
  return (*a > *b) - (*a < *b);
}

#define max(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a > _b ? _a : _b;                                                                             \
  })

typedef struct
{
  int n, m;
  int* indices;
  int** edges;
  bool* visited;
  bool* stacked;
  char* colors;
} context;

static bool
dfs(int v, context* ctx, int (*dp)[26], int* ans)
{
  if (ctx->stacked[v])
    return false;
  if (ctx->visited[v])
    return true;
  ctx->stacked[v] = true;
  ctx->visited[v] = true;
  memset(dp[v], 0, sizeof(dp[v]));
  for (int i = ctx->indices[v]; i < ctx->m && ctx->edges[i][0] == v; ++i) {
    int u = ctx->edges[i][1];
    if (!dfs(u, ctx, dp, ans))
      return false;
    for (int c = 0; c < 26; ++c) {
      dp[v][c] = max(dp[v][c], dp[u][c]);
      *ans = max(*ans, dp[v][c]);
    }
  }
  dp[v][ctx->colors[v] - 'a'] += 1;
  *ans = max(*ans, dp[v][ctx->colors[v] - 'a']);
  ctx->stacked[v] = false;
  return true;
}

int
largestPathValue(char* colors, int** edges, int edgesSize, int* edgesColSize)
{
  int n = strlen(colors);
  int indices[100000];
  bool visited[100000];
  memset(visited, 0, n * sizeof *visited);
  bool stacked[100000];
  memset(stacked, 0, n * sizeof *stacked);
  context ctx = { .n = n,
                  .m = edgesSize,
                  .indices = indices,
                  .edges = edges,
                  .visited = visited,
                  .stacked = stacked,
                  .colors = colors };

  qsort(edges, edgesSize, sizeof *edges, compare_edges);
  for (int i = 0, j = 0; i < n; ++i) {
    indices[i] = j < edgesSize && edges[j][0] == i ? j : edgesSize;
    while (j < edgesSize && edges[j][0] <= i)
      ++j;
  }

  int dp[100000][26];

  int ans = 0;
  for (int i = 0; i < n; ++i)
    if (!dfs(i, &ctx, dp, &ans))
      return -1;

  return ans;
}
// @leet end