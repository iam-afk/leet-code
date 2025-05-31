// @leet start
#define max(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = (a);                                                   \
    __typeof__(b) _b = (b);                                                   \
    _a > _b ? _a : _b;                                                        \
  })

char*
shortestCommonSupersequence(char* str1, char* str2)
{
  int n, m;
  int d[1001][1001];
  d[0][0] = 0;
  for (n = 0; str1[n]; ++n)
    d[n + 1][0] = 0;
  for (m = 0; str2[m]; ++m)
    d[0][m + 1] = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      d[i][j] = str1[i - 1] == str2[j - 1] ? d[i - 1][j - 1] + 1
                                           : max(d[i - 1][j], d[i][j - 1]);
  int k = n + m - d[n][m];
  char* res = malloc(k + 1);
  res[k--] = 0;
  int i = n, j = m;
  while (i > 0 && j > 0)
    if (str1[i - 1] == str2[j - 1])
      res[k--] = str1[i - 1], --i, --j;
    else if (j == 0 || d[i - 1][j] >= d[i][j - 1])
      res[k--] = str1[i - 1], --i;
    else
      res[k--] = str2[j - 1], --j;
  memcpy(res, str1, i);
  memcpy(res, str2, j);
  return res;
}
// @leet end