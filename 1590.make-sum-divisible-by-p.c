// @leet start
int
minSubarray(int* nums, int numsSize, int p)
{
  int sum = 0;
  for (int i = 0; i < numsSize; ++i) {
    sum += nums[i];
    sum %= p;
  }
  if (sum == 0)
    return 0;
  int m = sum;
  struct
  {
    int n, i;
    UT_hash_handle hh;
  } *map = 0, buf[100001], *e, *next = buf;
  e = next++;
  e->n = 0;
  e->i = -1;
  HASH_ADD_INT(map, n, e);

  int ans = INT_MAX;
  sum = 0;
  printf("%d\n", m);
  for (int i = 0; i < numsSize; ++i) {
    sum += nums[i];
    sum %= p;
    int k = (p + sum - m) % p;
    HASH_FIND_INT(map, &k, e);
    if (e) {
      if (i - e->i < ans && i - e->i < numsSize)
        ans = i - e->i;
    }

    HASH_FIND_INT(map, &sum, e);
    if (e) {
      e->i = i;
    } else {
      e = next++;
      e->n = sum;
      e->i = i;
      HASH_ADD_INT(map, n, e);
    }
  }
  return ans < INT_MAX ? ans : -1;
}
// @leet end