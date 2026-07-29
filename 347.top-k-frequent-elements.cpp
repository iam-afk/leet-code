// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  vector<int> topKFrequent(vector<int>& nums, int k)
  {
    unordered_map<int, int> c;
    for (int x : nums)
      ++c[x];
    auto a =
      c | views::transform([](auto p) { return pair{ p.second, p.first }; }) |
      ranges::to<vector>();

    ranges::nth_element(a, a.begin() + k, greater<>{});

    vector<int> v;
    return a | views::take(k) |
           views::transform([](auto p) { return p.second; }) |
           ranges::to<vector>();
  }
};
// @leet end