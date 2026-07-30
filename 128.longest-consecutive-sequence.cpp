// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  int longestConsecutive(vector<int>& nums)
  {
    unordered_set<int> s{ nums.begin(), nums.end() };
    int ans{ 0 };
    for (auto x : s) {
      if (!s.contains(x - 1)) {
        int i{ 1 };
        while (s.contains(x + i))
          i++;
        ans = max(ans, i);
      }
    }
    return ans;
  }
};
// @leet end