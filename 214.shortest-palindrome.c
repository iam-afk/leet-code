// @leet start
#define min(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a < _b ? _a : _b;                                                                             \
  })

#define N (size_t)5e5

char*
shortestPalindrome(char* s)
{
  int n = strlen(s);

  int mx = 0;

  int d[N];
  for (int i = 0, l = 0, r = 0; i < n; ++i) {
    int k = i < r ? min(r - i - 1, d[l + r - i - 1]) : 1;
    while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
      ++k;
    d[i] = k;
    if (i + k > r) {
      l = i - k + 1, r = i + k;
      if (l == 0)
        mx = r;
    }
  }

  d[0] = 0;
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    int k = i < r ? min(r - i, d[l + r - i]) : 0;
    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k])
      ++k;
    d[i] = k;
    if (i + k > r) {
      l = i - k, r = i + k;
      if (l == 0 && mx < r)
        mx = r;
    }
  }

  char* ret = malloc(2 * n - mx + 1);
  for (int i = 0; i < n - mx; ++i)
    ret[i] = s[n - i - 1];
  strcpy(ret + n - mx, s);

  return ret;
}
// @leet end