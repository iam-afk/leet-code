// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  int characterReplacement(string s, int k)
  {
    array<int, 26> d{};
    int mx{};
    int ans{};
    for (int l{}, r{}; r < s.length(); r++) {
      mx = max(mx, ++d[s[r] - 'A']);
      for (; l <= r && r - l + 1 - mx > k; l++)
        d[s[l] - 'A']--;
      ans = max(ans, r - l + 1);
    }
    return ans;
  }
};
// @leet end