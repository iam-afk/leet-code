// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  int longestBalanced(string s)
  {
    size_t ans{};
    auto index = [](char c) { return c - 'a'; };
    for (auto l = 0uz; l < s.size(); l++) {
      array<int, 26> counts{};
      for (auto [r, c] :
           s | views::transform(index) | views::enumerate | views::drop(l)) {
        counts[c]++;
        if (ranges::all_of(
              counts | views::filter([](auto x) { return x > 0; }),
              [t = counts[index(s[l])]](auto x) { return x == t; }))
          ans = max(ans, r - l + 1);
      }
    }
    return ans;
  }
};
// @leet end