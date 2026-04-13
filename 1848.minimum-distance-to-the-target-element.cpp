// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  int getMinDistance(vector<int>& nums, int target, int start)
  {
    auto answers =
      nums | views::enumerate |
      views::filter([target](auto t) { return get<1>(t) == target; }) |
      views::transform([start](auto t) { return abs(start - get<0>(t)); });
    return *ranges::min_element(answers);
  }
};
// @leet end