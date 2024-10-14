// @leet start

#define HEAP_S(type, field)                                                                        \
  static void swap_##type(type* a, int i, int j)                                                   \
  {                                                                                                \
    type t = a[i];                                                                                 \
    a[i] = a[j];                                                                                   \
    a[j] = t;                                                                                      \
  }                                                                                                \
  static void sift_up_##type(type* a, int i)                                                       \
  {                                                                                                \
    while (a[i] field > a[(i - 1) / 2] field) {                                                    \
      swap_##type(a, i, (i - 1) / 2);                                                              \
      i = (i - 1) / 2;                                                                             \
    }                                                                                              \
  }                                                                                                \
  static void sift_down_##type(type* a, int n, int i)                                              \
  {                                                                                                \
    while (2 * i + 1 < n) {                                                                        \
      int l = 2 * i + 1, r = 2 * i + 2;                                                            \
      int j = l;                                                                                   \
      if (r < n && a[r] field > a[l] field)                                                        \
        j = r;                                                                                     \
      if (a[i] field > a[j] field)                                                                 \
        break;                                                                                     \
      swap_##type(a, i, j);                                                                        \
      i = j;                                                                                       \
    }                                                                                              \
  }
#define HEAP(type) HEAP_S(type, )

HEAP(int)

long long
maxKelements(int* nums, int nums_size, int k)
{
  for (int i = nums_size / 2 + 1; i-- > 0;)
    sift_down_int(nums, nums_size, i);
  long long score = 0;
  for (int i = 0; i < k; ++i) {
    score += nums[0];
    nums[0] = (nums[0] + 2) / 3;
    sift_down_int(nums, nums_size, 0);
  }
  return score;
}
// @leet end