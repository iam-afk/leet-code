// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

static void
find(int k, int n, int* c, int* ret, int* retSize)
{
  int s = 0, i = 1;
  switch (k) {
    case 0:
      s = 1;
      break;
    case 2:
      i = 2;
      break;
    case 3:
      ret[(*retSize)++] = n;
      return;
  }
  for (int d = s; d <= 9; d += i)
    if (c[d] > 0) {
      --c[d];
      find(k + 1, n * 10 + d, c, ret, retSize);
      ++c[d];
    }
}

int*
findEvenNumbers(int* digits, int digitsSize, int* returnSize)
{
  int c[10] = {};
  for (int i = 0; i < digitsSize; ++i)
    ++c[digits[i]];

  int* ret = calloc(900, sizeof *ret);
  *returnSize = 0;

  find(0, 0, c, ret, returnSize);

  return ret;
}
// @leet end