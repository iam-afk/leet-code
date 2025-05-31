#define max(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = (a);                                                   \
    __typeof__(b) _b = (b);                                                   \
    _a > _b ? _a : _b;                                                        \
  })

static int
compare_ints(void const* a, void const* b)
{
  return *(int const*)a - *(int const*)b;
}

int
maxFrequency(int* nums, int nums_size, int k)
{
  qsort(nums, nums_size, sizeof(int), compare_ints);
  int64_t prefix[100000];
  prefix[0] = nums[0];
  for (int i = 1; i < nums_size; ++i)
    prefix[i] = prefix[i - 1] + nums[i];
  int answer = 0;
  for (int i = 0; i < nums_size; ++i) {
    int left = i, right = nums_size;
    while (left + 1 < right) {
      int target = left + (right - left) / 2;
      int64_t count = (int64_t)nums[target] * (target - i + 1);
      count -= prefix[target];
      if (i > 0)
        count += prefix[i - 1];
      if (count <= k)
        left = target;
      else
        right = target;
    }
    answer = max(answer, left - i + 1);
  }
  return answer;
}