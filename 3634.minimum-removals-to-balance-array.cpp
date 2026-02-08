#include <algorithm>
#include <vector>
using namespace std;

// @leet start
class Solution
{
public:
  int minRemoval(vector<int>& nums, int k)
  {
    ranges::sort(nums);
    long ans = nums.size();
    auto less_k = [k](auto a, auto b) { return 1L * k * a < b; };
    auto r = ranges::upper_bound(nums, nums.front(), less_k);
    for (auto [l, x] : nums | views::enumerate) {
      while (r != nums.end() && !less_k(x, *r))
        r++;
      ans = min(ans, l + distance(r, nums.end()));
    }
    return ans;
  }
};
// @leet end