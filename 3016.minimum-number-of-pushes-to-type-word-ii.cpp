// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  int minimumPushes(string word)
  {
    array<int, 26> c{};
    for (auto k : word | views::transform([](auto c) { return c - 'a'; }))
      c[k]++;

    ranges::sort(c, greater<>{});

    return ranges::fold_left(
      c | views::take_while([](auto x) { return x > 0; }) | views::enumerate |
        views::transform([](auto p) {
          auto [i, x] = p;
          return (i / 8 + 1) * x;
        }),
      0,
      plus{});
  }
};
// @leet end