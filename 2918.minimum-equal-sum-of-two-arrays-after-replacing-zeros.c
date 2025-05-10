// @leet start
#define max(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a > _b ? _a : _b;                                                                             \
  })

long long
minSum(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
  int64_t sum1 = 0, sum2 = 0;
  int z1 = 0, z2 = 0;
  for (int i = 0; i < nums1Size; ++i) {
    sum1 += nums1[i];
    z1 += nums1[i] == 0;
  }
  for (int i = 0; i < nums2Size; ++i) {
    sum2 += nums2[i];
    z2 += nums2[i] == 0;
  }
  if (z2 == 0 && sum1 + z1 > sum2 || z1 == 0 && sum1 < sum2 + z2)
    return -1;

  return max(sum1 + z1, sum2 + z2);
}
// @leet end