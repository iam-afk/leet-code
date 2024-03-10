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
intersection(int* nums1, int nums1_size, int* nums2, int nums2_size, int* ret_size)
{
  qsort(nums1, nums1_size, sizeof(int), compare_ints);
  qsort(nums2, nums2_size, sizeof(int), compare_ints);

  int buf[1000], size = 0;
  if (bsearch(nums1, nums2, nums2_size, sizeof(int), compare_ints) != 0)
    buf[size++] = nums1[0];

  for (int i = 1; i < nums1_size; ++i) {
    if (nums1[i - 1] == nums1[i])
      continue;
    if (bsearch(nums1 + i, nums2, nums2_size, sizeof(int), compare_ints) != 0)
      buf[size++] = nums1[i];
  }

  *ret_size = size;
  int* ret = calloc(size, sizeof *ret);
  memcpy(ret, buf, size * sizeof *ret);
  return ret;
}
// @leet end