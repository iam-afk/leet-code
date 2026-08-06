// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
  {
    ranges::sort(nums1);
    ranges::sort(nums2);
    vector<int> ans;
    auto it1{ nums1.begin() };
    auto it2{ nums2.begin() };
    while (it1 != nums1.end() && it2 != nums2.end()) {
      auto r = *it1 <=> *it2;
      if (r == strong_ordering::equal)
        ans.push_back(*it1);
      if (r != strong_ordering::greater)
        ++it1;
      if (r != strong_ordering::less)
        ++it2;
    }
    return ans;
  }
};
// @leet end