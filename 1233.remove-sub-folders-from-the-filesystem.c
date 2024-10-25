// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

static int
compare_folders(void const* a, void const* b)
{
  return strcmp(*(char const* const*)a, *(char const* const*)b);
}

char**
removeSubfolders(char** folder, int folderSize, int* returnSize)
{
  char** ret = calloc(folderSize, sizeof *ret);
  *returnSize = 0;

  qsort(folder, folderSize, sizeof(char*), compare_folders);

  for (int i = 0, j; i < folderSize; i = j) {
    ret[(*returnSize)++] = folder[i];
    for (j = i + 1; j < folderSize; ++j) {
      char *s = folder[i], *t = folder[j];
      while (*s && *s == *t)
        ++s, ++t;
      if (*s || *t != '/')
        break;
    }
  }

  return ret;
}
// @leet end