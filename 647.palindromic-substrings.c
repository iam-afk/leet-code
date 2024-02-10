// @leet start
#define N ((size_t)1e3)

int
countSubstrings(char* s)
{
  int n = strlen(s);
  bool d[2][N] = { [0 ... 1] = { [0 ... N - 1] = true } };
  int a = n;
  for (int k = 1, p = 0; k < n; ++k, p = 1 - p)
    for (int i = 0; i + k < n; ++i)
      if ((d[p][i] = s[i] == s[i + k] && d[p][i + 1]))
        ++a;
  return a;
}
// @leet end