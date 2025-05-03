// @leet start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define N (size_t)1e4

uint8_t counts[N][32];

static int
compare_counts(void const* a, void const* b)
{
  return memcmp(counts[*(int const*)a], counts[*(int const*)b], 26);
}

char***
groupAnagrams(char** strs, int strs_size, int* ret_size, int** ret_sizes)
{
  for (int i = 0; i < strs_size; ++i) {
    memset(counts[i], 0, sizeof counts[i]);
    char* s = strs[i];
    while (*s != 0)
      ++counts[i][*s++ - 'a'];
  }
  int str_index[N];
  for (int i = 0; i < strs_size; ++i)
    str_index[i] = i;
  qsort(str_index, strs_size, sizeof *str_index, compare_counts);

  char** groups[N];
  int groups_size[N];

  int from = 0, n = 0;
  while (from < strs_size) {
    int to = from + 1;
    while (to < strs_size && memcmp(counts[str_index[from]], counts[str_index[to]], 26) == 0)
      ++to;
    groups_size[n] = to - from;
    groups[n] = calloc(to - from, sizeof *groups);
    for (int i = 0, j = from; j < to; ++i, ++j)
      groups[n][i] = strs[str_index[j]];
    ++n;
    from = to;
  }
  *ret_size = n;
  *ret_sizes = calloc(n, sizeof **ret_sizes);
  memcpy(*ret_sizes, groups_size, n * sizeof **ret_sizes);
  char*** ret = calloc(n, sizeof *ret);
  memcpy(ret, groups, n * sizeof *ret);
  return ret;
}
// @leet end