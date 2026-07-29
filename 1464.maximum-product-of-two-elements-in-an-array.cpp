// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  int maxProduct(vector<int>& nums)
  {
    auto mx1 = ranges::max_element(nums);
    auto nums_without_max =
      nums | views::enumerate |
      views::filter([i = ranges::distance(nums.begin(), mx1)](auto p) {
        auto [j, _] = p;
        return i != j;
      }) |
      views::transform([](auto t) {
        auto [_, x] = t;
        return x;
      });
    auto mx2 = ranges::max_element(nums_without_max);
    return (*mx1 - 1) * (*mx2 - 1);
  }
};
// @leet end