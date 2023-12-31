// @leet start
#define max(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a > _b ? _a : _b;                                                                             \
  })

int
maxLengthBetweenEqualCharacters(char* s)
{
  int d[26] = { [0 ... 25] = -1 };
  int a = -1;
  for (int i = 0; s[i]; ++i)
    if (d[s[i] - 'a'] < 0)
      d[s[i] - 'a'] = i;
    else
      a = max(a, i - d[s[i] - 'a'] - 1);
  return a;
}
// @leet end