// @leet start
#define N (size_t)1e5

int
longestSquareStreak(int* nums, int numsSize)
{
  struct
  {
    unsigned num;
    UT_hash_handle hh;
  } *set = 0, buffer[N], *ptr, *next = buffer;
  for (int i = 0; i < numsSize; ++i) {
    ptr = next++;
    ptr->num = nums[i];
    HASH_ADD_INT(set, num, ptr);
  }
  int ans = -1;
  for (int i = 0; i < numsSize; ++i) {
    long num = (long)nums[i] * nums[i];
    HASH_FIND_INT(set, &num, ptr);
    int streak = 1;
    while (ptr && num <= N) {
      num *= num;
      HASH_FIND_INT(set, &num, ptr);
      ++streak;
    }
    if (streak > 1 && streak > ans)
      ans = streak;
  }
  return ans;
}
// @leet end