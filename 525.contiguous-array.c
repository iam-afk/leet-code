// @leet start

#define N ((size_t)1e5)

int
findMaxLength(int* nums, int nums_size)
{
  int d[2 * N + 1], a = 0, mx = 0;
  for (int i = -nums_size; i <= nums_size; ++i)
    d[i + N] = INT_MAX;
  d[N] = -1;
  for (int i = 0; i < nums_size; ++i) {
    a += 2 * nums[i] - 1;
    if (d[a + N] < INT_MAX) {
      if (mx < i - d[a + N])
        mx = i - d[a + N];
    } else
      d[a + N] = i;
  }
  return mx;
}
// @leet end