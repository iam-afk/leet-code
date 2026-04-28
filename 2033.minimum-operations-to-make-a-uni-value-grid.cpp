// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  int minOperations(vector<vector<int>>& grid, int x)
  {
    auto numbers = grid | views::join | ranges::to<vector>();
    ranges::sort(numbers);
    int ans{}, m{ numbers[numbers.size() / 2] };
    for (auto a : numbers) {
      if (abs(a - m) % x != 0)
        return -1;
      ans += abs(a - m) / x;
    }
    return ans;
  }
};
// @leet end