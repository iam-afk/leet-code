// @leet start
int
minBitFlips(int start, int goal)
{
  return __builtin_popcount(start ^ goal);
}
// @leet end