// @leet start
int
findFinalValue(int* nums, int numsSize, int original)
{
  while (true) {
    bool found = false;
    for (int i = 0; !found && i < numsSize; ++i)
      if (nums[i] == original) {
        original *= 2;
        found = true;
      }
    if (!found)
      break;
  }
  return original;
}
// @leet end