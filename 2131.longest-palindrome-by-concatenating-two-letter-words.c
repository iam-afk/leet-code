// @leet start
#define min(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = (a);                                                   \
    __typeof__(b) _b = (b);                                                   \
    _a < _b ? _a : _b;                                                        \
  })

int
longestPalindrome(char** words, int wordsSize)
{
  int d[26][26] = {};
  for (int i = 0; i < wordsSize; ++i) {
    int a = words[i][0] - 'a', b = words[i][1] - 'a';
    ++d[a][b];
  }
  int ans = 0, c = 0;
  for (int i = 0; i < 26; ++i) {
    for (int j = i; j < 26; ++j) {
      if (i != j)
        ans += min(d[i][j], d[j][i]);
      else {
        ans += d[i][j] / 2;
        c = c || d[i][j] & 1;
      }
    }
  }
  return ans * 4 + c * 2;
}
// @leet end