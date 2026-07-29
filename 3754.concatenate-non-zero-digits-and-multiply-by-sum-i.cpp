// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  long long sumAndMultiply(int n)
  {
    int x{}, s{};
    for (int p = 1; n > 0; n /= 10) {
      int d = n % 10;
      if (d == 0)
        continue;
      x += p * d;
      s += d;
      p *= 10;
    }
    return 1LL * x * s;
  }
};
// @leet end