// @leet start
#define N ((size_t)1e5)

long long
countGood(int* nums, int numsSize, int k)
{
  struct
  {
    int num, count;
    UT_hash_handle hh;
  } *hash = 0, hash_buf[N], *ptr, *next = hash_buf;
  long long ans = 0;
  for (int l = 0, r = 0, p = 0; l < numsSize - 1; ++l) {
    for (; p < k && r < numsSize; ++r) {
      HASH_FIND_INT(hash, &nums[r], ptr);
      if (!ptr) {
        ptr = next++;
        ptr->num = nums[r];
        ptr->count = 0;
        HASH_ADD_INT(hash, num, ptr);
      }
      p += ptr->count;
      ++ptr->count;
    }
    if (p >= k)
      ans += numsSize - r + 1;
    HASH_FIND_INT(hash, &nums[l], ptr);
    --ptr->count;
    p -= ptr->count;
  }
  return ans;
}
// @leet end