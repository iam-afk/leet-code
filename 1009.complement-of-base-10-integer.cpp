// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  int bitwiseComplement(int n)
  {
    if (n == 0)
      return 1;
    int ans = 0;
    for (int p = 1; n > 0; p <<= 1, n >>= 1)
      if ((n & 1) == 0)
        ans += p;
    return ans;
  }
};
// @leet end