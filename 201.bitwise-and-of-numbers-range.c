// @leet start
int
rangeBitwiseAnd(int left, int right)
{
  int answer = left;
  for (unsigned p = 1; p <= left; p *= 2)
    if (left & p) {
      unsigned next = (left & ~(2 * p - 1)) + 2 * p;
      if (next <= right)
        answer &= ~p;
    }
  return answer;
}
// @leet end