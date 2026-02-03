// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  vector<vector<int>> minimumAbsDifference(vector<int>& arr)
  {
    ranges::sort(arr);
    auto diffs =
      arr | views::pairwise_transform([](auto a, auto b) { return b - a; });
    auto mn = *ranges::min_element(diffs);
    return arr | views::pairwise | views::filter([mn](auto p) {
             auto [a, b] = p;
             return b - a == mn;
           }) |
           views::transform([](auto p) {
             auto [a, b] = p;
             return vector<int>{ a, b };
           }) |
           ranges::to<vector>();
  }
};
// @leet end