// @leet start
#define N (size_t)5e5

#define max(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a > _b ? _a : _b;                                                                             \
  })

int
maxWidthRamp(int* nums, int numsSize)
{
  static struct
  {
    int val, idx;
  } stack[N];

  int top = 0;
  stack[top].val = nums[0];
  stack[top].idx = 0;

  int ans = 0;
  for (int i = 1; i < numsSize; ++i) {
    if (nums[i] >= stack[0].val)
      ans = max(ans, i);
    else {
      int l = 0, r = top + 1;
      while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (stack[m].val > nums[i])
          l = m;
        else
          r = m;
      }
      if (r <= top)
        ans = max(ans, i - stack[r].idx);
    }
    if (nums[i] < stack[top].val) {
      ++top;
      stack[top].val = nums[i];
      stack[top].idx = i;
    }
  }
  return ans;
}
// @leet end