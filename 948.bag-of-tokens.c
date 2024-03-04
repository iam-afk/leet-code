// @leet start
static int
compare_ints(void const* a, void const* b)
{
  return *(int const*)a - *(int const*)b;
}

#define max(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a > _b ? _a : _b;                                                                             \
  })

int
bagOfTokensScore(int* tokens, int tokens_size, int power)
{
  qsort(tokens, tokens_size, sizeof(int), compare_ints);
  int i = 0, j = tokens_size, max_score = 0, score = 0;
  while (i < j) {
    if (tokens[i] <= power)
      power -= tokens[i++], ++score;
    else if (score > 0)
      power += tokens[--j], --score;
    else
      break;
    max_score = max(max_score, score);
  }
  return max_score;
}
// @leet end