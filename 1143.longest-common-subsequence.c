// @leet start
int
longestCommonSubsequence(char* text1, char* text2)
{
  int n = strlen(text2);
  int d[1000] = { 0 };
  int a;
  for (int i = 0; text1[i] != 0; ++i) {
    a = 0;
    for (int j = 0; j < n; ++j) {
      int t = d[j];
      if (text1[i] == text2[j])
        d[j] = a + 1;
      else if (j > 0 && d[j - 1] > d[j])
        d[j] = d[j - 1];
      a = t;
    }
  }

  return d[n - 1];
}
// @leet end
//
//
// x x x x x x
// x x x x x x
// x x x x x x