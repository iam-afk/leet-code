// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char**
removeAnagrams(char** words, int wordsSize, int* returnSize)
{
  *returnSize = 1;

  int prev[26] = {};
  for (int j = 0; words[0][j]; ++j)
    ++prev[words[0][j] - 'a'];

  for (int i = 1; i < wordsSize; ++i) {
    int cur[26] = {};
    for (int j = 0; words[i][j]; ++j)
      ++cur[words[i][j] - 'a'];

    if (memcmp(prev, cur, sizeof prev) != 0) {
      memcpy(prev, cur, sizeof prev);
      words[(*returnSize)++] = words[i];
    }
  }
  return words;
}
// @leet end