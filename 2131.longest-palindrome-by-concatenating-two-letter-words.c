// @leet start
#define min(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a < _b ? _a : _b;                                                                             \
  })

int
longestPalindrome(char** words, int wordsSize)
{
  int d[26 * 26] = {};
  for (int i = 0; i < wordsSize; ++i) {
    int a = words[i][0] - 'a', b = words[i][1] - 'a';
    ++d[a * 26 + b];
  }
  int ans = 0;
  bool c = false;
  for (int i = 0; i < 26 * 26; ++i) {
    int a = i / 26, b = i % 26;
    if (a != b)
      ans += min(d[i], d[b * 26 + a]) * 2;
    else {
      ans += d[i] / 2 * 4;
      c = c || d[i] & 1;
    }
  }
  return ans + c * 2;
}
// @leet end