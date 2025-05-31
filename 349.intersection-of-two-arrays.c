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
intersection(int* nums1,
             int nums1_size,
             int* nums2,
             int nums2_size,
             int* ret_size)
{
  qsort(nums1, nums1_size, sizeof(int), compare_ints);
  qsort(nums2, nums2_size, sizeof(int), compare_ints);

  int buf[1000], size = 0;

  for (int i = 0, j = 0; i < nums1_size && j < nums2_size;)
    if (nums1[i] < nums2[j])
      ++i;
    else if (nums1[i] > nums2[j])
      ++j;
    else {
      buf[size++] = nums1[i];
      while (i < nums1_size && nums1[i] == nums2[j])
        ++i;
    }
  *ret_size = size;
  int* ret = calloc(size, sizeof *ret);
  memcpy(ret, buf, size * sizeof *ret);
  return ret;
}
// @leet end