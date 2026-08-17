// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  int longestSubsequence(vector<int>& nums)
  {
    if (ranges::fold_left(nums, 0, bit_xor{}) != 0)
      return nums.size();
    if (ranges::all_of(nums, [](auto x) { return x == 0; }))
      return 0;
    return nums.size() - 1;
  }
};
// @leet end