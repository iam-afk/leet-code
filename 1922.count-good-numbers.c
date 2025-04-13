// @leet start
#define M (int64_t)(1e9 + 7)

int
countGoodNumbers(long long n)
{
  int64_t ans = n & 1 ? 5 : 1;
  int64_t p = 20;
  for (n /= 2; n > 0; n >>= 1) {
    if (n & 1)
      ans = (ans * p) % M;
    p = (p * p) % M;
  }
  return ans;
}
// @leet end