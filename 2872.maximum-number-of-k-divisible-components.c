// @leet start

static void
dfs(int v, int** g, int p, int* values, int k, int64_t* sum, int* res)
{
  *sum = values[v];
  for (int i = 1; i <= g[v][0]; ++i) {
    if (g[v][i] == p)
      continue;
    int64_t child_sum;
    dfs(g[v][i], g, v, values, k, &child_sum, res);
    if (child_sum % k == 0)
      ++(*res);
    else
      *sum += child_sum;
  }
}

int
maxKDivisibleComponents(int n,
                        int** edges,
                        int edgesSize,
                        int* edgesColSize,
                        int* values,
                        int valuesSize,
                        int k)
{
  int c[30000];
  memset(c, 0, n * sizeof *c);
  for (int i = 0; i < edgesSize; ++i)
    ++c[edges[i][0]], ++c[edges[i][1]];
  int* g[30000];
  for (int i = 0; i < n; ++i) {
    g[i] = calloc(c[i] + 1, sizeof *g[i]);
    g[i][0] = 0;
  }
  for (int i = 0; i < edgesSize; ++i) {
    int v = edges[i][0], u = edges[i][1];
    g[v][++g[v][0]] = u;
    g[u][++g[u][0]] = v;
  }

  int ans = 0;
  int64_t sum = 0;
  dfs(0, g, -1, values, k, &sum, &ans);

  for (int i = 0; i < n; ++i)
    free(g[i]);

  return ans + 1;
}

// @leet end