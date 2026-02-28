// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  int concatenatedBinary(int n)
  {
    constexpr uint64_t M = 1e9 + 7;
    uint64_t ans{};
    for (unsigned i = 1; i <= n; i++)
      ans = ((ans << bit_width(i)) + i) % M;
    return ans;
  }
};
// @leet end