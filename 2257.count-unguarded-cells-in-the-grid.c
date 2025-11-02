// @leet start
int
countUnguarded(int m,
               int n,
               int** guards,
               int guardsSize,
               int* guardsColSize,
               int** walls,
               int wallsSize,
               int* wallsColSize)
{
  int (*g)[n] = calloc(m * n, sizeof(int));
  memset(g, 0, m * n * sizeof(int));
  for (int i = 0; i < guardsSize; ++i)
    g[guards[i][0]][guards[i][1]] = 1;
  for (int i = 0; i < wallsSize; ++i)
    g[walls[i][0]][walls[i][1]] = 1;
  for (int i = 0; i < guardsSize; ++i) {
    int dr = 0, dc = 1;
    for (int k = 0; k < 4; ++k) {
      int r = guards[i][0] + dr, c = guards[i][1] + dc;
      while (0 <= r && r < m && 0 <= c && c < n && g[r][c] != 1) {
        g[r][c] = 2;
        r += dr, c += dc;
      }
      int t = dr;
      dr = dc, dc = -t;
    }
  }

  int ans = 0;
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
      ans += g[i][j] == 0;
  free(g);
  return ans;
}
// @leet end