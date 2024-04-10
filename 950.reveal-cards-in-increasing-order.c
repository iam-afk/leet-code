// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <string.h>
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

  int q[UINT16_MAX];
  uint16_t h = 0, t = deck_size;
  for (int i = 0; i < deck_size; ++i)
    q[i] = i;

  qsort(deck, deck_size, sizeof(int), compare_ints);

  for (int i = 0; i < deck_size; ++i) {
    int x = q[h++];
    ret[x] = deck[i];
    q[t++] = q[h++];
  }

  return ret;
}
// @leet end