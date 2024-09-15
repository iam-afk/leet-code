// @leet start
#define N (size_t)5e5

#define max(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a > _b ? _a : _b;                                                                             \
  })

int
findTheLongestSubstring(char* s)
{
  int ans = 0;
  int h[32] = { [0] = -1, [1 ... 31] = -2 };
  int p = 0;
  for (int i = 0; s[i]; ++i) {
    int x = 0;
    switch (s[i]) {
      case 'a':
        x = 1 << 0;
        break;
      case 'e':
        x = 1 << 1;
        break;
      case 'i':
        x = 1 << 2;
        break;
      case 'o':
        x = 1 << 3;
        break;
      case 'u':
        x = 1 << 4;
        break;
    }
    p = p ^ x;
    if (h[p] == -2)
      h[p] = i;
    else
      ans = max(ans, i - h[p]);
  }

  return ans;
}
// @leet end