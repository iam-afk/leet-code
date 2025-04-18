// @leet start
#include <string.h>
char*
countAndSay(int n)
{
  char p[2][5000] = { [0] = { '1' } };
  int m = 1;
  for (int i = 1; i < n; ++i) {
    int c = 1, x = 0;
    for (int j = 1; j < m; ++j) {
      if (p[~i & 1][j - 1] != p[~i & 1][j]) {
        p[i & 1][x++] = c + '0';
        p[i & 1][x++] = p[~i & 1][j - 1];
        c = 0;
      }
      ++c;
    }
    p[i & 1][x++] = c + '0';
    p[i & 1][x++] = p[~i & 1][m - 1];
    m = x;
  }
  char* ret = calloc(m + 1, sizeof *ret);
  memcpy(ret, p[~n & 1], m);
  ret[m] = 0;
  return ret;
}
// @leet end