// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  int minimumDifference(vector<int>& nums, int k)
  {
    ranges::sort(nums);
    auto diffs =
      views::zip_transform(minus{}, nums | views::drop(k - 1), nums);
    return *ranges::min_element(diffs);
  }
};
// @leet end