// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char**
wordSubsets(char** words1,
            int words1Size,
            char** words2,
            int words2Size,
            int* returnSize)
{
  char* retBuf[10000];
  *returnSize = 0;

  uint8_t uni[26] = {};
  for (int i = 0; i < words2Size; ++i) {
    uint8_t count[26] = {};
    for (int j = 0; words2[i][j]; ++j)
      ++count[words2[i][j] - 'a'];
    for (int j = 0; j < 26; ++j)
      if (uni[j] < count[j])
        uni[j] = count[j];
  }

  for (int i = 0; i < words1Size; ++i) {
    uint8_t count[26] = {};
    for (int j = 0; words1[i][j]; ++j)
      ++count[words1[i][j] - 'a'];
    bool universal = true;
    for (int j = 0; universal && j < 26; ++j)
      universal = count[j] >= uni[j];
    if (universal)
      retBuf[(*returnSize)++] = words1[i];
  }

  char** ret = calloc(*returnSize, sizeof *ret);
  memcpy(ret, retBuf, *returnSize * sizeof *ret);
  return ret;
}
// @leet end