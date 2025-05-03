// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct trie
{
  struct
  {
    uint32_t index;
    uint32_t count;
  } children[26];
};

int*
sumPrefixScores(char** words, int wordsSize, int* returnSize)
{
  static struct trie buffer[1000 * 1000];
  int free = 0;
  memset(buffer, 0, sizeof(buffer));

  struct trie root = {};
  for (int i = 0; i < wordsSize; ++i) {
    struct trie* p = &root;
    for (char const* word = words[i]; *word; ++word) {
      int j = *word - 'a';
      if (!p->children[j].index)
        p->children[j].index = ++free;
      ++p->children[j].count;
      p = buffer + p->children[j].index;
    }
  }

  *returnSize = wordsSize;
  int* ret = calloc(*returnSize, sizeof *ret);
  for (int i = 0; i < wordsSize; ++i) {
    int score = 0;
    struct trie* p = &root;
    for (char const* word = words[i]; *word && p; ++word) {
      int j = *word - 'a';
      score += p->children[j].count;
      p = buffer + p->children[j].index;
    }
    ret[i] = score;
  }
  return ret;
}
// @leet end