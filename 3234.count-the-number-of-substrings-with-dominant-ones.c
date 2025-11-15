// @leet start
#define min(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = (a);                                                   \
    __typeof__(b) _b = (b);                                                   \
    _a < _b ? _a : _b;                                                        \
  })

int
numberOfSubstrings(char* s)
{
  int pre[40000];
  for (int i = 0; s[i]; ++i)
    if (i == 0 || s[i - 1] == '0')
      pre[i] = i - 1;
    else
      pre[i] = pre[i - 1];
  int ans = 0;
  for (int i = 0; s[i]; ++i) {
    int zeros = s[i] == '0';
    for (int j = i; j >= 0 && zeros * zeros <= i;) {
      int ones = i - pre[j] - zeros;
      if (zeros * zeros <= ones) {
        //    011...10xxxxxxx
        //    ^      ^      ^
        // pre[j]    j      i
        ans += min(j - pre[j], ones - zeros * zeros + 1);
      }
      j = pre[j];
      ++zeros;
    }
  }
  return ans;
}
// @leet end