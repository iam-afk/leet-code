// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  int countBinarySubstrings(string s)
  {
    int ans = 0;
    int c = 1, p = 0;
    for (auto [a, b] : s | views::pairwise) {
      if (a == b)
        c++;
      else {
        ans += min(c, p);
        p = exchange(c, 1);
      }
    }
    return ans + min(c, p);
  }
};
// @leet end