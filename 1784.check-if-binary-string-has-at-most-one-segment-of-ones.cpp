// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  bool checkOnesSegment(string s)
  {
    auto skip_ones = s | views::drop_while([](char c) { return c == '1'; });
    return ranges::all_of(skip_ones, [](auto c) { return c == '0'; });
  }
};
// @leet end