// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define _GNU_SOURCE

static int count[51];

static int
compare(void const* a, void const* b)
{
  int i = *(int const*)a, j = *(int const*)b;
  if (count[i] == count[j])
    return (i < j) - (i > j);
  return (count[i] < count[j]) - (count[i] > count[j]);
}

static int
x_sum(int x, int index[static 50])
{
  qsort(index, 51, sizeof(int), compare);
  int sum = 0;
  for (int i = 0; i < x; ++i)
    sum += index[i] * count[index[i]];
  return sum;
}

int*
findXSum(int* nums, int n, int k, int x, int* returnSize)
{
  int index[50 + 1];
  for (int i = 0; i <= 50; ++i)
    index[i] = i;

  memset(count, 0, sizeof count);
  for (int i = 0; i < k; ++i)
    count[nums[i]]++;

  *returnSize = 0;
  int* ret = calloc(n - k + 1, sizeof *ret);

  ret[(*returnSize)++] = x_sum(x, index);
  for (int i = 1; i + k - 1 < n; ++i) {
    --count[nums[i - 1]], ++count[nums[i + k - 1]];
    ret[(*returnSize)++] = x_sum(x, index);
  }
  return ret;
}
// @leet end