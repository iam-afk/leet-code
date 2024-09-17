// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct node
{
  char const* w;
  int n;
  UT_hash_handle hh;
};

static struct node*
hash_words(char* s, struct node* buffer)
{
  struct node *hash = 0, *entry, *next = buffer;

  char const* word = s;
  while (*s) {
    while (*s && *s != ' ')
      ++s;
    ptrdiff_t len = s - word;
    if (*s)
      *s++ = 0;
    else
      *s = 0;
    HASH_FIND_STR(hash, word, entry);
    if (entry)
      ++entry->n;
    else {
      entry = next++;
      entry->w = word;
      entry->n = 1;
      HASH_ADD_KEYPTR(hh, hash, entry->w, len, entry);
    }
    word = s;
  }

  return hash;
}

static void
unique(struct node* words, struct node* others, char const** ret, int* retSize)
{
  struct node* found;
  for (struct node* entry = words; entry; entry = entry->hh.next) {
    if (entry->n == 1) {
      HASH_FIND_STR(others, entry->w, found);
      if (!found)
        ret[(*retSize)++] = entry->w;
    }
  }
}

char**
uncommonFromSentences(char* s1, char* s2, int* returnSize)
{
  struct node buffer1[200], buffer2[200];
  struct node* words1 = hash_words(s1, buffer1);
  struct node* words2 = hash_words(s2, buffer2);

  char const* buf[400];
  *returnSize = 0;
  unique(words1, words2, buf, returnSize);
  unique(words2, words1, buf, returnSize);

  char** ret = calloc(*returnSize, sizeof *ret);
  memcpy(ret, buf, *returnSize * sizeof *ret);
  return ret;
}
// @leet end