// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  vector<int> sortByBits(vector<int>& arr)
  {
    ranges::sort(arr, {}, [](unsigned n) -> pair<int, int> {
      return { popcount(n), n };
    });
    return arr;
  }
};
// @leet end