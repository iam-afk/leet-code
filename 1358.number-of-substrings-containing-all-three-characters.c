// @leet start
int
numberOfSubstrings(char* s)
{
  int ans = 0;
  int n = strlen(s);
  int a, b, c;
  a = b = c = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    if (s[i] == 'a')
      ++a;
    if (s[i] == 'b')
      ++b;
    if (s[i] == 'c')
      ++c;
    if (a > 0 && b > 0 && c > 0) {
      int k;
      for (k = j; a > 0 && b > 0 && c > 0; ++j) {
        if (s[j] == 'a')
          --a;
        if (s[j] == 'b')
          --b;
        if (s[j] == 'c')
          --c;
      }
      ans += (n - i) * (j - k);
    }
  }
  return ans;
}
// @leet end