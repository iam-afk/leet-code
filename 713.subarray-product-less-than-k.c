// @leet start
int
numSubarrayProductLessThanK(int* nums, int nums_size, int k)
{
  int a = 0, r = 0, p = 1;
  for (int i = 0; i < nums_size; ++i) {
    while (r < nums_size && p * nums[r] < k) {
      p *= nums[r];
      a += r - i + 1;
      ++r;
    }
    if (i < r)
      p /= nums[i];
    else
      ++r;
  }
  return a;
}
// @leet end