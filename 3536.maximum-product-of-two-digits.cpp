// @leet imports start
using namespace std;
// @leet imports end

// @leet start
class Solution
{
public:
  int maxProduct(int n)
  {
    int mx1 = n % 10;
    n /= 10;
    int mx2 = n % 10;
    n /= 10;
    if (mx2 > mx1)
      swap(mx1, mx2);
    for (; n > 0; n /= 10) {
      int x = n % 10;
      if (x > mx1)
        mx2 = exchange(mx1, x);
      else if (x > mx2)
        mx2 = x;
    }
    return mx1 * mx2;
  }
};
// @leet end