// @leet start
char* retBuf[100];

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char**
stringMatching(char** words, int wordsSize, int* returnSize)
{
  *returnSize = 0;
  for (int i = 0; i < wordsSize; ++i) {
    for (int j = 0; j < wordsSize; ++j)
      if (i != j && strstr(words[j], words[i])) {
        retBuf[(*returnSize)++] = words[i];
        break;
      }
  }
  char** ret = calloc(*returnSize, sizeof *ret);
  memcpy(ret, retBuf, *returnSize * sizeof *ret);
  return ret;
}

// @leet end