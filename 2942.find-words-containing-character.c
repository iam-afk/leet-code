// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int*
findWordsContaining(char** words, int wordsSize, char x, int* returnSize)
{
  *returnSize = 0;
  int buf[50];
  for (int i = 0; i < wordsSize; ++i)
    for (int j = 0; words[i][j]; ++j)
      if (words[i][j] == x) {
        buf[(*returnSize)++] = i;
        break;
      }
  int* ret = calloc(*returnSize, sizeof *ret);
  memcpy(ret, buf, *returnSize * sizeof *ret);
  return ret;
}
// @leet end