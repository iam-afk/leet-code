/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char**
buildArray(int* target, int target_size, int n, int* return_size)
{
  *return_size = 2 * target[target_size - 1] - target_size;
  char** operations = calloc(*return_size, sizeof *operations);
  for (int i = 1, j = 0, k = 0; i <= n && j < target_size; ++i) {
    operations[k++] = "Push";
    if (target[j] == i)
      ++j;
    else
      operations[k++] = "Pop";
  }
  return operations;
}