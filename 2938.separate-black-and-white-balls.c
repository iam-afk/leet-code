// @leet start
long long
minimumSteps(char* s)
{
  long long swaps = 0;
  int ones = 0;
  for (int i = 0; s[i]; ++i)
    if (s[i] == '1')
      ++ones;
    else
      swaps += ones;

  return swaps;
}
// @leet end