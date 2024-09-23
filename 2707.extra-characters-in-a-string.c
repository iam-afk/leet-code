// @leet start
#define min(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a < _b ? _a : _b;                                                                             \
  })

int D[51];

int
dp(char* s, int k, char** dictionary, int dictionarySize)
{
  if (s[k] == 0)
    return D[k] = 0;
  if (D[k] < INT_MAX)
    return D[k];
  D[k] = 1 + dp(s, k + 1, dictionary, dictionarySize);
  for (int i = 0; i < dictionarySize; ++i) {
    char* w = dictionary[i];
    bool starts_with = true;
    int l;
    for (l = 0; starts_with && s[k + l] && w[l]; ++l)
      starts_with = s[k + l] == w[l];
    if (starts_with && !w[l])
      D[k] = min(D[k], dp(s, k + l, dictionary, dictionarySize));
  }
  return D[k];
}

int
minExtraChar(char* s, char** dictionary, int dictionarySize)
{
  for (int i = 0; i < 51; ++i)
    D[i] = INT_MAX;
  return dp(s, 0, dictionary, dictionarySize);
}
// @leet end