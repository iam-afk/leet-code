// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  int findGCD(vector<int>& nums)
  {
    auto mm = ranges::minmax_element(nums);
    return gcd(*mm.min, *mm.max);
  }
};
// @leet end