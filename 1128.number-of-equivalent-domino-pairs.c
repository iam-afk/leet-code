// @leet start
#define swap(a, b)                                                                                 \
  ({                                                                                               \
    __typeof__(a) _t = (a);                                                                        \
    (a) = (b);                                                                                     \
    (b) = _t;                                                                                      \
  })

int
numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize)
{
  int ans = 0;
  for (int i = 0, d[100] = {}; i < dominoesSize; ++i) {
    int a = dominoes[i][0], b = dominoes[i][1];
    if (a > b)
      swap(a, b);
    ans += d[10 * a + b];
    ++d[10 * a + b];
  }
  return ans;
}
// @leet end