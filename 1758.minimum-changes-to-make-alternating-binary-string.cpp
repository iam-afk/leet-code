// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  int minOperations(string s)
  {
    int ans = 0, x = 0;
    for (auto c : s) {
      ans += (x == 1) != (c == '1');
      x ^= 1;
    }
    return min(ans, static_cast<int>(s.size()) - ans);
  }
};
// @leet end