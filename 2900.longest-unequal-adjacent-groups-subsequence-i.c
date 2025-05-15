// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char**
getLongestSubsequence(char** words, int wordsSize, int* groups, int groupsSize, int* returnSize)
{
  char** ret = calloc(wordsSize, sizeof *ret);
  *returnSize = 0;
  ret[(*returnSize)++] = words[0];
  for (int i = 1, j = 0; i < wordsSize; ++i)
    if (groups[i] != groups[j])
      ret[(*returnSize)++] = words[j = i];
  return ret;
}
// @leet end