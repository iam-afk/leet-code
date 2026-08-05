// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  bool checkInclusion(string s1, string s2)
  {
    auto to_index = [](char c) { return c - 'a'; };
    std::array<int, 26> t{}, d{};
    ranges::for_each(s1 | views::transform(to_index),
                     [&t](auto i) { return t[i]++; });
    int i{};
    for (auto [j, k] : s2 | views::transform(to_index) | views::enumerate) {
      d[k]++;
      for (; i <= j && d[k] > t[k]; i++)
        d[to_index(s2[i])]--;
      if (j - i + 1 == s1.length())
        return true;
    }
    return false;
  }
};
// @leet end