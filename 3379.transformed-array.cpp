// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  vector<int> constructTransformedArray(vector<int>& nums)
  {
    return nums | views::enumerate |
           views::transform([n = nums.size(), &nums](auto p) {
             auto [i, x] = p;
             return nums[(i + 100 * n + x) % n];
           }) |
           ranges::to<vector>();
  }
};
// @leet end