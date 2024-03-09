// @leet start
int
getCommon(int* nums1, int nums1_size, int* nums2, int nums2_size)
{
  for (int i = 0, j = 0; i < nums1_size && j < nums2_size;)
    if (nums1[i] < nums2[j])
      ++i;
    else if (nums1[i] > nums2[j])
      ++j;
    else
      return nums1[i];
  return -1;
}
// @leet end