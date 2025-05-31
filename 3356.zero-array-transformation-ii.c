// @leet start

static bool
zeros(int* a, int n, int** q, int k)
{
  static int d[100001];
  memset(d, 0, n * sizeof *d);
  for (int i = 0; i < k; ++i) {
    d[q[i][0]] += q[i][2];
    d[q[i][1] + 1] -= q[i][2];
  }
  int s = 0;
  for (int i = 0; i < n; ++i) {
    s += d[i];
    if (a[i] > s)
      return false;
  }
  return true;
}

int
minZeroArray(int* nums,
             int numsSize,
             int** queries,
             int queriesSize,
             int* queriesColSize)
{
  if (zeros(nums, numsSize, queries, -1))
    return 0;
  int l = 0, r = queriesSize + 1;
  while (l + 1 < r) {
    int m = l + (r - l) / 2;
    if (zeros(nums, numsSize, queries, m))
      r = m;
    else
      l = m;
  }
  return r <= queriesSize ? r : -1;
}
// @leet end