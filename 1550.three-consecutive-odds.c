// @leet start
bool
threeConsecutiveOdds(int* arr, int arrSize)
{
  int odd = 0;
  for (int i = 0; odd < 3 && i < arrSize; ++i)
    if (arr[i] % 2 == 1)
      ++odd;
    else
      odd = 0;
  return odd == 3;
}
// @leet end