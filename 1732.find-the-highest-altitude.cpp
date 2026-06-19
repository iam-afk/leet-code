// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  int largestAltitude(vector<int>& gain)
  {
    int ans = 0, alt = 0;
    for (auto x : gain)
      ans = max(ans, alt += x);
    return ans;
  }
};
// @leet end