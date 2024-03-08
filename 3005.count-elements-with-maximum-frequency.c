// @leet start
int
maxFrequencyElements(int* nums, int numsSize)
{
  int freq[101] = { 0 }, mx = 0, total = 0;
  for (int i = 0; i < numsSize; ++i)
    if (++freq[nums[i]] > mx)
      mx = freq[nums[i]], total = mx;
    else if (freq[nums[i]] == mx)
      total += freq[nums[i]];
  return total;
}
// @leet end