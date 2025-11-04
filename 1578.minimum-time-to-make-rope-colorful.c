/*
 * @lc app=leetcode id=1578 lang=c
 *
 * [1578] Minimum Time to Make Rope Colorful
 */

// @lc code=start
int
minCost(char* colors, int* neededTime, int neededTimeSize)
{
  int ans = 0, sum_time = 0, max_time = 0;
  for (int i = 0; i < neededTimeSize; ++i) {
    if (i > 0 && colors[i] == colors[i - 1]) {
      sum_time += neededTime[i];
      if (max_time < neededTime[i])
        max_time = neededTime[i];
    } else {
      ans += sum_time - max_time;
      sum_time = max_time = neededTime[i];
    }
  }
  return ans + sum_time - max_time;
}
// @lc code=end
