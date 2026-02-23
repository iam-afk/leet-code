// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  int binaryGap(int n)
  {
    while (n > 0 && (n & 1) == 0)
      n >>= 1;
    n >>= 1;

    int ans = 0, x = 0;
    while (n > 0) {
      x++;
      if (n & 1)
        ans = max(ans, x), x = 0;
      n >>= 1;
    }
    return ans;
  }
};
// @leet end