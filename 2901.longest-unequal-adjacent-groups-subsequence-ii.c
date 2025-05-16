// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define max(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a > _b ? _a : _b;                                                                             \
  })

static int
hamming(char* s, char* t)
{
  int x = 0;
  while (*s && *t)
    x += *s++ != *t++;
  return !*s && !*t ? x : -1;
}

char**
getWordsInLongestSubsequence(char** words,
                             int wordsSize,
                             int* groups,
                             int groupsSize,
                             int* returnSize)
{
  int l = 0;
  struct D
  {
    int n, p;
  } d[1000];
  for (int i = 0; i < wordsSize; ++i) {
    d[i] = (struct D){ .n = 1, .p = -1 };
    for (int j = 0; j < i; ++j)
      if (hamming(words[i], words[j]) == 1 && groups[i] != groups[j])
        if (d[i].n < d[j].n + 1) {
          d[i] = (struct D){ .n = d[j].n + 1, .p = j };
          if (d[i].n > d[l].n)
            l = i;
        }
  }

  *returnSize = d[l].n;
  char** ret = calloc(*returnSize, sizeof *ret);

  for (int i = *returnSize; l >= 0; l = d[l].p)
    ret[--i] = words[l];

  return ret;
}
// @leet end