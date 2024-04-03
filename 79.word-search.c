// @leet start
static bool
find(char** board, int n, int m, int i, int j, char* w)
{
  if (!*w)
    return true;
  if (i < 0 || i >= m || j < 0 || j >= n || *w != board[i][j])
    return false;
  board[i][j] = 0;
  static int const di[] = { -1, 0, 1, 0 };
  static int const dj[] = { 0, -1, 0, 1 };
  bool f = false;
  for (int k = 0; !f && k < 4; ++k)
    f = find(board, n, m, i + di[k], j + dj[k], w + 1);
  board[i][j] = *w;
  return f;
}

bool
exist(char** board, int board_size, int* board_col_size, char* word)
{
  int m = board_size, n = board_col_size[0];
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
      if (find(board, n, m, i, j, word))
        return true;
  return false;
}

// @leet end