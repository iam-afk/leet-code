// @leet start
int
findJudge(int n, int** trust, int trust_size, int* trunt_col_size)
{
  int f[1001] = { 0 }, t[1001] = { 0 };
  for (int i = 0; i < trust_size; ++i)
    ++f[trust[i][0]], ++t[trust[i][1]];
  for (int i = 1; i <= n; ++i)
    if (f[i] == 0 && t[i] == n - 1) {
      return i;
    }
  return -1;
}
// @leet end