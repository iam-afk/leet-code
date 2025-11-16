// @leet start
#define M ((int)1e9 + 7)

int
numSub(char* s)
{
  int ones = 0, ans = 0;
  for (int i = 0; s[i]; ++i) {
    ones += s[i] == '1';
    if (s[i] == '0') {
      ans += (1L + ones) * ones / 2 % M;
      ans %= M;
      ones = 0;
    }
  }
  ans += (1L + ones) * ones / 2 % M;
  ans %= M;
  return ans;
}
// @leet end