// @leet start
struct trie
{
  struct trie* next[26];
  bool word;
};

static struct trie buf[256], *next;

static void
find(char* s, struct trie* root, int n, int* mx)
{
  if (*s == 0) {
    if (n > *mx)
      *mx = n;
    return;
  }
  struct trie** node = &root;
  for (int i = 0; s[i]; ++i) {
    node = &(*node)->next[s[i] - 'a'];
    if (*node == 0) {
      *node = next++;
    }
    if (!(*node)->word) {
      (*node)->word = true;
      find(s + i + 1, root, n + 1, mx);
      (*node)->word = false;
    }
  }
}

int
maxUniqueSplit(char* s)
{
  memset(buf, 0, sizeof buf);
  next = buf;

  struct trie* root = next++;
  int mx = 0;
  find(s, root, 0, &mx);
  return mx;
}
// @leet end