// @leet start
#define N ((size_t)1e5)

char*
removeKdigits(char* num, int k)
{
  static char s[N];
  int t = 0;
  for (int i = 0; num[i] != 0; ++i) {
    while (k > 0 && t > 0 && s[t - 1] > num[i])
      --t, --k;
    if (t != 0 || num[i] != '0')
      s[t++] = num[i];
  }
  t = t >= k ? t - k : 0;
  s[t] = 0;
  return t > 0 ? s : "0";
}
// @leet end