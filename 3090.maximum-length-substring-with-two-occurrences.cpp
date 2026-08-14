// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  int maximumLengthSubstring(string s)
  {
    array<int, 26> c{};
    int ans{};
    for (int l{}, r{}; r < s.length(); r++) {
      c[s[r] - 'a']++;
      for (; l <= r && c[s[r] - 'a'] > 2; l++)
        c[s[l] - 'a']--;
      ans = max(ans, r - l + 1);
    }
    return ans;
  }
};
// @leet end