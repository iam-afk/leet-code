// @leet start

static int
compare_str(void const* a, void const* b)
{
  char const *s1 = *(char const**)a, *s2 = *(char const**)b;
  char const *b1 = s1, *b2 = s2;
  while (*s1 && *s2) {
    if (*s1 != *s2)
      return *s2 - *s1;
    if (*++s1 == 0)
      s1 = b1;
    if (*++s2 == 0)
      s2 = b2;
    if (s1 == b1 && s2 == b2)
      break;
  }
  return 0;
}

char*
largestNumber(int* nums, int numsSize)
{
  bool zeros = true;
  for (int i = 0; zeros && i < numsSize; ++i)
    zeros = nums[i] == 0;
  if (zeros)
    return "0";

  size_t retSize = 0;

  static char buf[100 * 11];
  static char* snums[100];

  char* next = buf;
  for (int i = 0; i < numsSize; ++i, ++next) {
    snums[i] = next;
    int r = sprintf(next, "%d", nums[i]);
    next += r;
    retSize += r;
  }

  qsort(snums, numsSize, sizeof(char*), compare_str);

  char* ret = malloc(retSize + 1);
  *ret = 0;
  for (int i = 0; i < numsSize; ++i)
    strcat(ret, snums[i]);
  return ret;
}
// @leet end