// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  int minimumDistance(vector<int>& nums)
  {
    int ans = -1;
    for (auto [i, x] : nums | views::enumerate)
      for (auto [j, y] : nums | views::enumerate | views::drop(i + 1)) {
        if (x != y)
          continue;
        for (auto [k, z] : nums | views::enumerate | views::drop(j + 1))
          if (x == z) {
            if (ans == -1 || k - i << 1 < ans)
              ans = k - i << 1;
          }
      }
    return ans;
  }
};
// @leet end