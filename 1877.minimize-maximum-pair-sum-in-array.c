#define max(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a > _b ? _a : _b;                                                                             \
  })

static int
compare_ints(void const* a, void const* b)
{
  return *(int const*)a - *(int const*)b;
}

int
minPairSum(int* nums, int nums_size)
{
  qsort(nums, nums_size, sizeof(int), compare_ints);
  int maximum = nums[0] + nums[nums_size - 1];
  for (int i = 1; i < nums_size / 2; ++i)
    maximum = max(maximum, nums[i] + nums[nums_size - 1 - i]);
  return maximum;
}