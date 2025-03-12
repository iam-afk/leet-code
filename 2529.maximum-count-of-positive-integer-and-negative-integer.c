// @leet start
int
maximumCount(int* nums, int numsSize)
{
  int neg, pos;
  if (nums[0] >= 0)
    neg = 0;
  else {
    int l = 0, r = numsSize;
    while (l + 1 < r) {
      int m = l + (r - l) / 2;
      if (nums[m] < 0)
        l = m;
      else
        r = m;
    }
    neg = r;
  }
  if (nums[0] > 0)
    pos = numsSize;
  else {
    int l = 0, r = numsSize;
    while (l + 1 < r) {
      int m = l + (r - l) / 2;
      if (nums[m] <= 0)
        l = m;
      else
        r = m;
    }
    pos = numsSize - r;
  }
  return neg < pos ? pos : neg;
}
// @leet end