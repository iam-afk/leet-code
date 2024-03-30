// @leet start
#define N ((size_t)(2 * 1e4))

int
subarraysWithKDistinct(int* nums, int nums_size, int k)
{
  struct
  {
    int x, n;
    UT_hash_handle hh;
  } *map = 0, *ptr, buffer[N], *next = buffer;

  int d = 0, j = 0, a = 0;
  for (int i = 0; i < nums_size; ++i) {
    while (d < k && j < nums_size) {
      HASH_FIND_INT(map, &nums[j], ptr);
      if (ptr) {
        ++ptr->n;
        if (ptr->n == 1)
          ++d;
      } else {
        ptr = next++;
        ptr->x = nums[j];
        ptr->n = 1;
        HASH_ADD_INT(map, x, ptr);
        ++d;
      }
      ++j;
    }
    if (d < k)
      break;
    int je = j;
    while (je < nums_size && ptr && ptr->n > 0) {
      HASH_FIND_INT(map, &nums[je], ptr);
      if (!ptr || ptr->n == 0)
        break;
      ++je;
    }
    a += je - j + 1;
    HASH_FIND_INT(map, &nums[i], ptr);
    if (--ptr->n == 0)
      --d;
  }

  return a;
}
// @leet end