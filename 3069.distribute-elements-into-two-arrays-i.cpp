// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  vector<int> resultArray(vector<int>& nums)
  {
    auto const n = nums.size();
    vector<int> r(n, 0);
    r.front() = nums[0];
    r.back() = nums[1];
    auto i{ r.begin() };
    auto j{ r.end() - 1 };
    for (auto x : nums | views::drop(2)) {
      auto& t = *i > *j ? ++i : --j;
      *t = x;
    }
    reverse(j, r.end());
    return r;
  }
};
// @leet end