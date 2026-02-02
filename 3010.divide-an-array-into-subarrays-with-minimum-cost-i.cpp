// @leet imports start
#include <utility>
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  int minimumCost(vector<int>& nums)
  {
    int mn0 = nums.front(), mn1, mn2;
    mn1 = mn2 = numeric_limits<int>::max();
    for (auto x : nums | views::drop(1))
      if (x < mn1)
        mn2 = exchange(mn1, x);
      else if (x < mn2)
        mn2 = x;
    return mn0 + mn1 + mn2;
  }
};
// @leet end