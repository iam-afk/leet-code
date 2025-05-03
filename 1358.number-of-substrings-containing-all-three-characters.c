// @leet start
int
numberOfSubstrings(char* s)
{
  int ans = 0;
  int n = strlen(s);
  int d[3] = {};
  for (int i = 0, j = 0; i < n; ++i) {
    ++d[s[i] - 'a'];
    while (d[0] > 0 && d[1] > 0 && d[2] > 0) {
      ans += n - i;
      --d[s[j++] - 'a'];
    }
  }
  return ans;
}
// @leet end