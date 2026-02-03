// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  int minimumPairRemoval(vector<int>& nums)
  {
    int ans;
    for (ans = 0; !ranges::is_sorted(nums); ans++) {
      auto adjacent_sums = nums | views::pairwise_transform(plus{});
      auto min_sum = ranges::min_element(adjacent_sums);
      auto position = ranges::distance(adjacent_sums.begin(), min_sum);
      nums[position] = *min_sum;
      nums.erase(next(nums.begin(), position + 1));
    }
    return ans;
  }
};
// @leet end