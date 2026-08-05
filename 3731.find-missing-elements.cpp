// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  vector<int> findMissingElements(vector<int>& nums)
  {
    ranges::sort(nums);

    vector<int> ans;
    for (int i = 1; i < nums.size(); i++)
      for (int l = nums[i - 1] + 1; l < nums[i]; l++)
        ans.push_back(l);
    return ans;
  }
};
// @leet end