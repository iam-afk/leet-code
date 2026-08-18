// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  int largestInteger(vector<int>& nums, int k)
  {
    array<int, 51> c;
    for (auto x : nums)
      c[x]++;
    if (k == 1) {
      for (int x = 50; x >= 0; x--)
        if (c[x] == 1)
          return x;
      return -1;
    }
    if (k == nums.size())
      for (int x = 50; x >= 0; x--)
        if (c[x] > 0)
          return x;
    int ans{ -1 };
    if (c[nums.front()] == 1)
      ans = max(ans, nums.front());
    if (c[nums.back()] == 1)
      ans = max(ans, nums.back());
    return ans;
  }
};
// @leet end