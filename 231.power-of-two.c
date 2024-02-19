// @leet start
bool
isPowerOfTwo(int n)
{
  return n > 0 && (n & n - 1) == 0;
}
// @leet end