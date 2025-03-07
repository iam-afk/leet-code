// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int*
closestPrimes(int left, int right, int* returnSize)
{
  bool p[1000010];
  memset(p, true, right + 1);
  p[1] = false;
  for (int i = 2; i * i <= right; ++i)
    if (p[i])
      for (int j = i * i; j <= right; j += i)
        p[j] = false;

  *returnSize = 2;
  int* ret = calloc(2, sizeof *ret);
  ret[0] = ret[1] = -1;

  int num1 = left;
  for (; num1 <= right; ++num1)
    if (p[num1])
      break;
  if (num1 > right)
    return ret;

  int num2 = num1 + 1;
  for (; num2 <= right; ++num2)
    if (p[num2]) {
      if (ret[0] < 0 || num2 - num1 < ret[1] - ret[0])
        ret[0] = num1, ret[1] = num2;
      num1 = num2;
    }

  return ret;
}
// @leet end