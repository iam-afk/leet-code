// @leet start

struct node
{
  struct node* next[11];
};

int
longestCommonPrefix(int* arr1, int arr1Size, int* arr2, int arr2Size)
{
  struct node buffer[9 * 50000], *next = buffer;
  struct node root = { .next = {} };

  char buf[10];
  for (int i = 0; i < arr1Size; ++i) {
    sprintf(buf, "%d", arr1[i]);
    struct node* p = &root;
    for (int j = 0; buf[j]; ++j) {
      int d = buf[j] - '0';
      if (!p->next[d]) {
        p->next[d] = next++;
        memset(p->next[d]->next, 0, sizeof(struct node));
      }
      p = p->next[d];
    }
  }

  int mx = 0;
  for (int i = 0; i < arr2Size; ++i) {
    sprintf(buf, "%d", arr2[i]);
    struct node* p = &root;
    int j = 0;
    for (; buf[j] && p->next[buf[j] - '0']; ++j)
      p = p->next[buf[j] - '0'];
    if (mx < j)
      mx = j;
  }

  return mx;
}
// @leet end