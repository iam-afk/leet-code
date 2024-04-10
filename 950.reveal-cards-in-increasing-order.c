// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
static int
compare_ints(void const* a, void const* b)
{
  return *(int const*)a - *(int const*)b;
}

int*
deckRevealedIncreasing(int* deck, int deck_size, int* ret_size)
{
  *ret_size = deck_size;
  int* ret = calloc(*ret_size, sizeof *ret);

  qsort(deck, deck_size, sizeof(int), compare_ints);

  int order[1000], q[1000];
  for (int i = 0; i < deck_size; ++i)
    order[i] = i;
  int n = deck_size, t = 0, k = 0, i = 0;
  while (n > 0) {
    if (i < n)
      q[k++] = order[i++];
    else {
      n = t, t = 0, i = 0;
      continue;
    }
    if (i < n)
      order[t++] = order[i++];
    else
      n = t, t = 1, i = 1;
  }
  for (int i = 0; i < deck_size; ++i)
    ret[q[i]] = deck[i];
  return ret;
}
// @leet end